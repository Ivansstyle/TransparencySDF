#version 410 core

uniform float u_GlobalTime;
uniform vec2 u_Resolution;
uniform vec3 u_Camera;
uniform vec3 u_CameraUp;
in vec2 o_FragCoord;
out vec4 o_FragColor;

struct Light {
  vec3 pos;
  vec3 diffuse;
  vec3 ambient;
  vec3 specular;
  float intensity;
};

const float traceprecision = 0.01f;
const Light SunLight = Light(vec3(2.0f, 2.5f, 2.0f), vec3(1.0, 0.8, 0.55), vec3(1.00, 0.90, 0.70), vec3(0.40,0.60,1.00), 1.0);
const Light fillLightA = Light(vec3(-2.0f, 5.5f, -1.0f), vec3(0.78, 0.88, 1.0), vec3(1.00, 0.90, 0.70), vec3(0.40,0.60,1.00), 0.5);
const Light fillLightB = Light(vec3(-1.0f, 5.5f, 2.0f), vec3(1.0, 0.88, 0.78), vec3(1.00, 0.90, 0.70), vec3(0.40,0.60,1.00), 0.5);
const Light fillLightC = Light(vec3(0.0f, -5.5f, 0.0f), vec3(1.0, 0.88, 0.78), vec3(1.00, 0.90, 0.70), vec3(0.40,0.60,1.00), 1.0);
const Light Lights[4] = Light[4](SunLight, fillLightA, fillLightB, fillLightC);

struct TraceResult
{
  vec3 color; // Color
  float o; // Transparency at the point
  float t; //Step
  float bt; //Backwards step
  float d; // Depth
  float bd; // Depth backwards
  // Parameters of the ray 
}; /// 8 floats passed -> good performance


#define TRANSPARENCY_SAMPLES 128.0f

/*
 * Signed distance field functions
 * These function were originally written by Inigo Quilez
 * Modified by Teemu Lindborg where needed.
 * [Accessed Decemeber 2016] Available from: http://iquilezles.org/www/articles/distfunctions/distfunctions.htm
 */
// --------------------- OLD IMPLEMENTATION START -----------------------------
// Sphere
vec4 sdSphere(vec3 p, float s, vec3 color)
{
  mat2x3 res;
  res[0].x = length(p)-s;
  res[1] = color;

  return vec4(length(p)-s, color);
}


// Box signed exactr
vec4 sdBox(vec3 p, vec3 b, vec3 color)
{
  vec3 d = abs(p) - b;
  return vec4(min(max(d.x,max(d.y,d.z)),0.0) + length(max(d,0.0)), color);
}


// Box fast
vec4 sdFastBox(vec3 _position, float _w, vec3 color)
{
  vec3 pos = abs(_position);
  float dx = pos.x - _w;
  float dy = pos.y - _w;
  float dz = pos.z - _w;
  float m = max(dx, max(dy, dz));
  return vec4(m, color);
}

// Torus - signed - exact
vec4 sdTorus(vec3 p, vec2 t, vec3 color)
{
  vec2 q = vec2(length(p.xz)-t.x,p.y);
  return vec4(length(q)-t.y, color);
}

// Cylinder - signed - exact
vec4 sdCylinder(vec3 p, vec3 c, vec3 color)
{
  return vec4(length(p.xz-c.xy)-c.z, color);
}

//Cone - signed - exact
vec4 sdCone(vec3 p, vec2 c, vec3 color)
{
  // c must be normalized
  float q = length(p.xy);
  return vec4(dot(c,vec2(q,p.z)), color);
}

// Plane - signed - exact
vec4 sdPlane(vec3 p, vec4 n, vec3 color)
{
  // n must be normalized
  return vec4(dot(p,n.xyz) + n.w, color);
}

// Hexagonal Prism - signed - exact
vec4 sdHexPrism(vec3 p, vec2 h, vec3 color)
{
  vec3 q = abs(p);
  return vec4(max(q.z-h.y,max((q.x*0.866025+q.y*0.5),q.y)-h.x), color);
}

// Triangular Prism - signed - exact
vec4 sdTriPrism(vec3 p, vec2 h, vec3 color)
{
  vec3 q = abs(p);
  return vec4(max(q.z-h.y,max(q.x*0.866025+p.y*0.5,-p.y)-h.x*0.5), color);
}

// Capsule / Line - signed - exact
vec4 sdCapsule(vec3 p, vec3 a, vec3 b, float r, vec3 color)
{
  vec3 pa = p - a, ba = b - a;
  float h = clamp( dot(pa,ba)/dot(ba,ba), 0.0, 1.0 );
  return vec4(length( pa - ba*h ) - r, color);
}

// Capped cylinder - signed - exact
vec4 sdCappedCylinder(vec3 p, vec2 h, vec3 color)
{
  vec2 d = abs(vec2(length(p.xz),p.y)) - h;
  return vec4(min(max(d.x,d.y),0.0) + length(max(d,0.0)), color);
}

// Capped Cone - signed - bound
vec4 sdCappedCone(vec3 p, vec3 c, vec3 color)
{
  vec2 q = vec2( length(p.xz), p.y );
  vec2 v = vec2( c.z*c.y/c.x, -c.z );
  vec2 w = v - q;
  vec2 vv = vec2( dot(v,v), v.x*v.x );
  vec2 qv = vec2( dot(v,w), v.x*w.x );
  vec2 d = max(qv,0.0)*qv/vv;
  return vec4(sqrt( dot(w,w) - max(d.x,d.y) ) * sign(max(q.y*v.x-q.x*v.y,w.y)), color);
}

// Ellipsoid - signed - bound
vec4 sdEllipsoid(vec3 p, vec3 r, vec3 color)
{
  return vec4((length( p/r ) - 1.0) * min(min(r.x,r.y),r.z), color);
}

/*
 * Unsigned distance fields
 */
// Box unsigned exact
vec4 udBox(vec3 p, vec3 b, vec3 color)
{
  return vec4(length(max(abs(p)-b,0.0)), color);
}

// Round Box unsigned exact

vec4 udRoundBox(vec3 p, vec3 b, float r, vec3 color)
{
  return vec4(length(max(abs(p)-b,0.0))-r, color);
}

float g(float a, float b)
{
  return a + b + sqrt(a*a + b*b);
}

float w1(float a, float b, float t)
{
  return g(b, t-1) / (g(a, -t) + g(b, t-1));
}

float w2(float a, float b, float t)
{
  return g(a, -t) / (g(a, -t) + g(b, t-1));
}

vec3 lerp(vec4 a, vec4 b, float t)
{
//  return t*a.yzw + (1-t)*b.yzw;
  return w1(a.x, b.x, t)*a.yzw + w2(a.x, b.x, t)*b.yzw;
}

vec4 opBlend(vec4 a, vec4 b, float k)
{
  float h = clamp(0.5+0.5*(b.x-a.x)/k, 0.0, 1.0);
  float d = mix(b.x, a.x, h) - k*h*(1.0-h);
  return vec4(d, lerp(a, b, h));
}

vec4 opUnion(vec4 a, vec4 b)
{
  return a.x <= b.x ? a : b;
}

vec4 opIntersection(vec4 a, vec4 b)
{
  return a.x >= b.x ? a : b;
}

vec4 opSubtraction(vec4 a, vec4 b)
{
  return -a.x >= b.x ? vec4(-a.x, a.yzw) : b;
}

vec3 opRepetition(vec3 p, vec3 c)
{
  vec3 q = mod(p,c)-0.5*c;
  return q;
}

// --------------------- OLD IMPLEMENTATION END -----------------------------

/**
  * Modified by Ivans Saponenko (2017-2019)
  * return type changed to support more data including transparency and one reserved still not used float
  * structure of return (mat2x3) is:
  * { |distance,    | red,  |
  *   |transparency,| green,|
  *   |reserved,    | blue  |}; 
  * Also input color now supports transparency so changed to vec4 (RGBA)
  * Now using prefix T to not confuse with any other functions
  */
// ---------------------------------- TRANSPARENCY MOD BEGIN --------------------------------


/*
*   Mat2x3 functions returns:
*   
*   add final ray lenght 
*
*
*
*/

// Sphere // EDITED
mat2x3 TsdSphere(vec3 p, float s, vec4 color) // color as vec4
{
  mat2x3 res;
  res[0].x = length(p)-s;
  res[0].y = color.w;
  res[1] = color.xyz;
  return res; // returning as {[distance, transparency, reserved][vec3(color)]};
}


// Box signed exact // EDITED
mat2x3 TsdBox(vec3 p, vec3 b, vec4 color) // color as vec4
{
    mat2x3 res;
  vec3 d = abs(p) - b;

  res[0].x = min(max(d.x,max(d.y,d.z)),0.0) + length(max(d,0.0));
  res[0].y = color.w;
  res[1] = color.xyz;
  return res; // returning as {[distance, transparency, reserved][vec3(color)]};
}

// Box fast // EDITES
mat2x3 TsdFastBox(vec3 _position, float _w, vec4 color)
{
  mat2x3 res;
  res[1] = color.xyz;
  res[0].y = color.w;

  vec3 pos = abs(_position);
  float dx = pos.x - _w;
  float dy = pos.y - _w;
  float dz = pos.z - _w;
  res[0].x = max(dx, max(dy, dz));

  return res;
}

// Torus - signed - exact
mat2x3 TsdTorus(vec3 p, vec2 t, vec4 color)
{
  mat2x3 res;
  res[1] = color.xyz;
  res[0].y = color.w;

  vec2 q = vec2(length(p.xz)-t.x,p.y);

  res[0].x = length(q)-t.y;
  return res;
}

// Cylinder - signed - exact
mat2x3 TsdCylinder(vec3 p, vec3 c, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
    res[0].x = length(p.xz-c.xy)-c.z;
    return res;
}


//Cone - signed - exact
mat2x3 TsdCone(vec3 p, vec2 c, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
  // c must be normalized
  float q = length(p.xy);
  res[0].x = dot(c,vec2(q,p.z));
  return res;
}

// Plane - signed - exact
mat2x3 TsdPlane(vec3 p, vec4 n, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
  // n must be normalized
  res[0].x = dot(p,n.xyz) + n.w;
  return res;
}

// Hexagonal Prism - signed - exact
mat2x3 TsdHexPrism(vec3 p, vec2 h, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
  vec3 q = abs(p);
  res[0].x = max(q.z-h.y,max((q.x*0.866025+q.y*0.5),q.y)-h.x);
  return res;
}

// Triangular Prism - signed - exact
mat2x3 TsdTriPrism(vec3 p, vec2 h, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
  vec3 q = abs(p);
  res[0].x = max(q.z-h.y,max(q.x*0.866025+p.y*0.5,-p.y)-h.x*0.5);
  return res;
}

// Capsule / Line - signed - exact
mat2x3 TsdCapsule(vec3 p, vec3 a, vec3 b, float r, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
  vec3 pa = p - a, ba = b - a;
  float h = clamp( dot(pa,ba)/dot(ba,ba), 0.0, 1.0 );
  res[0].x = length( pa -ba*h ) - r;
  return res;
}

// Capped cylinder - signed - exact
mat2x3 TsdCappedCylinder(vec3 p, vec2 h, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
  vec2 d = abs(vec2(length(p.xz),p.y)) - h;
  res[0].x = min(max(d.x,d.y),0.0) + length(max(d,0.0));
  return res;
}

// Capped Cone - signed - bound
mat2x3 TsdCappedCone(vec3 p, vec3 c, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
  vec2 q = vec2( length(p.xz), p.y );
  vec2 v = vec2( c.z*c.y/c.x, -c.z );
  vec2 w = v - q;
  vec2 vv = vec2( dot(v,v), v.x*v.x );
  vec2 qv = vec2( dot(v,w), v.x*w.x );
  vec2 d = max(qv,0.0)*qv/vv;
  res[0].x = sqrt( dot(w,w) - max(d.x,d.y) ) * sign(max(q.y*v.x-q.x*v.y,w.y));
  return res;
}

// Ellipsoid - signed - bound
mat2x3 TsdEllipsoid(vec3 p, vec3 r, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
  res[0].x = (length( p/r ) - 1.0) * min(min(r.x,r.y),r.z);
  return res;
}

/*
 * Unsigned distance fields
 */
// Box unsigned exact
mat2x3 TudBox(vec3 p, vec3 b, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
    res[0].x = length(max(abs(p)-b,0.0));
    return res;
}

// Round Box unsigned exact

mat2x3 TudRoundBox(vec3 p, vec3 b, float r, vec4 color)
{
    mat2x3 res;
    res[1] = color.xyz;
    res[0].y = color.w;
    res[0].x = length(max(abs(p)-b,0.0))-r;
    return res;
}
//float g(float a, float b)
//{
//  return a + b + sqrt(a*a + b*b);
//}

//float w1(float a, float b, float t)
//{
//  return g(b, t-1) / (g(a, -t) + g(b, t-1));
//}

//float w2(float a, float b, float t)
//{
//  return g(a, -t) / (g(a, -t) + g(b, t-1));
//}

//vec3 lerp(vec4 a, vec4 b, float t)
//{
////  return t*a.yzw + (1-t)*b.yzw;
//  return w1(a.x, b.x, t)*a.yzw + w2(a.x, b.x, t)*b.yzw;
//}

mat2x3 TopBlend(mat2x3 a, mat2x3 b, float k)
{
    mat2x3 res;
    float h = clamp(0.5+0.5*(b[0].x-a[0].x)/k, 0.0, 1.0);
    float d =  mix(a[0].x, b[0].x, h) - k*h*(1.0-h);
    res[1] = lerp(vec4(a[0].x, a[1].xyz),vec4(b[0].x, b[1].xyz), h); // SHOULD BE VEC4

    ///res[0].y = mix(a[0].y, b[0].y, h); // TRANSPARENCY TODO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    res[0].x = d; // Using mix for now
    return res;
}


mat2x3 TopUnion(mat2x3 a, mat2x3 b) // MIXING
{
  return a[0].x <= b[0].x ? a : b;
}

mat2x3 TopIntersection(mat2x3 a, mat2x3 b) // MIXING
{
  return a[0].x >= b[0].x ? a : b;
}

mat2x3 TopSubtraction(mat2x3 a, mat2x3 b)
{
  if (-a[0].x >= b[0].x) {
      return mat2x3(-a[0].x, a[0].y, a[0].z, a[1].x, a[1].y, a[1].z);
  }
  else return b;

  //return -a[0].x >= b[0].x ? mat2x3(-a[0].x, a[0].y, a[0].z,
  //                                  a[1].x, a[1].y, a[1].z) : b;
}

vec3 TopRepetition(vec3 p, vec3 c) // What to do with this? // Still the quuestion
{
  vec3 q = mod(p,c)-0.5*c;
  return q;
}

// ------------------------------- TRANSPARENCY MOD END ----------------------------------------
// Mapping with transparency
mat2x3 Tmap(vec3 _position) // mat
{
    mat2x3 sphere1, sphere2, pos;

    // //Two boxes
    //pos = TopBlend(TsdBox(_position, vec3(2.0, 5.0, 1.5), vec4(0.3, 0.6, 0.6, 0.4)),
    //                      TsdBox(_position, vec3(1.0, 3.0, 0.5), vec4(0.3, 0.36, 0.1, 0.4))
    //                     ,1.5f); // Weird box
    // //Two spheres
    // pos = TopBlend(TsdSphere(_position, 3.0f, vec4(1.f, 1.f, 1.f, 0.0f)),
    //                    TsdSphere(_position + vec3(1.5f), 1.0, vec4(1.f, 1.f, 1.f, 1.f))
    //                    ,1.6f);
    vec3 _pos1 = _position + vec3(-2,0,0);
    sphere1 = TsdSphere(_pos1, 2.0f, vec4(1.0f,0.0f,0.0f,1.0f));
    _pos1 = _position + vec3(1,0,0);
    sphere2 = TsdSphere(_pos1, 2.0f, vec4(0.0f,0.0f,1.0f,1.0f));

    pos = TopUnion(sphere1, sphere2);
      return pos;
}

// Old map func
vec4 map(vec3 _position)
{
   vec4 pos = vec4(4.0, 3.0, 4.0, 0.0);
   pos = sdBox(_position, vec3(1.0, 1.0, 1.0), vec3(0.6, 0.6, 0.6));
   return pos;
}

// Ray for tracing // No need to edit 
mat2x3 createRay(vec3 _origin, vec3 _lookAt, vec3 _upV, vec2 _uv, float _fov, float _aspect)
{
  mat2x3 ray;
  vec3 direction, rayUpV, rightV;
  vec2 uv;
  float fieldOfViewRad;

  ray[0] = _origin;
  direction = normalize(_lookAt - _origin);
  rayUpV = normalize( _upV - direction * dot(direction, _upV));
  rightV = cross(direction, rayUpV);
  uv = _uv * 2 - vec2(1.);
  fieldOfViewRad = _fov * 3.1415 / 180;

  ray[1] = direction + tan(fieldOfViewRad / 2.f) * rightV * uv.x + tan(fieldOfViewRad / 2.f) / _aspect * rayUpV * uv.y;
  ray[1] = normalize(ray[1]);

  return ray;
}

// Sphere tracing the rays with sphrere tracing algorithm 
TraceResult castRay(mat2x3 _ray)
{
  TraceResult trace;
  trace.t = 1.f;
  float tmax = 20.f;
  for(int i = 0; i < 64; ++i) // 64 - max iterations 
  {
    vec4 r = map(_ray[0] + trace.t * _ray[1]);
    trace.d = r.x;
    trace.color = r.yzw;
    // CalculateOpacity HOW?
    trace.o = 0.5f; // Testing
    if(trace.d <= traceprecision || trace.t > tmax) {
      break;
    }
    trace.t += trace.d;
  }
  return trace;
}

vec3 calcNormal(vec3 _position)
{
  vec3 offset = vec3(0.0005, -0.0005, 1.0);
  vec3 normal = normalize(offset.
                          xyy*map( _position + offset.xyy ).x +
                          offset.yyx*map( _position + offset.yyx ).x +
                          offset.yxy*map( _position + offset.yxy ).x +
                          offset.xxx*map( _position + offset.xxx ).x);
  return normalize(normal);
}

/**
 * Ambient occlusion is based on a shadertoy example by Inigo Quilez
 * [Accessed January 2017] Available from: https://www.shadertoy.com/view/Xds3zN
 */
float calcAO(vec3 _position, vec3 _normal)
{
  float occ = 0.0;
  float sca = 1.0;
  for(int i = 0; i < 5; i++)
  {
    float hr = 0.01 + 0.12*float(i)/4.0;
    vec3 aopos = _normal * hr + _position;
    float dd = map(aopos).x; // Map is here! (AO map)
    occ += -(dd-hr)*sca;
    sca *= 0.95;
  }
  return clamp(1.0 - 3.0*occ, 0.0, 1.0);
}

/**
 * The sky rendering is based on a shadertoy example by Inigo Quilez
 * [Accessed January 2017] Available from: https://www.shadertoy.com/view/4ttSWf
 */
vec3 renderSky(mat2x3 _ray)
{
  // background sky
  vec3 col = 0.9*vec3(0.4, 0.65, 1.0) - _ray[1].y*vec3(0.4, 0.36, 0.4);

  // sun glare
  float sun = clamp(dot(normalize(SunLight.pos), _ray[1]), 0.0, 1.0);
  col += 0.6*vec3(1.0, 0.6, 0.3)*pow(sun, 32.0);

  return col;
}


// No map needed
vec3 applyFog(vec3 color, float distance)
{
  float fogAmount = 1.0 - exp(-distance*2);
  vec3 fogColor = vec3(0.4, 0.65, 1.0);
  return mix(color, fogColor, fogAmount);
}


float softshadow(vec3 ro, vec3 rd, float mint, float tmax)
{
  float res = 1.0;
  float t = mint;
  for(int i = 0; i < 16; ++i)
  {
    float h = Tmap(ro + normalize(rd)*t)[0].x; // Map is here!
    res = min(res, 8.0*h/t);
    t += clamp(h, 0.02, 0.10);
    if(h < traceprecision || t > tmax)
      break;
  }
  return clamp(res, 0.0, 1.0);
}

// Rendering function
vec3 render(mat2x3 _ray)
{
  TraceResult trace = castRay(_ray); // 1st RayCast
  vec3 col = renderSky(_ray); 

  if(trace.d <= traceprecision)
  {
    vec3 p = _ray[0] + trace.t * _ray[1]; // !!! SURFACE !!!
    vec3 n = calcNormal(p);
    vec3 reflection = reflect(_ray[1], n);
    float intensitySum = 0.f;
    col = vec3(0.0);

    for(int i = 0; i < 4; ++i) {

      vec3 lightDir = normalize(Lights[i].pos - p);

      float diffuse = clamp(dot(n, lightDir), 0.0, 1.0) * softshadow(p, Lights[i].pos, 0.02, 2.5);
      float ambient = clamp(0.5 + 0.5*n.y, 0.0, 1.0);
      float occlusion = calcAO(p, n);
      float specular = pow(clamp(dot(reflection, lightDir), 0.0, 1.0 ), 16.0);

      vec3 acc = vec3(0.0);
      acc += 1.40 * diffuse * Lights[i].diffuse;
      acc += 1.20 * ambient * Lights[i].ambient * occlusion;
      if(i == 0)
        acc += 2.00 * specular * Lights[i].specular * diffuse;

      col += trace.color * acc * Lights[i].intensity;
      intensitySum += Lights[i].intensity;
    }
    col /= intensitySum;
    col = applyFog(col, trace.t/150.f);

    // Vigneting
    vec2 q = o_FragCoord.xy / u_Resolution.xy;
    col *= 0.5 + 0.5*pow( 16.0*q.x*q.y*(1.0-q.x)*(1.0-q.y), 0.25 );
  }
  return vec3( clamp(col, 0.0, 1.0) );
}

// --------------------- TRANSPARENCY RENDERING ----------------------------------
  
// if (abs(trace.t -trace.bt) < 1e-3) 
// {
//   trace.color = vec3(1.0f, 0.0f,0.0f);
// }
// else{
//   float c = abs(trace.bt-trace.t)/30.0f;
//   //c = 1.0f-clamp(c, 0.0f, 1.0f);
//   trace.color = vec3(c);
// }

// Volume Marching ans sampling
vec4 marchVolume(mat2x3 _ray, TraceResult _tr) // Returns opacity of the pixel
{
    int samples = 512; // Amount of transparency samples
    float tmax = 20.f; // MAX RAY DISTANCE

    // Setting a ray for the forward volume marching
    mat2x3 f_ray = _ray;
    vec3 f_hitpoint = _ray[0] + _tr.d * _ray[1]; 

   
    // Revesed ray
    vec3 bEye = _ray[0] +  _ray[1] * tmax; 
    vec3 bDir = normalize(-_ray[1]); 
    mat2x3 b_ray = mat2x3(bEye, bDir); // Eye moved to the tmax                                       
    vec3 b_hitpoint = b_ray[0] + _tr.bd * b_ray[1]; 

    vec3 col = vec3(0.0f); // 
    float s_transparency = 0.0f;

    // The size of ray permetrating the object 
    float marchsize = _tr.bd - _tr.d;  


    // How big are the samples
    float samplestep = marchsize / (float)samples;  

    vec3 sum=vec3(0.0f);
    float avg_transparency=0.0f; 
    
    int miss = 0; // Normalize
    
    for(int i = 0; i < samples; ++i) // Volume march
    { 
      // There is a problem with the ray direction 
      vec3 startpoint = f_ray[0] + _tr.d * f_ray[1]; 
      vec3 samplepoint = startpoint + f_ray[1] * i; 
      
      // Color sample
      vec3 s_col=vec3(0.0f);

      // Transparency sample
      float s_transparency = 0.0f; 

      // Sample 
      mat2x3 s = Tmap(samplepoint);
      
      if(s[0].x>0.0f){
        // Inside 
        
        s_col = vec3(0.0f);
        s_transparency=0.0f;
        

      }else{ // Outside
        
        s_col = s[1]; 
        s_transparency = s[0].y; 
        +miss;
      }
      

      sum+=s_col * s_transparency;
      avg_transparency += s_transparency; 
    }
    
    // Calculate pixel color | something is really wrong 
    vec3 color = normalize(sum/vec3(avg_transparency)); 
    float transparency = avg_transparency/(float)samples; 

    // Polishing up and packing
    vec4 result; 
    
    //Calculating final pixel value 
    result = vec4(color, transparency);

    //Testing Misses alone
    //float contrast = 1.8f; 
    //result = vec4(color, clamp(((float)miss/(float)samples)*contrast,0.0f,1.0f)); // Use trace.o in rendering
    
    //Testing color alone 
    //result = vec4(color, 1.0f);

    //Testing transparency alone 
      return result;
}


TraceResult TcastRay(mat2x3 _ray)
{
  TraceResult trace; // Forward Tracing
  trace.t =   1.f;
  trace.bt =  1.f;
  float tmax = 20.f;
  int numSamples = 64; 

  // Forward raycasting <--------------0
  for(int i = 0; i < numSamples; ++i)
  {
    mat2x3 r = Tmap(_ray[0] + trace.t * _ray[1]);
    trace.d = r[0].x;
    //trace.color = r[1].rgb;

    // CalculateOpacity
    if(trace.d <= traceprecision) {
     break; // Hit
    }
    else if(trace.t > tmax) break;
   trace.t += trace.d; // Add
  }

  // Backwards Raycasting 0------------> 
  
  // Revesed ray
  vec3 bEye = _ray[0] +  _ray[1] * tmax; 
  vec3 bDir = normalize(-_ray[1]); 
  mat2x3 bray = mat2x3(bEye, bDir); // Eye moved to the tmax
                                       
  // Tracing backwards
  for(int i = 0; i < numSamples; ++i) // We use 64 samples at this point 
  {
    mat2x3 r = Tmap(bray[0] + trace.bt * bray[1]); // create a ray from backwards ray to 
    trace.bd = r[0].x;
    //trace.color = r[1].rgb;

    if(trace.bd <= traceprecision) {
      break;
    }
    else if(trace.t > tmax) break;
   trace.bt += trace.bd; // Backtrace marker make a step 
  }

// For trace check purposes 
if (abs(trace.t -trace.bt) < 1e-3) 
{
  trace.color = vec3(1.0f, 0.0f,0.0f);
}
else{
  float c = abs(trace.bt-trace.t)/30.0f;
  c = 1.0f-clamp(c, 0.0f, 1.0f);
  trace.color = vec3(c);
}

 // Sampling inside the object
  vec4 data = marchVolume(_ray, trace);
  trace.color = data.xyz;
  trace.o = data.w;

  return trace; // Opacity returns here
}


vec3 TcalcNormal(vec3 _position) // Why you so strange normal
{
  vec3 offset = vec3(0.0005, -0.0005, 1.0);
  vec3 normal = normalize(offset.xyy*Tmap( _position + offset.xyy )[0].x +
                          offset.yyx*Tmap( _position + offset.yyx )[0].x +
                          offset.yxy*Tmap( _position + offset.yxy )[0].x +
                          offset.xxx*Tmap( _position + offset.xxx )[0].x);
  return normalize(normal);
}

// Rendering function // WIP for transparency
vec3 Trender(mat2x3 _ray)
{
  TraceResult trace = TcastRay(_ray); // 1st RayCast

  vec3 skyCol = renderSky(_ray);
  vec3 col = skyCol;

  //trace.o = 1.f; // FOR TESTING

  if(trace.d <= traceprecision) // We are on the object
  {
    vec3 p = _ray[0] + trace.t * _ray[1]; // !!! SURFACE !!!
    vec3 n = TcalcNormal(p);
    vec3 reflection = reflect(_ray[1], n);
    float intensitySum = 0.f;
    
    // Color with transparency
    col = trace.color; 
    //col = col * trace.o + skyCol * (1.f - trace.o);

    for(int i = 0; i < 4; ++i) {

      vec3 lightDir = normalize(Lights[i].pos - p);

      float diffuse = clamp(dot(n, lightDir), 0.0, 1.0) * softshadow(p, Lights[i].pos, 0.02, 2.5);
      float ambient = clamp(0.5 + 0.5*n.y, 0.0, 1.0);
      float occlusion = calcAO(p, n) * trace.o;

      float specular = pow(clamp(dot(reflection, lightDir), 0.0, 1.0 ), 16.0);

      vec3 acc = vec3(0.0);
      acc += 1.40 * diffuse * Lights[i].diffuse;
      acc += 1.20 * ambient * Lights[i].ambient * occlusion;
      if(i == 0)
        acc += 2.00 * specular * Lights[i].specular * diffuse;


      col += trace.color * acc * Lights[i].intensity; // Apply lights

     
      //col += 0.01f * acc * Lights[i].intensity;
      intensitySum += Lights[i].intensity;
    }
    col /= intensitySum;
    // opacity ???
    //col = applyFog(col, trace.t/150.f);

    // Vigneting
    vec2 q = o_FragCoord.xy / u_Resolution.xy;
    col *= 0.5 + 0.5*pow( 16.0*q.x*q.y*(1.0-q.x)*(1.0-q.y), 0.25 );


    //col = trace.color;
    col = clamp(col*trace.o + skyCol * (1.f - trace.o),0.0,1.0);// Testing !
    
    // Testing opacity only 
    col = vec3(clamp(trace.o,0.0,1.0));
  }

  return vec3( clamp(col, 0.0, 1.0) );
}

// --------------------- TRANSPARENCY RENDERING END ----------------------------------

void main()
{
  vec3 cameraPosition = u_Camera;
  vec3 upVector = u_CameraUp;
  vec3 lookAt = vec3(0.f);
  float aspectRatio = u_Resolution.x / u_Resolution.y;

  mat2x3 ray = createRay(cameraPosition, lookAt, upVector, o_FragCoord, 90.f, aspectRatio);
  vec3 color = Trender(ray);

  // Gamma correction NOT
  o_FragColor = vec4(pow(color, vec3(0.4545)), 1.f);
  //o_FragColor = vec4(color, 1.f);
}


/* ---------------------------- TRASHBIN -----------------------------------


//TraceResult castRay(mat2x3 _ray)
//{
//TraceResult trace;
//trace.t = 1.f;
//float tmax = 20.f;
//for(int i = 0; i < 64; ++i)
//{
//  vec4 r = map(_ray[0] + trace.t * _ray[1]);
//  trace.d = r.x;
//  trace.color = r.yzw;
//  if(trace.d <= traceprecision || trace.t > tmax) {
//    break;
//  }
//  trace.t += trace.d;
//}


    // // Adaptive step // Using tmax preprogrammed
    // float step = (20.0f - (_tr.bd - _tr.d)) / TRANSPARENCY_SAMPLES;
    // //float step = 0.1f;
    // int hits = 0;
    // float lastT = 1.1f;
0
    // // Sampling transparency (wro0ng now)
    // for (int i = 0; i < TRANSPARE0NCY_SAMPLES; ++i)
    // {0
    //     mat2x3 r = Tmap(tray[0] +0 float(i) * step * tray[1]);
0
    //     if (r[0].x < 0)0
    //     {0
    //         col += r[1].xyz * r[00].y;
    //         transparency += 0.10f0;//r[0].y;
    //         transparency = min(r[0].y, lastT);
    //         lastT = r[0].y;
    //         ++hits;
    //     }
    //     if (transparency / float(i) >= 1.0f) {break;} // We are in non transparent object

//  // Break if we outside object
//     }
//     col /= float(hits);
//     transparency /= float(hits);
//     col = vec3(transparency);

//     //col = vec3(transparency);


*/
#pragma once

#include "PortType.hpp"

#include <QtCore/QPointF>
#include <QtCore/QRectF>

#include <iostream>

/// @brief Node Editor
/// Dimitry Pinaev.
/// [Accessed November 2016]. Available from: https://github.com/paceholder/nodeeditor

class ConnectionGeometry
{
public:

  ConnectionGeometry();

public:

  QPointF const& getEndPoint(PortType portType) const;

  void setEndPoint(PortType portType, QPointF const& point);

  void moveEndPoint(PortType portType, QPointF const &offset);

  QRectF boundingRect() const;

  std::pair<QPointF, QPointF>
  pointsC1C2() const;

  QPointF source() const { return _out; }
  QPointF sink() const { return _in; }

  double pointDiameter() const { return _pointDiameter; }

  double lineWidth() const { return _lineWidth; }

  bool hovered() const { return _hovered; }
  void setHovered(bool hovered) { _hovered = hovered; }

private:
  // local object coordinates
  QPointF _in;
  QPointF _out;

  double _pointDiameter;

  //int _animationPhase;

  double _lineWidth;

  bool _hovered;
};
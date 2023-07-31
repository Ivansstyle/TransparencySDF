cmake_minimum_required(VERSION 3.5)

# General
project(hsitho)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_BUILD_TYPE "Debug")

# QT Specific
find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)

# Project specific files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/nodes/*.cpp" "nodeEditor/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/nodes/*.hpp" "nodeEditor/*.hpp")
file(GLOB_RECURSE FORMS "ui/mainwindow.ui")

# Include directories
include_directories(
        ./include
        ./include/nodes
        ./nodeEditor
        /usr/local/include
        /opt/homebrew/include
)

# Add definition
add_definitions(-DNODE_EDITOR_SHARED)

# Compiler warnings
add_compile_options(-Wno-unused-parameter -Wno-unused-function)

# Executable
add_executable(hsitho ${SOURCES} ${HEADERS} ${FORMS})

# Specify here the libraries this program depends on
target_link_libraries(hsitho
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::OpenGL
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS} ${FORMS})
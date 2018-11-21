cmake_minimum_required(VERSION 3.2)

include("CMake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.34.tar.gz"
    SHA1 "70287b1ffa810ee4e952052a9adff9b4856d0d54"
)

project(Qwt VERSION 6.1.3)

option(LIBQWT_ENABLE_PLOT "Build plot support" ON)
option(LIBQWT_ENABLE_WIDGETS "Build widgets support" ON)
option(LIBQWT_ENABLE_MATHML "Build MathML support" OFF)
option(LIBQWT_ENABLE_OPENGL "Build OpenGL support" ON)
option(LIBQWT_ENABLE_SVG "Build SVG support" ON)

hunter_add_package(Qt)

find_package(Qt5Core REQUIRED)
list(APPEND components Qt5::Core)

if(LIBQWT_ENABLE_WIDGETS)
	find_package(Qt5Widgets REQUIRED)
	list(APPEND QT_LIBS Qt5::Widgets)
endif()

if(LIBQWT_ENABLE_SVG)
hunter_add_package(Qt COMPONENTS qtsvg)
	find_package(Qt5Svg QUIET)
	list(APPEND QT_LIBS Qt5::Svg)
endif()
find_package(Qt5PrintSupport REQUIRED)
list(APPEND QT_LIBS Qt5::PrintSupport)
find_package(Qt5Concurrent REQUIRED)
list(APPEND QT_LIBS Qt5::Concurrent)

if(LIBQWT_ENABLE_OPENGL)
	find_package(Qt5OpenGL REQUIRED)
	list(APPEND QT_LIBS Qt5::OpenGL)
endif()

if(LIBQWT_ENABLE_MATHML)
	find_package(Qt5Xml REQUIRED)
	list(APPEND QT_LIBS Qt5::Xml)
endif()

if(NOT LIBQWT_ENABLE_PLOT)
	add_definitions(-DNO_QWT_PLOT)
endif()
if(NOT LIBQWT_ENABLE_WIDGETS)
	add_definitions(-DNO_QWT_WIDGETS)
endif()
if(NOT LIBQWT_ENABLE_SVG)
	add_definitions(-DQWT_NO_SVG)
endif()
if(NOT LIBQWT_ENABLE_OPENGL)
	add_definitions(-DQWT_NO_OPENGL)
endif()
if(WIN32)
	add_definitions(-DQT_DLL -DQWT_DLL -DQWT_MAKEDLL)
endif()
#include_directories(src)
add_subdirectory(src)
add_subdirectory(textengines)

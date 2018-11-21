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
add_subdirectory(textengines)
list(APPEND SOURCES 
 	src/qwt_abstract_scale_draw.cpp
    src/qwt_clipper.cpp
    src/qwt_color_map.cpp
    src/qwt_column_symbol.cpp
    src/qwt_date.cpp
    src/qwt_date_scale_draw.cpp
    src/qwt_date_scale_engine.cpp
    src/qwt_dyngrid_layout.cpp
    src/qwt_event_pattern.cpp
    src/qwt_graphic.cpp
    src/qwt_interval.cpp
    src/qwt_interval_symbol.cpp
    src/qwt_math.cpp
    src/qwt_magnifier.cpp
    src/qwt_null_paintdevice.cpp
    src/qwt_painter.cpp
    src/qwt_painter_command.cpp
    src/qwt_panner.cpp
    src/qwt_picker.cpp
    src/qwt_picker_machine.cpp
    src/qwt_pixel_matrix.cpp
    src/qwt_point_3d.cpp
    src/qwt_point_polar.cpp
    src/qwt_round_scale_draw.cpp
    src/qwt_scale_div.cpp
    src/qwt_scale_draw.cpp
    src/qwt_scale_map.cpp
    src/qwt_spline.cpp
    src/qwt_scale_engine.cpp
    src/qwt_symbol.cpp
    src/qwt_system_clock.cpp
    src/qwt_text_engine.cpp
    src/qwt_text_label.cpp
    src/qwt_text.cpp
    src/qwt_transform.cpp
    src/qwt_widget_overlay.cpp
    )

if(LIBQWT_ENABLE_PLOT)
	list(APPEND SOURCES
	src/qwt_curve_fitter.cpp
    src/qwt_abstract_legend.cpp
    src/qwt_legend.cpp
    src/qwt_legend_data.cpp
    src/qwt_legend_label.cpp
    src/qwt_plot.cpp
    src/qwt_plot_renderer.cpp
    src/qwt_plot_xml.cpp
    src/qwt_plot_axis.cpp
    src/qwt_plot_curve.cpp
    src/qwt_plot_dict.cpp
    src/qwt_plot_directpainter.cpp
    src/qwt_plot_grid.cpp
    src/qwt_plot_histogram.cpp
    src/qwt_plot_item.cpp
    src/qwt_plot_abstract_barchart.cpp
    src/qwt_plot_barchart.cpp
    src/qwt_plot_multi_barchart.cpp
    src/qwt_plot_intervalcurve.cpp
    src/qwt_plot_zoneitem.cpp
    src/qwt_plot_tradingcurve.cpp
    src/qwt_plot_spectrogram.cpp
    src/qwt_plot_spectrocurve.cpp
    src/qwt_plot_scaleitem.cpp
    src/qwt_plot_legenditem.cpp
    src/qwt_plot_seriesitem.cpp
    src/qwt_plot_shapeitem.cpp
    src/qwt_plot_marker.cpp
    src/qwt_plot_textlabel.cpp
    src/qwt_plot_layout.cpp
    src/qwt_plot_canvas.cpp
    src/qwt_plot_panner.cpp
    src/qwt_plot_rasteritem.cpp
    src/qwt_plot_picker.cpp
    src/qwt_plot_zoomer.cpp
    src/qwt_plot_magnifier.cpp
    src/qwt_plot_rescaler.cpp
    src/qwt_point_mapper.cpp
    src/qwt_raster_data.cpp
    src/qwt_matrix_raster_data.cpp
    src/qwt_sampling_thread.cpp
    src/qwt_series_data.cpp
    src/qwt_point_data.cpp
    src/qwt_scale_widget.cpp
	    )
endif()

if(LIBQWT_ENABLE_OPENGL)
	list(APPEND SOURCES 
    src/qwt_plot_glcanvas.cpp
	)
endif()

if(LIBQWT_ENABLE_SVG)
    list(APPEND SOURCES 
    src/qwt_plot_svgitem.cpp
    )
endif()


if(LIBQWT_ENABLE_WIDGETS)
    list(APPEND SOURCES 
    src/qwt_abstract_slider.cpp
    src/qwt_abstract_scale.cpp
    src/qwt_arrow_button.cpp
    src/qwt_analog_clock.cpp
    src/qwt_compass.cpp
    src/qwt_compass_rose.cpp
    src/qwt_counter.cpp
    src/qwt_dial.cpp
    src/qwt_dial_needle.cpp
    src/qwt_knob.cpp
    src/qwt_slider.cpp
    src/qwt_thermo.cpp
    src/qwt_wheel.cpp
    )
endif()
set(HEADERS
    src/qwt_abstract_legend.h
    src/qwt_abstract_scale.h
    src/qwt_abstract_slider.h
    src/qwt_analog_clock.h
    src/qwt_compass.h
    src/qwt_counter.h
    src/qwt_dial.h
    src/qwt_dyngrid_layout.h
    src/qwt_knob.h
    src/qwt_legend.h
    src/qwt_legend_label.h
    src/qwt_magnifier.h
    src/qwt_panner.h
    src/qwt_picker.h
    src/qwt_plot.h
    src/qwt_plot_canvas.h
    src/qwt_plot_glcanvas.h
    src/qwt_plot_magnifier.h
    src/qwt_plot_panner.h
    src/qwt_plot_picker.h
    src/qwt_plot_renderer.h
    src/qwt_plot_zoomer.h
    src/qwt_sampling_thread.h
    src/qwt_scale_widget.h
    src/qwt_slider.h
    src/qwt_text_label.h
    src/qwt_thermo.h
    src/qwt_wheel.h
)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(qwt ${SOURCES} ${HEADERS})
include_directories(qwt PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/src>")
target_link_libraries(qwt ${QT_LIBS})
set_property(TARGET qwt PROPERTY SOVERSION ${PROJECT_VERSION})
include(GNUInstallDirs)
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(include_install_dir "include")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)
 
 configure_package_config_file(
    "CMake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

install(TARGETS qwt 
  EXPORT ${targets_export_name}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  #RUNTIME DESTINATION bin
  INCLUDES DESTINATION ${include_install_dir}
)
install(
    FILES ${HEADERS}
    #DIRECTORY "include/"
    DESTINATION "${include_install_dir}"
    #FILES_MATCHING PATTERN "*.h"
)

install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

install(
    EXPORT "${targets_export_name}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)



#include_directories(src)
#add_subdirectory(src)


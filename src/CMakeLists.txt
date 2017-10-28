link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(smith main.cpp SmithChartWindow.cpp SmithWidget.cpp SmithWidget.h)
target_link_libraries(smith ${GTKMM_LIBRARIES})

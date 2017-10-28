cmake_minimum_required(VERSION 3.8)
project(smith)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

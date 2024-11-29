cmake_minimum_required(VERSION 3.20)

project(Cal)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Qt6 REQUIRED COMPONENTS Widgets)


set(UI_FILES mainwindow.ui)

qt6_wrap_ui(UI_HEADERS ui_mainwindow.h)


add_executable(Cal main.cpp mainwindow.cpp mainwindow.ui)

target_link_libraries(Cal PRIVATE Qt6::Widgets)

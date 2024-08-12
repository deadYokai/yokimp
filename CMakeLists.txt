cmake_minimum_required(VERSION 3.28)

add_subdirectory(ftxui)

project(yokimp LANGUAGES CXX)

add_executable(yokimp main.cpp)
target_link_libraries(yokimp PRIVATE ftxui::screen ftxui::dom ftxui::component)




cmake_minimum_required(VERSION 3.0)

add_executable(insertion_sort insertion_sort.cpp)

install(TARGETS insertion_sort
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin)
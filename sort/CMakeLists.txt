cmake_minimum_required(VERSION 3.0)

add_executable(insertion_sort insertion_sort.cpp)
add_executable(merge_sort merge_sort.cpp)
add_executable(bubble_sort bubble_sort.cpp)

list(APPEND BINS
        insertion_sort
        merge_sort
        bubble_sort)

install(TARGETS ${BINS}
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin)
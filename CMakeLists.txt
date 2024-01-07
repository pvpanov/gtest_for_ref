cmake_minimum_required(VERSION 3.26)
project(testing_test)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES main.cpp)
add_executable(solution_run ${SOURCE_FILES})

include_directories(solution_lib)
add_subdirectory(solution_lib)

target_link_libraries(solution_run solution_lib)

add_subdirectory(tests)


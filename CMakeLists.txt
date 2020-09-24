cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(transform-SIMD VERSION 1.0)

# C++ setting
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall -Wextra -pedantic -Werror  -O2 -g)

list(APPEND CMAKE_PREFIX_PATH $ENV{HOME}/.local/)
find_package(benchmark REQUIRED)
find_package (Threads)

add_library(transformslib SHARED
    transforms.cxx
)

add_executable(transforms_test 
	       transforms_test.cxx)

add_executable(transforms_bench 
	       transforms_bench.cxx)

target_link_libraries(transforms_test  transformslib)
target_link_libraries(transforms_bench  transformslib benchmark::benchmark)


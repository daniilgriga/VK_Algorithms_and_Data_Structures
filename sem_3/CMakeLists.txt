cmake_minimum_required (VERSION 3.12)

project (SortingBenchmark LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)


set (COMMON_COMPILE_OPTIONS
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>)

add_executable (test_algs
    src/tester.cpp)
target_include_directories (test_algs PRIVATE include)
target_compile_options (test_algs PRIVATE ${COMMON_COMPILE_OPTIONS})

add_executable (bench_shell
    src/shell_bencmark.cpp)
target_include_directories (bench_shell PRIVATE include)
target_compile_options (bench_shell PRIVATE ${COMMON_COMPILE_OPTIONS})

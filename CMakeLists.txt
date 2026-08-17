cmake_minimum_required(VERSION 3.16)
project(programming_tasks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

foreach(CONFIG Debug Release RelWithDebInfo MinSizeRel)
    string(TOUPPER ${CONFIG} CONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin)
endforeach()

add_executable(task_16_4 task_16_4.cpp)
add_executable(task_14_1 task_14_1.cpp)
add_executable(task_7_7 task_7_7.cpp)

add_executable(test_16_4 tests/test_16_4.cpp)
add_executable(test_14_1 tests/test_14_1.cpp)
add_executable(test_7_7 tests/test_7_7.cpp)

enable_testing()
add_test(NAME task_16_4_tests COMMAND test_16_4)
add_test(NAME task_14_1_tests COMMAND test_14_1)
add_test(NAME task_7_7_tests COMMAND test_7_7)

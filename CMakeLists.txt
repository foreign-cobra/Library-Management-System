cmake_minimum_required(VERSION 3.20)

project(lilbrary-unit-tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runProgram
  src/Book.cpp
  src/helper.cpp
  src/Library.cpp
  src/main.cpp
)

add_executable(runAllTests
  test/test.cpp
  src/Library.cpp
  src/Book.cpp
)

target_link_libraries(runProgram gtest gtest_main)
target_link_libraries(runProgram)
target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests)
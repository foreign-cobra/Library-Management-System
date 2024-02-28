cmake_minimum_required(VERSION 3.20)

project(libary-unit-tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runAllTests
  test.cpp
  src/settleFines.cpp
  src/book.cpp
  src/library.cpp
  src/user.cpp
)

add_executable(runProgram
  src/book.cpp
  src/helper.cpp
  src/library.cpp
  src/main.cpp
  src/user.cpp
  src/settleFines.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests)
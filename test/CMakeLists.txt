cmake_minimum_required(VERSION 3.2)
project(divider_tests)

# add the google test library.
add_subdirectory(lib/googletest)

include_directories(${DIVISION_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/divider_tests.cpp)

add_executable(divider_tests ${SOURCE_FILES})

# add the "division" and "gtest" libraries to the "divider_tests" target
target_link_libraries(divider_tests division gtest)

install(TARGETS divider_tests DESTINATION bin)


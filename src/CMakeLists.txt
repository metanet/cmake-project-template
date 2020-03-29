cmake_minimum_required(VERSION 3.2)
project(divider)

add_subdirectory(division)
set(SOURCE_FILES main.cpp)

add_executable(divider ${SOURCE_FILES})

# link the "division" library to the "divider" target
target_link_libraries(divider division)

# DIVISIBLE_INSTALL_BIN_DIR comes from the top level
# the "divider" target is installed to the install bin dir
install(TARGETS divider DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})

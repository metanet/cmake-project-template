cmake_minimum_required(VERSION 3.2)
project(division C CXX)

set(SOURCE_FILES
        division.h
        division.cpp
        )

# adds a library target: "division"
# STATIC libraries are archives of object files for use when linking other targets.
# SHARED libraries are linked dynamically and loaded at runtime.
add_library(division SHARED STATIC ${SOURCE_FILES})

install(TARGETS division DESTINATION ${DIVISIBLE_INSTALL_LIB_DIR})

install(FILES division.h DESTINATION ${DIVISIBLE_INSTALL_INCLUDE_DIR})

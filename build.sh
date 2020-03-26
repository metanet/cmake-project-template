#!/bin/bash

rm -rf build
cmake -H. -Bbuild
cmake -H. -Bbuild/debug -DCMAKE_BUILD_TYPE=Debug
cmake -H. -Bbuild/release -DCMAKE_BUILD_TYPE=Release

cd build
make clean
make
make install
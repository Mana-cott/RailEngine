#!/bin/bash

# simple build script for Linux
[ -d build ] && rm -r build
mkdir build
cd build
cmake ..
make
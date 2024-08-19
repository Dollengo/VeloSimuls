#!/bin/bash

# Set the compiler
CXX=g++

mkdir -p build

# Compile the source files
$CXX -o build/VeloSimul main.cpp player.cpp

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful! You can run the game using './VeloSimul'."
else
    echo "Build failed. Please check the errors above."
fi

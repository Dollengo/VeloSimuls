@echo off
REM Set the compiler
set CXX=g++

mkdir -p build

REM Compile the source files
%CXX% -o build/VeloSimul.exe src/main.cpp src/player.cpp

REM Check if the build was successful
if %ERRORLEVEL% EQU 0 (
    echo Build successful! You can run the game in 'build' directory using 'VeloSimul.exe'.
) else (
    echo Build failed. Please check the errors above.
)

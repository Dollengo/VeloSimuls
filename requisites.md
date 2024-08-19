# Requisites for VeloSimul

To build and run VeloSimul, you'll need the following:

## Software

1. **C++ Compiler**:
   - Unix-based systems: `g++` or `clang++`
   - Windows: MinGW (`g++`)

2. **Build Tools** (optional):
   - CMake (if you wish to use a more advanced build system)

## Installation

### On Unix-Based Systems

1. Install `g++` (e.g., on Ubuntu: `sudo apt-get install g++`).
2. Optionally, install `cmake` for more advanced build configurations.

### On Windows

1. Install MinGW from the [MinGW website](http://mingw.org/).
2. Ensure that `g++` is available in your system's PATH.

## Building the Project

- **Unix-Based Systems**: Run `./unixbuild.sh`.
- **Windows (MinGW)**: Run `./mingwbuild.sh`.

## Running the Game

After building the project, execute the binary:

- **Unix-Based Systems**: `./VeloSimul`
- **Windows**: `VeloSimul.exe`

Follow the prompts to set the player's velocity and starting position, and use the menu to control the player.

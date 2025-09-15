# game-of-life

## Intro
This c++ project is a simple implementation of Conway's game of life. The project has been compiled, tested and executed on windows and linux. The following instructions on how to build and test the project, are focused for those two platforms.

It is suggested (but not required) that you use visual studio if you are on windows. 

The software itself is located in folder GOL_console. Here you will find the implementation of the game in GOL.hpp. There is also a test folder.

## Steps to get this repo up and running locally:

 - `git clone https://github.com/rrrags/game-of-life`
 - `git submodule update --init --recursive` (for vcpkg submodule)
 - `cd vcpkg && bootstrap-vcpkg.sh` (`bootstrap-vcpkg.bat` on windows)
 - `cmake --list-presets` to check out available cmake presets
 - Choose preset. F.ex: `cmake --preset "conf-MSVC"`
 - Go to build folder and do `cmake --build .` (or open solution file in visual studio on windows, and run the executable from visual studio)

## How to test the project after building
### On windows visual studio
 - Open test explorer and click Run All Tests
 - Or, run the test from the solution explorer
### On linux
 - `cd path/to/your/build/folder && ctest`
 
 
 
 dagbok:
 vscode måtte bygge før QT, ellers fant ikke qtcreator qt libraries? funket å oppdatere cmakepresets ""CMAKE_PREFIX_PATH": "C:\\Qt\\6.8.2\\msvc2022_64\\lib\\cmake", " med space f.eks.?

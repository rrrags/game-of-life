# game-of-life

## Steps to get this repo up and running locally:

 - `git clone https://github.com/rrrags/game-of-life`
 - `git submodule update --init --recursive` (for vcpkg submodule)
 - `cd vcpkg && bootstrap-vcpkg.sh` (`bootstrap-vcpkg.bat` on windows)
 - `cmake --list-presets` to see available cmake presets
 - Choose preset. F.ex: `cmake --preset "conf-MSVC"`
 - Go to build folder and do `cmake --build .`



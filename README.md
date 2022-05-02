### SlotMachine

[![CI - Windows](https://github.com/SergeyG22/SlotMachineOGS/actions/workflows/windows_builds.yml/badge.svg)](https://github.com/SergeyG22/SlotMachineOGS/actions/workflows/windows_builds.yml)<br>
[![CI - linux](https://github.com/SergeyG22/SlotMachineOGS/actions/workflows/linux_builds.yml/badge.svg)](https://github.com/SergeyG22/SlotMachineOGS/actions/workflows/linux_builds.yml)<br>
Not tested under MacOS (no distribution).<br><br>
The application is a model of a slot machine with the ability to rotate and stop the slots. If the player does not press the stop button, the reels will automatically stop after 15 seconds.

### Installing dependencies

Python interpreter and the Conan package manager must be installed.
CMake 3.14 or higher should also be installed.

To install Conan, enter the following command:

```
pip3 install conan 
```

To check that the Conan is installed correctly enter in cmd:

```
conan --version
```

Download the sources and install the required dependencies:
```
git clone https://github.com/SergeyG22/SlotMachineOGS.git
cd SlotMachineOGS
cd cmake
conan install ../scripts
```

To switch between Debug or Release builds:

```
cd cmake
conan install -s build_type=Debug ../scripts 
```
```
cd cmake
conan install -s build_type=Release ../scripts 
```

After these commands, Conan will build a dependency graph and download the necessary packages.

### Building from source
```
cd SlotMachineOGS
mkdir build
cd build
cmake ..
```

For Linux enter (debug or release version):

```
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```
```
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

For Windows enter (debug or release version):

```
cmake --build build --config Debug
```
```
cmake --build build --config Release
```
After that, an executable file will appear in 'build' the directory

**To work successfully, the "resource" folder must be located on the directory above that of the executable file**<br><br>

### Keyboard control:
 [R] - rotate slots <br>
 [Space] - stop slots
### Mouse control:
 [Start] - rotate slots [click left mouse button] <br>
 [Stop] - stop slots [click left mouse button]
### Preview
![alt text](https://github.com/SergeyG22/SlotMachineOGS/blob/main/doc/animations/animation.gif)



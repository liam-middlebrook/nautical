# nautical
A game engine written in C++ using OpenGL 3.3 as a graphics framework

# License

nautical is licensed under the [GNU GPLv3](http://www.gnu.org/copyleft/gpl.html)

# Usage

N/A yet, still in the early architecture stage

# Dependencies

- A compiler that supports C++11
- [CMake](http://www.cmake.org/) >= 3.0.2
- [SWIG](http://www.swig.org/)
- [RapidJSON](https://github.com/miloyip/rapidjson)

# Build instructions

To do a typical out-of-source cmake build:

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

# Install instructions

From an out-of-source build directory:

```sh
cmake --build . --target install
```

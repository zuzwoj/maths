# Maths

A simple C++ library created primarily for usage with OpenGL.

## Features
- 3D and 4D vectors
- 4x4 matrices
- quaternions

## Installation (Windows)
From the `Maths` directory execute the following
```
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
``` 
This will generate `Maths.lib` file under `Maths\build\Release` that can then be used with the .h files from `Maths\include\Maths`.
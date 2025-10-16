# Maths

A simple C++ library created primarily for usage with OpenGL.

## Features
- 2D, 3D and 4D vectors
- 4x4 matrices
- quaternions
- some common mathematical functions

## Build (Windows)
From the `Maths` directory execute the following (with `<mode>` being either `Release` or `Debug`)
```
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config <mode>
``` 
This will generate `Maths.lib` file under `Maths\build\<mode>` that can then be used with the .h files from `Maths\include\Maths`.

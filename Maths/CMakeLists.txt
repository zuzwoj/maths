cmake_minimum_required(VERSION 3.14)
project(Maths VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Maths STATIC
    src/diagonalMatrix.cpp
    src/identityMatrix.cpp
    src/invertedProjectionMatrix.cpp
    src/matrix4x4.cpp
    src/projectionMatrix.cpp
    src/quaternion.cpp
    src/rotationMatrix.cpp
    src/rotationXMatrix.cpp
    src/rotationYMatrix.cpp
    src/rotationZMatrix.cpp
    src/scaleMatrix.cpp
    src/stereoscopicProjectionMatrix.cpp
    src/translationMatrix.cpp
    src/vector2.cpp
    src/vector3.cpp
    src/vector4.cpp "include/Maths/functions.h" "src/functions.cpp")

target_include_directories(Maths
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

set_target_properties(Maths PROPERTIES POSITION_INDEPENDENT_CODE ON)

include(GNUInstallDirs)

install(TARGETS Maths
    EXPORT MathsTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT MathsTargets
    FILE MathsTargets.cmake
    NAMESPACE Maths::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Maths
)

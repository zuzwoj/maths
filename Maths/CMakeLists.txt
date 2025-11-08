cmake_minimum_required(VERSION 3.14)
project(Maths VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Maths STATIC
    "src/matrix4x4/diagonalMatrix.cpp"
    "src/matrix4x4/identityMatrix.cpp"
    "src/matrix4x4/invertedProjectionMatrix.cpp"
    "src/matrix4x4/matrix4x4.cpp"
    "src/matrix4x4/projectionMatrix.cpp"
    src/quaternion.cpp
    "src/matrix4x4/rotationMatrix.cpp"
    
    
    
    "src/matrix4x4/scaleMatrix.cpp"
    "src/matrix4x4/stereoscopicProjectionMatrix.cpp"
    "src/matrix4x4/translationMatrix.cpp"
    "src/vector/vector2.cpp"
    "src/vector/vector3.cpp"
    "src/vector/vector4.cpp" "include/Maths/functions.h" "src/functions.cpp"       "include/Maths/matrix3x3.h" "include/Maths/matrix.h" "src/matrix3x3.cpp")

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

cmake_minimum_required(VERSION 3.14)
project(Maths VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Maths STATIC
    src/Maths.cpp
)

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

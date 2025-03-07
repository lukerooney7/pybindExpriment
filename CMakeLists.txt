cmake_minimum_required(VERSION 3.12)
project(MyPropagator)

include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.10.0  # Adjust the version if necessary
)
FetchContent_MakeAvailable(pybind11)

# Not sure if we need this (or may need to generalise as hardcoded for my machine)
include_directories("/opt/homebrew/opt/z3/include")
link_directories("/opt/homebrew/opt/z3/lib")

add_library(Z3::Z3 STATIC IMPORTED)
set_target_properties(Z3::Z3 PROPERTIES
    IMPORTED_LOCATION "/opt/homebrew/opt/z3/lib/libz3.dylib"
    INTERFACE_INCLUDE_DIRECTORIES "/opt/homebrew/opt/z3/include"
)

pybind11_add_module(propagator propagator.cpp)
target_link_libraries(propagator PRIVATE pybind11::module Z3::Z3)

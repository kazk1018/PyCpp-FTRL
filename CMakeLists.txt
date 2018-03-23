cmake_minimum_required(VERSION 3.8)
project(ftrl CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# build settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

# sources
set(SOURCE_FILES src/py.cc src/ftrl.cc src/ftrl.h)

# pyenv settings
set(PYTHON_VERSION 3.6.2)
set(PYENV_VERSION_DIRECTORY $ENV{HOME}/.pyenv/versions/${PYTHON_VERSION})
set(PYTHON_EXECUTABLE ${PYENV_VERSION_DIRECTORY}/bin/python)

# pybind11
add_subdirectory(pybind11)

set(PYBIND11_CPP_STANDARD -std=c++11)

# eigen
find_package(Eigen3 REQUIRED)

if (EIGEN3_FOUND)
    message(${EIGEN3_INCLUDE_DIR})
    include_directories(${EIGEN3_INCLUDE_DIR})
endif()

# build
pybind11_add_module(ftrl ${SOURCE_FILES})

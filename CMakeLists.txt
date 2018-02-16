cmake_minimum_required(VERSION 3.0.2)

project(RayTracer)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR ${ROOT_DIR}/src)

find_package(CUDA QUIET REQUIRED)

set(INC
  ${ROOT_DIR}/inc/
  )

set(SRC
  ${SRC_DIR}/main.cpp
  )

include_directories(${INC})

set(CMAKE_CXX_FLAGS "-g -W -Wall -std=c++11")
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; "")

cuda_add_executable(ray_tracer ${SRC})
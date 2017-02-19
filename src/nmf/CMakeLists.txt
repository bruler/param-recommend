# Copyright 2017 Kapil Gupta
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


cmake_minimum_required(VERSION 3.2)
project(nmf)

# settings
set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall -Wextra -Wuninitialized")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
set(CMAKE_FILES_DIRECTORY "build/")

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(EIGEN3_INCLUDE_DIR)

set(TRAIN
  ${PROJECT_SOURCE_DIR}/NMFTrain.cpp
)

set(TEST
  ${PROJECT_SOURCE_DIR}/NMFTest.cpp
)

add_library(NMF
  lfm.cpp
  sparse.cpp
  nmf.cpp
)

link_directories(${CMAKE_BINARY_DIR}/bin)
add_executable(${CMAKE_PROJECT_NAME}_tr ${TRAIN})
add_executable(${CMAKE_PROJECT_NAME}_te ${TEST})

target_link_libraries(${CMAKE_PROJECT_NAME}_tr
  Eigen3::Eigen
  NMF
  pthread
)

target_link_libraries(${CMAKE_PROJECT_NAME}_te
  Eigen3::Eigen
  NMF
  pthread
)

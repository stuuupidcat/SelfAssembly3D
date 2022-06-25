cmake_minimum_required(VERSION 3.0.0)
project(SelfAssembly VERSION 0.1.0)

add_executable(SelfAssembly main.cpp
                            src/grid.cpp
                            src/agent.cpp
                            src/coordinator.cpp
                            src/compare.cpp)


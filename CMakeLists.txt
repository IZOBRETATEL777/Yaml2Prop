cmake_minimum_required(VERSION 3.20)
project(Yaml2Prop C)

set(CMAKE_C_STANDARD 11)

add_executable(Yaml2Prop main.c String.c String.h YamlParser.c YamlParser.h Scalar.c Scalar.h Chain.c Chain.h)
target_link_libraries (Yaml2Prop yaml)

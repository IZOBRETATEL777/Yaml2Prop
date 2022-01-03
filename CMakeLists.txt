cmake_minimum_required(VERSION 3.20)
project(Yaml2Prop C)

set(CMAKE_C_STANDARD 11)

add_executable(Yaml2Prop src/main.c src/entity/String.c src/entity/String.h src/tool/YamlParser.c src/tool/YamlParser.h src/entity/Scalar.c src/entity/Scalar.h src/entity/Chain.c src/entity/Chain.h src/entity/ChainList.c src/entity/ChainList.h)
target_link_libraries (Yaml2Prop yaml)

cmake_minimum_required(VERSION 3.11)
project(Yaml2Prop C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(src/lib/libyaml)
add_executable(Yaml2Prop
        src/main.c
        src/entity/String.c
        src/tool/YamlParser.c
        src/entity/Scalar.c
        src/entity/Chain.c
        src/entity/ChainList.c
        src/tool/PropertiesOutput.c
        src/tool/Printer.c
        src/exception/Error.c
        )
target_link_libraries(Yaml2Prop yaml)

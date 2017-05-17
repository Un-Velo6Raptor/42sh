cmake_minimum_required(VERSION 3.6)
project(PSU_2016_42sh)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB helloworld_SRC
        "include/*.h"
        "src/*.c"
        "src/command/*.c"
        "src/parseur/*.c"
        "src/globing/*.c"
        "src/alias/*.c"
        "src/builtins/*.c"
        "src/line_editing/*.c"
        )

file(GLOB lib_SRC
        "lib/src/*.c"
        "lib/basic.h")

add_library(basic STATIC ${lib_SRC} src/globing/globing.c include/globing.h src/history/history.c include/history.h)

add_executable(PSU_2016_42sh ${helloworld_SRC} src/builtins/echo.c src/command/file.c)

target_link_libraries(PSU_2016_42sh basic)

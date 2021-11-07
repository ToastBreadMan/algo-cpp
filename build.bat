@echo off
IF NOT EXIST build (
    echo build dir is getting created
    mkdir build
)
cmake -S . -B build
cmake --build build
.\build\Debug\without_stdlibs.exe
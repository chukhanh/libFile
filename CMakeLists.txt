cmake_minimum_required(VERSION 3.28)
project(LibStruct)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibStruct main.cpp
        Common/Common.cpp
        Common/Common.h
        Date/Date.h
        Date/Date.cpp
        Reader/Reader.cpp
        Reader/Reader.h
        File/File.cpp
        File/File.h
)

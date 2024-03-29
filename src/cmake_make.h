#ifndef _CMAKE_MAKE_H
#define _CMAKE_MAKE_H

#include <string>

std::string cmake_make(std::string name) { 
    std::string cmakeFile{};

    cmakeFile += "cmake_minimum_required(VERSION 3.0.0)\n";
    cmakeFile += "project(" + name + ")\n";
    cmakeFile += "\n";
    cmakeFile += "set(SOURCE_FILES src/main.cpp)\n";
    cmakeFile += "\n";
    cmakeFile += "add_executable(${PROJECT_NAME} ${SOURCE_FILES})\n";

    return cmakeFile;
}

#endif // _CMAKE_MAKE_H

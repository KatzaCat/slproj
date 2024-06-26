#ifndef _MAKE_CPP_H
#define _MAKE_CPP_H

#include <string>

#include "c++_main.h"
#include "c++_makefile.h"
#include "../cmake_make.h"

#include "../util/util.h"

bool make_cpp_project(std::string name, bool cmake) {
    std::string compilationFile{};

    const std::string rootDirectory = "./" + name;
    const std::string srcDirectory = rootDirectory + "/src";
    const std::string binDirectory = rootDirectory + "/bin";
    const std::string outFile = rootDirectory + "/out";

    const std::string mainFile = srcDirectory + "/main.cpp";

    if (cmake) {
        compilationFile = rootDirectory + "/CMakeLists.txt";
    } else {
        compilationFile = rootDirectory + "/Makefile";
    }

    if (!make_directory(rootDirectory)) {return false;}
    if (!make_directory(srcDirectory)) {return false;}
    if (!make_directory(binDirectory)) {return false;}
    if (cmake) {if (!make_directory(outFile)) {return false;}}

    if (!make_file(mainFile, main_contents())) {return false;}
    if (cmake) {
        if (!make_file(compilationFile, cmake_make(name))) {return false;}
    } else {
        if (!make_file(compilationFile, makefile_contents(name))) {return false;}
    }

    return true;
}

#endif // _MAKE_CPP_H

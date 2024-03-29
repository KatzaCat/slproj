#ifndef _MAKE_C_H
#define _MAKE_C_H

#include <iostream>
#include <string>

#include "c_main.h"
#include "c_makefile.h"
#include "../cmake_make.h"

#include "../util/util.h"

bool make_c_project(std::string name, bool cmake) {
    std::string compilationFile{};

    const std::string rootDirectory = "./" + name;
    const std::string srcDirectory = rootDirectory + "/src";
    const std::string binDirectory = rootDirectory + "/bin";
    const std::string outFile = rootDirectory + "/out";
    
    const std::string mainFile = srcDirectory + "/main.c";

    if (cmake) {
        compilationFile = rootDirectory + "/CMakeLists.txt";
    } else {
        compilationFile = rootDirectory + "/Makefile";
    }


    if (!make_directory(rootDirectory)) {return false;}
    if (!make_directory(srcDirectory)) {return false;}
    if (!make_directory(binDirectory)) {return false;}
    if (cmake) {if (!make_directory(outFile)) {return false;}}

    if (!make_file(mainFile, main_c_contents())) {return false;}
    if (cmake) {
        if (!make_file(compilationFile, cmake_make(name))) {return false;}
    } else {
        if (!make_file(compilationFile, makefile_c_contents(name))) {return false;}
    }

    
    return true;
}

#endif // _MAKE_C_H

#ifndef _MAKE_CPP_H
#define _MAKE_CPP_H

#include <string>

#include "c++_main.h"
#include "c++_makefile.h"

#include "../util/util.h"

bool make_cpp_project(std::string name) {
    const std::string rootDirectory = "./" + name;
    const std::string srcDirectory = rootDirectory + "/src";
    const std::string binDirectory = rootDirectory + "/bin";
    
    const std::string mainFile = srcDirectory + "/main.cpp";
    const std::string makeFile = rootDirectory + "/Makefile";

    if (!make_directory(rootDirectory)) {return false;}
    if (!make_directory(srcDirectory)) {return false;}
    if (!make_directory(binDirectory)) {return false;}

    if (!make_file(mainFile, main_contents())) {return false;}
    if (!make_file(makeFile, makefile_contents(name))) {return false;}

    return true;
}

#endif // _MAKE_CPP_H
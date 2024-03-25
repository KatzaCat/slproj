#ifndef _MAKE_C_H
#define _MAKE_C_H

#include <iostream>
#include <string>

#include "c_main.h"
#include "c_makefile.h"

#include "../util/util.h"

bool make_c_project(std::string name) {
    const std::string rootDirectory = "./" + name;
    const std::string srcDirectory = rootDirectory + "/src";
    const std::string binDirectory = rootDirectory + "/bin";
    
    const std::string mainFile = srcDirectory + "/main.c";
    const std::string makeFile = rootDirectory + "/Makefile";

    if (!make_directory(rootDirectory)) {return false;}
    if (!make_directory(srcDirectory)) {return false;}
    if (!make_directory(binDirectory)) {return false;}

    if (!make_file(mainFile, main_c_contents())) {return false;}
    if (!make_file(makeFile, makefile_c_contents(name))) {return false;}
    
    return true;
}

#endif // _MAKE_C_H
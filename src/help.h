#ifndef _HELP_H
#define _HELP_H

#include <iostream>

// simply put, it prints help
void print_help() {
    std::cout << "\tslproj -c_make [c/c++] <name> | Makes a project of either a c or c++ project, with make\n";
    std::cout << "\tslproj -c_cmake [c/c++] <name> | Makes a project of either a c or c++ project, with cmake\n";
}

#endif // _HELP_H

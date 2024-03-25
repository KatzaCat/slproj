#include <iostream>
#include <string.h>

#include "c/make_c.h"
#include "c++/make_c++.h"
#include "help.h"

#define ARGUMENT_HELP "-help"
#define ARGUMENT_CREATE "-c"

int main(int argc, char** argv) {
    // if there are more than 0 arguments
    if ((argc - 1) < 1) {
        std::cout << "0 arguments passed, at least one is required" << std::endl;
        return -1;
    }

    // if the user needs help
    if (strcmp(argv[1], ARGUMENT_HELP) == 0) {
        // help cannot fail
        print_help();
        return 0;
    }

    // if the user wants to make a project
    if(strcmp(argv[1], ARGUMENT_CREATE) == 0) {
        // if a name isn't passed
        if ((argc - 1) < 3) {
            std::cout << "Too few arguments passed\n";
            std::cout << "\tslproj -help" << std::endl;
            return -1;
        }
        // if we wanna make a c project
        if (strcmp(argv[2], "c") == 0) 
        {if (!make_c_project(argv[3])) return -1; else return 0;}
        // if we wanna make a c++ project
        if (strcmp(argv[2], "c++") == 0) 
        {if (!make_cpp_project(argv[3])) return -1; else return 0;}
        // neither were passed
        std::cout << "Required argument [c/c++] not found\n";
        std::cout << "\tslproj -help" << std::endl;
        return -1;
    }
    
    // if the command isn't a valid argument
    std::cout << "Argument \"" << argv[1] << "\" is not a valid argument\n";
    std::cout << "\tslproj -help" << std::endl;
    return 0;
}
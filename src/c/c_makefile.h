#ifndef _C_MAKEFILE_H
#define _C_MAKEFILE_H

#include <string>

std::string makefile_c_contents(std::string name) {
    std::string makefileContents{};

    makefileContents += "NAME = " + name + "\n";
    makefileContents += "\n";
    makefileContents += "INCLUDES  = -I src\n";
    makefileContents += "INCLUDES += # -I other includes\n";
    makefileContents += "\n";
    makefileContents += "SOURCE  = $(wildcard src/*.c)\n";
    makefileContents += "SOURCE += $(wildcard src/**/*.c)\n";
    makefileContents += "\n";
    makefileContents += "LIBRARIES = # -L library\n";
    makefileContents += "\n";
    makefileContents += "LINKER = # -lexample\n";
    makefileContents += "\n";
    makefileContents += "BUILD_FLAGS = -s\n";
    makefileContents += "COMPILE_FLAGS = -Wall -Werror -pedantic\n";
    makefileContents += "\n";
    makefileContents += "COMPILER = gcc\n";
    makefileContents += "\n";
    makefileContents += "all: object\n";
    makefileContents += "\t${COMPILER} *.o -o bin/${NAME} ${BUILD_FLAGS} ${LIBRARIES} ${LINKER}\n";
    makefileContents += "\n";
    makefileContents += "object:\n";
    makefileContents += "\t${COMPILER} -c ${SOURCE} ${COMPILE_FLAGS} ${INCLUDES}\0";

    return makefileContents;
}

#endif // _C_MAKEFILE_H
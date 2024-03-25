#ifndef _C_MAIN_H
#define _C_MAIN_H

#include <string>

std::string main_c_contents() {
    std::string mainContents{};

    mainContents += "#include <stdio.h>\n";
    mainContents += "\n";
    mainContents += "int main(int argc, char** argv) {\n";
    mainContents += "\tprintf(\"Hello World!\");\n";
    mainContents += "\t\n";
    mainContents += "\treturn 0;\n";
    mainContents += "}\0";

    return mainContents;
}

#endif // _C_MAIN_H
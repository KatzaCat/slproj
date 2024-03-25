#ifndef _CPP_MAIN_H
#define _CPP_MAIN_H

#include <string>

std::string main_contents() {
    std::string mainContents{};

    mainContents += "#include <iostream>\n";
    mainContents += "\n";
    mainContents += "int main(int argc, char** argv) {\n";
    mainContents += "\tstd::cout << \"Hello World!\" << std::endl;\n";
    mainContents += "\t\n";
    mainContents += "\treturn 0;\n";
    mainContents += "}\0";

    return mainContents;
}

#endif // _CPP_MAIN_H
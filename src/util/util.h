#ifndef _UTIL_H
#define _UTIL_H

#include <iostream>
#include <string>
#include <fstream>

/**
 * Makes a directory from the current path, with a bit of 
 * debugging info
 * 
 * @param path the path you wanna make
 * 
 * @returns `true` on success and `false` if failed
*/
bool make_directory(std::string path) {
    if (system(("mkdir " + path).c_str()) != 0) {
        std::cout << path << "\n\tcould not be created\n";
        return false;
    }
    std::cout << "Creating directory:\n\t" << path << "\n";
    return true;
}

/**
 * Makes a file at a given path, with some debugging info
 * 
 * @param file the file to make
 * @param contents the name of the file to make
 * 
 * @returns `true` on success and `false` if failed
*/
bool make_file(std::string file, std::string contents) {
    std::ofstream outFile(file);
    if (!outFile.is_open()) {
        std::cout << "Failed to create file:\n\t" << file << "\n";
        return false;
    }
    outFile << contents;
    std::cout << "Made and filled file:\n\t" << file << "\n";
    return true;
}

#endif // _UTIL_H
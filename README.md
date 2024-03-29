# slproj
A command line utility for creating c/c++ projects!

## usage
in the terminal, run the `slproj` command to make a new project

### c_make
if you want to make a project that utilizes a simple `Makefile`.  
```bash
slproj -c_make [c/c++] <name>
```  
you can specify the type of project you wanna make, 
where `c` will make a c project, and `c++` will make a c++ project.  
you can also specify the name: `name`  


### c_cmake
if you want to make a project that utilizes cmake and `CMakeLists.txt`.  
```bash
slproj -c_cmake [c/c++] <name>
```


## what to expect
whenever you run this command, the program will make a project of the specified type with the given name  

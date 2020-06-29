#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#include "msh.h"

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

class FileFunctions{
// Pipes the first command's output into the second.
void pipeCmds(char**, char**);

// Given the number of arguments and an array of arguments, this will execute
// those arguments.  The first argument in the array should be a command.
void singleCmd(char** lhBuff);

// Given a string of user input, this will determine if the user wants to
// quit the shell.
//bool want_to_quit(string);

};

#endif
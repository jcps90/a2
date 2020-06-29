#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sys/stat.h>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

const int MAX_ARGS = 256;       //maximum array size

enum PipeStatus {PIPE, NOPIPE}; //assign the enumirator of PIPE if '|' is found otherwise NOPIPE 

PipeStatus parse_command(int, char**, char**, char**);  //allows to use a pipe or just a filename

void pipe_cmd(char**, char**);  //pipes the output of the first program onto the second program

int read_args(char**);          //takes userInput into an array and returns the num of arguments 

void run_cmd(int, char**);      //takes in the number of arguments and the array of args. runs the args

bool want_to_quit(string);      //exit condition

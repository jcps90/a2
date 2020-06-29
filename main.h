/*
Authors: Juan Pina-Sanz, Mikhail Mineev
Users: cssc2147, cssc2160
Class: CS 570, Summer 2020
Assignment 2
Filename: main.h
*/

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

// Reads input from the user into the given array and returns the number of
// arguments taken in.
int readArgs(char**);

// Given the number of arguments and an array of arguments, this will execute
// those arguments.  The first argument in the array should be a command.
void runCmd(int, char**);

// Given a string of user input, this will determine if the user wants to
// quit the shell.
bool quitShell(string);

void pipeCmd(char**, char**);  //pipes the output of the first program onto the second program




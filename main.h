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

const int MAXCHAR = 256;       //maximum array size

enum PipeStatus {PIPE, NOPIPE}; //assign the enumirator of PIPE if '|' is found otherwise NOPIPE 

PipeStatus parseCommand(int, char**, char**, char**);  //allows to use a pipe or just a filename

int readArgs(char**);         //reads in userInput into an array and returns the num or arg elements

void runCmd(char**);     //given number of args and the args array will execute the arguments 

bool quitShell(string);        //given an input will see if user wants to quit from the microshell

void pipeCmd(char**, char**);  //pipes the output of the first program onto the second program




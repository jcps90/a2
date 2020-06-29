/*
Authors: Juan Pina-Sanz, Mikhail Mineev
Users: cssc2147, cssc2160
Class: CS 570, Summer 2020
Assignment 2
Filename: main.cpp
*/

#include "main.h"

int main() {                                                          //takes and runs userInput until the user enters the 'quit' command
  char *userInput[MAXCHAR], *lhBuff[MAXCHAR], *rhBuff[MAXCHAR];
  PipeStatus pipe_status;
  int argc;

  while (1) {
                                                                      // Reads in the command from the user.
    argc = readArgs(userInput);
    pipe_status = parseCommand(argc, userInput, lhBuff, rhBuff);     //reads the userInput and decides if it is necissary to split into left and rigth buffs.
                                                                      //will give a PIPE or NOPIPE enum
    if (pipe_status == PIPE)                                          //PIPE
      pipeCmd(lhBuff, rhBuff);
    else
      runCmd(userInput);                                        //NOPIPE
                                                                      
    for (int i=0; i<argc; i++)                                        //resets userInput for the next input
      userInput[i] = NULL;
  }
  return 0;
}

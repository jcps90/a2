/*
Authors: Juan Pina-Sanz, Mikhail Mineev
Users: cssc2147, cssc2160
Class: CS 570, Summer 2020
Assignment 2
Filename: FileFunctions.cpp
*/

#include "main.h"



PipeStatus parseCommand(int argc, char** userInput, char** lhBuff, char** rhBuff) {     // lhBuff and rhBuff will only be populated if there is a pipe.
  PipeStatus status = NOPIPE;               //pipe status begins as a NOPIPE
  int pipLoc = -1;                          // pipLoc will keep track of where the pipe is located.   

  for (int i=0; i<argc; i++) {              //scans through the arg array and sees if there are any pipes
    if (strcmp(userInput[i], "|") == 0) {   //if pipe is found changes statis to a PIPE and changes pipeLoc to point to the location where the pipe was found
      status = PIPE;
      pipLoc = i;
  }

  
  if (status != NOPIPE) {                   // if pipe found
    for (int i=0; i<pipLoc; i++) {          //goes through the array and stores everything toi the left of the pipe into lhBuff
      lhBuff[i] = userInput[i];
    }
    int count = 0;
    for (int i=pipLoc+1; i<argc; i++) {     //everything to the right of the pipe goes into the rhBuffer 
      rhBuff[count] = userInput[i];
      count++;
    }

    lhBuff[pipLoc] = NULL;                  //nulls both in order to allow for interactions with the exec commands
    rhBuff[count] = NULL;
  }
    return status;            
    }
}


void pipeCmd(char** lhBuff, char** rhBuff){ //pipes the lhBuff onto the rhBuff
  int fds[2]; // file descriptors
  pipe(fds);
  pid_t pid;

  
  if (fork() == 0) {                        //child process 1 start
    dup2(fds[0], 0);
    close(fds[1]);                           //since the child process is not going to be written to we close the pipe
    
    execvp(rhBuff[0], rhBuff);                //execute the command, thro an erro if the command is unable to be executed
    perror("execvp failed");
    
  } else if ((pid = fork()) == 0) {            //child process 2 start
    dup2(fds[1], 1);
    close(fds[0]);                            //since the child process is not going to be written to we close the pipe

    execvp(lhBuff[0], lhBuff);                //execute the command, thro an erro if the command is unable to be executed
    perror("execvp failed");

  } else
    waitpid(pid, NULL, 0);                    //parent needs to wait until the child finishes
}

// This will get input from the user, pipLoc the input into arguments, insert
// those arguments into the given array, and return the number of arguments as
// an integer.
// read the input from the user and pass it though to the array that holds
// the all inputs to be split by the parseCommand
// this function will also prompt the user to start using the microshell
int readArgs(char **userInput){
  char *newString;
  string inputArg;
  int argc = 0;
  //Display a prompt
  char cwd[1024];
  char *currentUser = getenv("USER");
  string currentDir = getcwd(cwd, sizeof(cwd));
  cout << "\n" << currentUser << ":" << currentDir << "% ";
  // continue reading in until the user hits enter
  while (cin >> inputArg) {
    // gives the user the option to exit the shell.
    if (quitShell(inputArg)) {
      exit(0);
    }

    // this will perform the conversion of the input from the user
    //into a string that can be copied into into the input array.
    newString = new char[inputArg.size()+1];
    strcpy(newString, inputArg.c_str());
    userInput[argc] = newString;

    // update our argument counter.
    argc++;

    // stop accepting input after hitting enter.
    if (cin.get() == '\n'){
      break;
    }
  }

  // Have to have the last argument be NULL so that execvp works.
  userInput[argc] = NULL;

  // Return the total number of args input.
  return argc;
}

// For single input of arguments this will fork a new process and run those arguments.
void runCmd(char** userInput){
  pid_t pid;

  // Fork process
  pid = fork();

  // error
  if (pid < 0)
    perror("Error (pid < 0)");

  // child 
  else if (pid == 0) {
    execvp(userInput[0], userInput);
    perror("execvp error");
  // parent 
  }
}

                                                    
bool quitShell(string choice) {                     // provided with an input, this determines whether or not the user wants to exit the shell. 
                                                                                        
    for (unsigned int i=0; i<choice.length(); i++){  // ensure that both EXIT and exit are valid for closing the shell
       choice[i] = tolower(choice[i]);
     }
     return (choice == "exit");
}

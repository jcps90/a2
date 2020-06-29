/*
Authors: Juan Pina-Sanz, Mikhail Mineev
Users: cssc2147, cssc2160
Class: CS 570, Summer 2020
Assignment 2
Filename: FileFunctions.cpp
*/

#include "main.h"

// Based on the number of arguments and the size of the argument array we
// will go through those arguments and update the status of the Pipe
// to whether there is a pipe to a file, or none.
// lhBuff and rhBuff will only be populated if there is a pipe.
PipeStatus parse_command(int argc, char** userInput, char** lhBuff, char** rhBuff) {
  // Start by assuming there are no pipes
  PipeStatus status = NOPIPE;

  // pipLoc will keep track of where the pipe is located.
  int pipLoc = -1;

  // Go through the array of arguments...
  for (int i=0; i<argc; i++) {
    // Pipe found!
    if (strcmp(userInput[i], "|") == 0) {
      status = PIPE;
      pipLoc = i;
  }

  // If a pipe was found...
  if (status != NOPIPE) {
    // Go through the array of arguments up to the point where the
    // pipe was found and store each of those arguments in lhBuff.
    for (int i=0; i<pipLoc; i++)
      lhBuff[i] = userInput[i];

    // Go through the array of arguments from the point where the pipe
    // was found through the end of the array of arguments and store each
    // argument in rhBuff.
    int count = 0;
    for (int i=pipLoc+1; i<argc; i++) {
      rhBuff[count] = userInput[i];
      count++;
    }

    // Terminate lhBuff and rhBuff with NULL, so that execvp likes them.
    lhBuff[pipLoc] = NULL;
    rhBuff[count] = NULL;
  }

  // Return an enum showing whether a pipe was found or not
    return status;
    }
}

// This pipes the output of lhBuff into rhBuff.
void pipeCmd(char** lhBuff, char** rhBuff){
  int fds[2]; // file descriptors
  pipe(fds);
  pid_t pid;

  // child process #1
  if (fork() == 0) {
    // Reassign stdin to fds[0] end of pipe.
    dup2(fds[0], 0);

    // Not going to write in this child process, so we can close this end
    // of the pipe.
    close(fds[1]);

    // Execute the second command.
    execvp(rhBuff[0], rhBuff);
    perror("execvp failed");

  // child process #2
  } else if ((pid = fork()) == 0) {
    // Reassign stdout to fds[1] end of pipe.
    dup2(fds[1], 1);

    // Not going to read in this child process, so we can close this end
    // of the pipe.
    close(fds[0]);

    // Execute the first command.
    execvp(lhBuff[0], lhBuff);
    perror("execvp failed");

  // parent process
  } else
    waitpid(pid, NULL, 0);
}

// This will get input from the user, pipLoc the input into arguments, insert
// those arguments into the given array, and return the number of arguments as
// an integer.
int readArgs(char **userInput){
  char *newString;
  string inputArg;
  int argc = 0;
  //Display a prompt
  char cwd[1024];
  char *currentUser = getenv("USER");
  string currentDir = getcwd(cwd, sizeof(cwd));
  cout << "\n" << currentUser << ":" << currentDir << "% ";
  // Read in arguments till the user hits enter
  while (cin >> inputArg) {
    // Let the user exit out if their input suggests they want to.
    if (quitShell(inputArg)) {
      exit(0);
    }

    // Convert that std::string into a C string.
    newString = new char[inputArg.size()+1];
    strcpy(newString, inputArg.c_str());
    userInput[argc] = newString;

    // Increment our counter of where we're at in the array of arguments.
    argc++;

    // If the user hit enter, stop reading input.
    if (cin.get() == '\n')
      break;
  }

  // Have to have the last argument be NULL so that execvp works.
  userInput[argc] = NULL;

  // Return the number of arguments we got.
  return argc;
}

// Given the number of arguments (argc) and an array of arguments (userInput),
// this will fork a new process and run those arguments.
void runCmd(int argc, char** userInput) {
  pid_t pid;

  // Fork our process
  pid = fork();

  // error
  if (pid < 0)
    perror("Error (pid < 0)");

  // child process
  else if (pid == 0) {
    execvp(userInput[0], userInput);
    perror("execvp error");
  // parent process
  }
}

// Given a string of user input, this determines whether or not the user
// wants to exit the shell.
bool quitShell(string choice) {
    // Lowercase the user input
    for (unsigned int i=0; i<choice.length(); i++){
       choice[i] = tolower(choice[i]);
     }
     return (choice == "exit");
}

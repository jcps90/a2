/*
Authors: Juan Pina-Sanz, Mikhail Mineev
Users: cssc2147, cssc2160
Class: CS 570, Summer 2020
Assignment 2
Filename: main.cpp
*/

#include "main.h"

// Takes user input until they quit the shell, and passes that input as
// arguments to be run.
int main() {
  char *argv[MAX_ARGS], *cmd1[MAX_ARGS], *cmd2[MAX_ARGS];
  PipeStatus pipe_status;
  int argc;

    char cwd[1024];
    char *currentUser = getenv("USER");
    string currentDir = getcwd(cwd, sizeof(cwd));
  // Keep returning the user to the prompt ad infinitum unless they enter
  // 'quit' or 'exit' (without quotes).
  while (true) {
    // Display a prompt.
    cout << "\n" << currentUser << ":" << currentDir << "% ";
    // Read in a command from the user.
    argc = read_args(argv);

    // Decipher the command we just read in and split it, if necessary, into
    // cmd1 and cmd2 arrays.  Set pipe_redirect to a PipeRedirect enum value to
    // indicate whether the given command pipes, redirects, or does neither.
    pipe_status = parse_command(argc, argv, cmd1, cmd2);

    // Determine how to handle the user's command(s).
    if (pipe_status == PIPE)          // piping
      pipe_cmd(cmd1, cmd2);
    else
      run_cmd(argc, argv);              // neither

    // Reset the argv array for next time.
    for (int i=0; i<argc; i++)
      argv[i] = NULL;
  }

  // Let the OS know everything is a-okay.
  return 0;
}

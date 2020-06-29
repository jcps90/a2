#include "FileFunctions.h"

// This function is designed to handle only a single command call and will only
// be called when an command is input without a pipe in the user input.
void FileFunctions::singleCmd(char** lhBuff) {
  pid_t pid;

  // Fork the process to run our command
  pid = fork();
  // output 
  if (pid < 0){
    cout << "Error (pid < 0)";
  }
  // child process
  else if (pid == 0) {
    // run execvp, if we get an error code, output to console
    if (execvp(lhBuff[0], lhBuff) < 0){
        cout << "execvp error";
    }
  }
  // we must tell the parent process to wait for the child to finish
    waitpid(pid, NULL, 0);
}

// This function is designed to reach in from our left hand and right hand buffers
// and to perform a pipe execution with the instructions contained in each buffer.
// This function is intended to be called multiple times for each instance where
// one command is piped into another.
void FileFunctions::pipeCmds(char** lhBuff, char** rhBuff){
    int fileD[2];
    pipe(fileD);
    pid_t pid;

    if (fork () == 0){
        dup2(fileD[0], 0);
        // close the "write" end of the pipe for this child
        close(fileD[1]);

        if(execvp(rhBuff[0],rhBuff) <0 ){
            cout << "File Execution Failed!";
        }

    }else if((pid = fork()) == 0){
        dup2(fileD[1],1);
        // close the "read" end of the pipe for this child
        close(fileD[0]);
        if( execvp(lhBuff[0],lhBuff) < 0{
            cout << "File Execution Failed";
        }

    }else{
        // we must tell the parent process to wait for the child to finish
        waitpid(pid,NULL,0);
    }
}
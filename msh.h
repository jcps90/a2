#ifndef MSH_H
#define MSH_H

#include "FileValidate.h"
//#include "FileHandler.h"
// ^ already includes: 
//  <string.h>

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <readline/history.h>

#define MAXCHAR 256

// We found that we cannot actually clear the console, but we can modify
// the cursor. To do this, we use the escape sequence \0033 followed by
// [H to move the cursor to the upper left corner and [J to clear from
// the cursor down.
#define clearLine() printf("\033[H\033[J")

class msh{
    public:

        //public variables
        string currentUser;
        string currentDir;
        char userInput[MAXCHAR];

        // public constructor
        msh();

        //public function
        void cmdLineLoop();
    private:
        //private variables
        
        //private functions
        void initShell();
    int recieveInput(char *userInput);

    void setCWD();

    int ParseDirectory(string dir);

};

#endif
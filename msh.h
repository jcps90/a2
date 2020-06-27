#ifndef MSH_H
#define MSH_H

#include "FileValidate.h"
//#include "FileHandler.h"
// ^ already includes: 
//  <string.h>


#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h> 
#include <readline/history.h>

#define MAXCHAR 256;

class msh{
    public:

        //public variables
        string currentUser;
        string currentDir;
        char userInput[MAXCHAR];

        // public constructor
        msh();

        //public function
        void cmdLineLoop()
    private:
        //private variables
        
        //private functions
        void initShell();
        int recieveInput();

};

#endif
#ifndef MSH_H
#define MSH_H

#include "FileValidate.h"
#include "FileHandler.h"
// ^ already includes: 
//  <string.h>


#include <stdio.h>

class msh{
    public:

        //public variables
        string currentUser;

        // public constructor
        msh();

        //public function

    private:
        //private variables
        
        //private functions
        void initShell();
        void recieveInput();

};

#endif
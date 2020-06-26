#include "msh.h"

// microshell contstructor
// pull in all necessary variables for running 
msh::msh(void){
    currentUser = getenv("USER");
}

// clear terminal, print welcome statement for the user
void msh::initShell(){
    clear();
    printf("\n\n\tWelcome %s!", currentUser);
    printf("\n\n");
    sleep(1);
}

//run terminal prompt
void msh::recieveInput(){
    char* buf;
    buf = 

}


void exitShell(){
    exit(0);
}

void cmdLineLoop(){
    
}
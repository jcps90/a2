#include "msh.h"

// microshell contstructor
// pull in all necessary variables for running 
msh::msh(void){
    char cwd[1024];
    currentUser = getenv("USER");
    currentDir = getcwd(cwd, sizeof(cwd));
}

// clear terminal, print welcome statement for the user
void msh::initShell(){
    clearLine();
    printf("\n\n\tWelcome %s!", currentUser);
    printf("\n\n");
    sleep(1);
}


// pass through user input and return 
int msh::recieveInput(char *userInput){
    //create an inputBuffer for the direct user input
    char inputBuf[MAXCHAR];
    string outLine = "\n"+ currentUser + ":" + currentDir + "%";
    //read into the buffer the user line with the prompt:
    //cssc9999:<current working directory>%
    cout << outLine;
    cin.getline(inputBuf,MAXCHAR);

    // if there is input in the inputBuffer then we will add it to the 
    // command history so it may be referenced later
    // we then save the inputBuffer to userInput
    if (strlen(inputBuf) != 0){
        strcpy(userInput, inputBuf);
        return 0;
    }
    else{
        return 1;
    }
}


void exitShell(){
    exit(0);
}

void msh::cmdLineLoop(){
    initShell();

    while(1){
        if(recieveInput(userInput)){
            continue;
        }
    }
    
}
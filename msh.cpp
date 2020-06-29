#include "msh.h"

//FileHandler fileH;
FileFunctions fileFun;
// microshell contstructor
// pull in all necessary variables for running msh and
// produce 
msh::msh(void){
    char cwd[1024];
    currentUser = getenv("USER");
    currentDir = getcwd(cwd, sizeof(cwd));
}

// clear terminal, print welcome statement for the user
void msh::initShell(){
    clearLine();
    cout << "\n\n\tWelcome " <<  currentUser << "!";
    cout << "\n\n";
    sleep(1);
}

void msh::clearUserInput(){
    	for(int i = 0; i < MAXCHAR; i++){
        userInput[i] = '\0';
    }
}

// pass through user input and return 
int msh::recieveInput(char *userInput){
    //create an inputBuffer for the direct user input
    char inputBuf[MAXCHAR];
    //string outLine = "\n" + currentUser + ":" + currentDir + "%";
    //read into the buffer the user line with the prompt:
    //cssc9999:<current working directory>%
    cout << "\n" << currentUser << ":" << currentDir << "% ";
    cin.getline(inputBuf,MAXCHAR);
    // if there is input in the inputBuffer then we will add it to the 
    // command history so it may be referenced later
    // we then save the inputBuffer to userInput
    cout << "InputBuf = " << inputBuf << "\n";
    if (strlen(inputBuf) != 0){
        strcpy(userInput, inputBuf);
        cout << "UserInput = " << userInput << "\n";
        return 0;
    }
    else{
        return 1;
    }
}

void exitShell(){
    exit(0);
}

void msh::pipeCount(){
	int i = 0;
    char pipe = '|';
    while( userInput[i+1] != NULL){
            //cout << pipeCounter << "\t";
            if( userInput[i] == pipe){
                //cout << pipeCounter << "\t";
                pipeLocation[pipeCounter] = i;
                cout << "pipeCount PipeLoc: " << pipeLocation[pipeCounter] << "\n";
                pipeCounter++;
            }
        i++;
    }
}

void msh::caseOne(){
    //clear left hand buffer
	for(int i = 0; i < MAXCHAR; i++){
        lhBuff[i] = '\0';
    }

  	int i = 0;
    // load left hand buffer with user input
    while(userInput[i] != NULL){
      	lhBuff[i] = userInput[i];
        i++;
    }//case 1   
}

void msh::caseTwo(){
    // clear left hand and right hand buffer
    cout << "caseTwo PipeLoc preClear: " << pipeLocation[0] << "\n";
	for(int i = 0; i < MAXCHAR; i++){
        lhBuff[i] = '\0';
        rhBuffer[i] = '\0';
        }
    pipeCount();
    cout << "caseTwo PipeLoc postClear: " << pipeLocation[0] << "\n";
    int k = pipeLocation[0];
    int c = k+1;
    cout << c << "\n";

    //load left hand buffer with user input from start
    //until the location of the first delimiter

	//lhbuff goes here

    //load right hand buffer with user input from locaton of
    //1st delimiter + 1 until the end of the input

    for(int i = 0; i < k ; i++){
        //cout << "loading into lhBuff" << lhBuff[i] << "\n";
      	lhBuff[i] = userInput[i];
    }
    cout << "Case Two print lhbuff: " << lhBuff << "\n";
    cout << "rhBuffer array Addr: " << &rhBuffer << "\n";
    
    while( userInput[c] != NULL){
        cout << "userInput = " << userInput[c] << "\n";
        cout << "Case Two print rhbuff[c]: " << rhBuff[c] << "\n";
        cout << "c = " << c << "\n";
        rhBuff[c] = userInput[c];
        c++;
        }
      

}//case 2 

// pipeLocation[0] = pipe #1.
void msh::caseThree(){
    // clear left hand buffer
	for(int i = 0; i < MAXCHAR; i++){
     lhBuff[i] = '\0';
    }
    pipeCount();
	int i = 0;
    // copy right hand buffer into left hand buffer	
    while( rhBuff[i] != NULL){ 
    lhBuff[i] = rhBuff[i];
    i++;
    }
    //clear right hand buffer
    for(int i = 0; i < MAXCHAR; i++){
    rhBuff[i] = '\0';
    }
    pipeCount();
    // load right hand buffer with user input from the location of the current pipe
    // until right before the next pipe
    while( pipeLocation[currentPipe] != NULL){
      	int k = pipeLocation[currentPipe];
        int m = pipeLocation[currentPipe+1];
       	for(k; k < m; k++){
        	rhBuff[k] = userInput[k];
        }
        break;  
    }
    currentPipe++; 
} //case 3   

int msh::caseDecider(){
	if(pipeCounter == 0){
       cout <<"CD: 1/ " << pipeCounter << "\n";
        return 1;		//case 1
    } else if (pipeCounter == 1){
        cout << "CD: 2/ " << pipeCounter << "\n";
    	return 2; //case 2
    } else {
        cout << "CD: 3/ " << pipeCounter << "\n";
    	return 3; //case 3
    }
    
}

void msh::cmdLineLoop(){
    int exeFlag;
    initShell();
    while(1){
        if(recieveInput(userInput)){
            continue;
        }
        pipeCount();
        exeFlag = caseDecider();
        cout << "cmdLineLoop pipeLocation " << pipeLocation[0] << "\n";
        //cout << exeFlag << "\n";
        if(exeFlag == 1){

            caseOne();
            cout << "Case One Used" << "\t";
            cout << "lhbuff = " << lhBuff;

        }else if(exeFlag == 2){

            caseTwo();
            cout << "Case Two Used" << "\n";
            cout << "lhbuff = " << lhBuff << "\n";
            cout << "rhbuff = " << rhBuff << "\n";

        }else if(exeFlag == 3){

            caseTwo();
            cout << "Case Two + " << "\n";
            cout << "lhbuff = " << lhBuff << "\n";
            cout << "rhbuff = " << rhBuff << "\n";
            for(int i = 0; i < pipeCounter; i++){
            caseThree();
            cout << "Case Three Used" << "\n";
            cout << "lhbuff = " << lhBuff << "\n";
            cout << "rhbuff = " << rhBuff << "\n";
            }
        }else{
            cout << "error";
        }
    }
}

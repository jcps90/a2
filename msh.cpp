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

int msh::ParseDirectory(string dir) {
	DIR *tDir;
	
	tDir = opendir(dir.c_str());
	if(tDir == nullptr) {
		cerr << endl << "Error opening directory " << dir 
			 << " (errno: " << errno << ")" << endl;
		return errno;
	}
	
	struct dirent *dirP;
	struct stat filestat;
	string path;
	while( (dirP = readdir(tDir)) ) {
		//Skip current object if it is this directory or parent directory
		if(!strncmp(dirP->d_name, ".", 1) || !strncmp(dirP->d_name, "..", 2))
			continue;
		
		if(dir==".") path = dirP->d_name;
		else		 path = dir + "/" + dirP->d_name;
		
		//Skip current file / directory if it is invalid in some way
		if(stat(path.c_str(), &filestat)) continue;
		
		//Recursively call this function if current object is a directory
		if(S_ISDIR(filestat.st_mode)) {
			ParseDirectory(path);
			continue;
		}
		
		//At this position you can check if the current file (path) is the file you are searching
	}
	
	closedir(tDir);
	
	return 0;
}
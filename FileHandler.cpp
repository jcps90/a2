#include "FileHandler.h"

//exec funtion
void FileHandler::fileNameGet (char array[], int arrSize){     
    int counter;     //see if input has a file with an executable extension
    for(counter = 0; counter < arrSize; counter++){
        if(array[counter] == NULL){ 
            while( array[counter-1] != '/' || array[counter-1] != NULL ){
                fileName = array[counter-1];   //if executable extension is found gets the filename + its extension
                counter--;
                }
            return;  
        }
    }
}//fileExec


void FileHandler::filePathGet (char array[], int arrSize){       //see if the array has "/" in it
    for(int counter = 0; counter < arrSize; counter++){
        if(array[counter] == '/'){
            for (int i = 0; i < arrSize; i++){              //if it does then entered item is file path and needs 
                nFilePath = nFilePath + array[i];           //to replace the default file path
                                                            //if "\" is found file path gets replaced and breaks out of loop
            }
        }
    }
}//filePath



int FileHandler :: filePathCheck(string dir) {
	DIR *fDir;
	
	fDir = opendir(dir.c_str());
	if(fDir == NULL) {
		cout << endl << "Error opening directory " << dir  << endl;
	}
	
	struct dirent *dirPath;
	struct stat filestat;

	while( (dirPath = readdir(fDir)) ) {
		//Skip current object if it is this directory or parent directory
		if( !strncmp(dirPath->d_name, ".", 1) || !strncmp(dirPath->d_name, "..", 2) ){
			continue;
        }
		if(dir=="."){
                path = dirPath->d_name;
        }   
		else{
            	path = dir + "/" + dirPath->d_name;
            }
		//Skip current file / directory if it is invalid in some way
		if(stat(path.c_str(), &filestat)) {
            continue;
            }
		//Recursively call this function if current object is a directory
		if(S_ISDIR(filestat.st_mode)) {
			filePathCheck(path);
			continue;
		}
		
		if( fileName == path){ //At this position you can check if the current file (path) is the file you are searching
            return 1;
        } else{
            return 0;
        }
	
	closedir(fDir);
	
	return 0;
    }//filePathChecker
}
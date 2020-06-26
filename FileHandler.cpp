#include "FileHandler.h"

void FileHandler::fileExec (char array[], int arrSize){          //see if input has a file with an executable extension
    for(int counter = 0; counter < arrSize; counter++){
        if(array[counter] == commands[0] || array[counter] == commands[1]){ 
            fileName = array[counter-1] + array[counter];   //if executable extension is found gets teh filename + its extension
            return;
        }
        else{
            cout << "Not an executable program. \n" << endl;
            cout << "Exiting. \n" << endl;
        }
    }
}//fileExec

void FileHandler::filePath (char array[], int arrSize){       //see if the array has "\" in it
    char slash = "/";

    for(int counter = 0; counter < arrSize; counter++){
        if(array[counter] == slash){
            for (int i = 0; i < arrSize; i++){              //if it does then entered item is file path and needs 
                nFilePath = nFilePath + array[i];           //to replace the default file path
                return;                                     //if "\" is found file path gets replaced and breaks out of loop
            }
        }
    }
}//filePath
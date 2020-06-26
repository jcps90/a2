#include "FileValidate.h"

bool FileValidate::isValidFile(char *path){

    struct stat file;

}

// using the stat() function this function will verify
// if the user has permission to execute the file by using
// .st_mode and checking the S_IEXEC bit
int FileValidate::willExecute(char *path){
    struct stat statBuffer;

    if(stat(path, &statBuffer) == -1 && statBuffer.st_mode & S_IEXEC){
        return -1;
    }else{
        return 0;
    }

}
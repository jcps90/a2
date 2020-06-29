#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "msh.h" 

#include <iostream>
#include <stdlib.h>
#include <dirent.h>
#include <iterator>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

class FileHandler{
    public:
        string nFilePath;
        string fileName;
        string nul;

        string pathname = nFilePath;
        string fName = fileName;

        const char * c = pathname.c_str();
        const char * f = fName.c_str();

        void fileNameGet (char array[], int arrSize);
        void filePathGet (char array[], int arrSize);
        void execCheck(char array[]);

        //int  filePathCheck (string dir);




};

#endif

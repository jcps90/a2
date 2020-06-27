#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "msh.h" 

#include <iostream>
#include <stdlib.h>
#include <dirent.h>
#include <iterator>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

class FileHandler{
    public:
        string nFilePath;
        string fileName;
        
        void fileNameGet (char array[], int arrSize);
        void filePathGet (char array[], int arrSize);
        int  filePathCheck (string dir);

    private:

    string path;

};

#endif

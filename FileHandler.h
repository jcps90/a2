#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
//#include <dirent.h>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class FileHandler{
    public:
        string nFilePath;
        string fileName;

    private:
        char commands[64] = { 'exe', 'cpp'};
        
        void fileExec (char array[], int arrSize);
        void filePath (char array[], int arrSize);

};

#endif
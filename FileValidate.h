#ifndef FILEVALIDATE_H
#define FILEVALIDATE_H

#include <string>
#include <sys/types.h>

using namespace std;

class FileValidate{

    public:
        bool isValidFile(char *filePath);
        int willExecute(char *filepath);

};

#endif
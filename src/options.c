#include <stdlib.h>

const int MAX_F_NAME_ = 33;

const *defaultPath = "./newProject";
const *pathPrefix = "./";



typedef struct Options{
    char* language;
    char* projectName[33];
};

void printHelp(){
    int helpSize;
    char* helpInfo[] ={"./[mainDir]","-n [Name of project]", "\n", "-m", "-d [Name of sub dir]"};



    helpSize = sizeof(helpInfo);
    for (int i = 0; i < helpSize; i++){
        printf("%s \n", helpInfo[i]);
    }
    exit(0);
}
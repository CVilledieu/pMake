#include <stdlib.h>
#include <options.h>


const *defaultPath = "./newProject";
const *pathPrefix = "./";

typedef struct Options{
    char* language;
    char *projectName[MAX_F_NAME];
};

//If format error is found printSuggestHelp() is ran
void printSuggestHelp(){
    printf("%s\n", "run 'pMake -h' for help");
}

//Prints information about the pMake when user runs pMake -h or -help
void printHelp(){
    //general info about how to run pMake correctly
    info();
    //prints the available flags/options that can be provided when ran
    flags();
    exit(0);
}


void info(){
    char *info;
    info = "To run:\n pMake [flags/options]\n requred flags are -n [name of project/root dir] and -l [language]";
    printf("%s \n", info);
}


void flags(){
    int helpSize;
    char* helpInfo[] ={"-n [Name of project]", "-l [desired language]", "-h"};
    printf("%s\n", "List of commands:");
    helpSize = sizeof(helpInfo);
    for (int i = 0; i < helpSize; i++){
        printf("\t %s  \n", helpInfo[i]);
    }

    exit(0);
}
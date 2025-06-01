#include <stdlib.h>
#include <stdio.h>


void info(void);
void flags(void);


//If format error is found printSuggestHelp() is ran
void printSuggestHelp(void){
    printf("%s\n", "run 'pMake -h' for help");
}

//Prints information about the pMake when user runs pMake -h or -help
void printHelp(void){
    //general info about how to run pMake correctly
    info();
    //prints the available flags/options that can be provided when ran
    flags();
    exit(0);
}


void info(void){
    char *info;
    info = "To run:\n pMake [flags/options]\n requred flags are -n [name of project/root dir] \n if language is not provided a blank project will be created";
    printf("%s \n", info);
}


void flags(void){
    int helpSize;
    char* helpInfo[] ={"-n [Name of project]", "-l [desired language]", "-h"};
    printf("%s\n", "List of commands:");
    helpSize = sizeof(helpInfo);
    for (int i = 0; i < helpSize; i++){
        printf("\t %s  \n", helpInfo[i]);
    }

    exit(0);
}
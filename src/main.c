#include <stdio.h>
#include <stdlib.h>



typedef struct Options{
    char *fPath;
    char *fName;
    int git;
    int make;
    int language; 
}Options;

void parseInput(int argc, char *argv[], Options* options);

const char *default_path = "./%s\n";
const char *default_name = "newProject";


int main(int argc, char *argv[]) {
    Options* options = malloc(sizeof(Options));
    parseInput(argc, argv, &options);
    FILE *fp;
    char projectName = "test";
    char fName = "test.c";
    sprintf(".//%s//",projectName, fName);

    return 0;    
}

void parseInput(int argc, char *argv[], Options* options) {
    printf("%s\n", "Parse input");
}
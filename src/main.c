#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


typedef struct Options{
    char fPath[_MAX_PATH];
    char fName[_MAX_FNAME];
    int git;
    int make;
}Options;

void parseArguments(int argc, char *argv[], Options *opt);

const char *default_path = ".";
const char *default_name = "newProject";


int main(int argc, char *argv[]) {
    Options* options = malloc(sizeof(Options));
    parseArguments(argc, argv, options);
    int fMakeErr;

    fMakeErr = mkdir(default_path);
    if (fMakeErr == -1) {
        printf("Error creating directory\n");
        return 1;
    }

    

    free(options);
    return 0;    
}

void parseArguments(int argc, char *argv[], Options *options) {
    if (argc < 2) {
        printf("No path or name provided.\n");
        printf("Defaulting to path: %s and name: %s\n", 
            default_path, default_name);
        return;
    }
    for (int i = 1; i < argc; i++) {
        switch (argv[i][0]) {
            case '.':
                formatPath(argv[i], options->fPath);
            case '-':
                if (i+1 >= argc || argv[i+1] == '-') {
                    parseOptions(argv[i][1], NULL);
                } else {
                    parseOptions(argv[i][1], argv[i+1]);
                }
                
                
            default:
                printf("Unknown option: %s\n", argv[i]);
        }
    }

}


void createFile(char *fName) {
    FILE *fp;
    fp = fopen(fName, "w");
    if (fp == NULL){
        printf("File: %s was not created. \n", fName);
    }
    fclose(fp);
    
}
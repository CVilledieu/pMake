#ifndef OPTIONS_H
#define OPTIONS_H

#define MAX_F_NAME 32

typedef struct Options{
    char* language;
    char *projectName[MAX_F_NAME];
} Options;

void printHelp();

#endif
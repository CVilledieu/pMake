#ifndef OPTIONS_H
#define OPTIONS_H

extern const int MAX_F_NAME;

typedef struct Options{
    char* language;
    char* projectName[33];
};

void printHelp();

#endif
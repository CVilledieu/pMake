#ifndef OPTIONS_H
#define OPTIONS_H

enum languages{
    C,
    Go,
    Js,
    Unknown
};


typedef struct Project{
    char *name;
    enum languages language;
}Project;

Project parseInput(int argc, char* argv[]);

#endif
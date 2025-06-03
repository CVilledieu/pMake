#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void printHelp(void);
void printSuggestHelp(void);
enum languages parseLanguage(char* language);

enum languages {
    C,
    Go,
    Js,
    Unknown
};

typedef struct Project{
    char *name;
    enum languages language;
}Project;

//parses input
//if help is flagged func calls printHelp() then exits
//if valid input was given parseInput() returns a struct to be used to create the project
Project parseInput(int argc, char* argv[]){
    Project newProject;
    //sets the default values of both the name and the language
    newProject.name = "newProject";
    newProject.language = C;
    int options;
    while ((options = getopt(argc,argv,"hHo:O:l:L:")) != -1){
        switch(options){
            case 'o':
            case 'O':
                newProject.name = optarg;
                break;
            case 'l':
            case 'L':
                newProject.language = parseLanguage(optarg);
                break;
            case '?': printSuggestHelp();break;
            case ':': 
                printSuggestHelp();
                break;
            case 'h':
            case 'H':
                printHelp();
            default:
                printSuggestHelp();
                exit(1);
        }
    }

    return newProject;
}

enum languages parseLanguage(char* language){
    switch(language[0]){
        case 'g':
        case 'G':
            if(language[1] == 'o'|| language[1] == 'O'){
                return Go;
            }
            break;
        case 'c':
        case 'C':
            if ((language[1]=='\0')){
                return C;
            }
            break;
        case 'j':
        case 'J':
            if(language[1] == 's' || language[1] == 'S'){
                return Js;
            }
            break;
        default: 
            return Unknown;
            break;
        return Unknown;
    }


    if ((language[0] == 'g'|| language[0] == 'G') &&  (language[1] == 'o'|| language[1] == 'O')){
        return Go;
    } else if ((language[0] == 'c' || language[0] == 'C')&& (language[1]=='\0')){
        return C;
    }else if ((language[0] == 'j' || language[1] == 'J') && (language[1] == 's' || language[1] == 'S')){
        return Js;
    }else{
        return Unknown;
    }
}

//If format error is found printSuggestHelp() is ran
void printSuggestHelp(void){
    printf("%s\n", "run 'pMake -h' for help");
}

//Prints information about the pMake when user runs pMake -h or -help
void printHelp(void){
    printf("\n"
        "Help is on the way!\n\n"
        "Usage: pMake [options]"
        "Options:\n"
        "\t-o [name of project]\t If unused project name will default to newProject.\n"
        "\t-l [desired language]\t If unused language will default to C.\n"
        "\nConfig support coming soon!\n"
        "Github.com/cvilledieu\n"
    );
    exit(1);
}


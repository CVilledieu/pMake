#include <stdio.h>
#include <stdlib.h>


typedef struct { 
    char *fPath;
    char *fName;
    Options options;
}Project;

typedef struct {
    int git;
    int make;
    int language; 
}Options;

int getLanguage(char *lang);

const char *default_path = "default/path";
const char *default_name = "default_name";


int main(int argc, char *argv[]) {
    Project *proj = malloc(sizeof(Project));
    Options *options = malloc(sizeof(Options));
    if (argc < 2) {
        printf("No arguments provided. Using default project name and path.\n");
        proj->fPath = default_path;
        proj->fName = default_name;
    }
    for (int i = 0; i < argc; i++) {
        switch (argv[i][0]){
            case '-':
                switch (argv[i][1]){
                    case 'g':
                        proj->options.git = 1;
                        break;
                    case 'm':
                        proj->options.make = 1;
                        break;
                    case 'l':
                        proj->options.language = getLanguage(argv[i+1]);
                        break;
                    default:
                        printf("Unknown option: %s\n", argv[i]);
                }
                break;
        }
        
    }
    FILE *file = fopen(argv[1], "r");
}
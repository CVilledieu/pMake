/*
To run make sure pMake is in system file path
*/
#include <options.h>
#include <stdlib.h>
#include <stdio.h>
#include <direct.h>

void createProject(char * name, char *lang);
void createFile(char* name, char* content);

int main(int argc, char *argv[]) { 
    if (argc < 2){
        printf("%s\n", "No input arguments given");
        return 0;
    }
    for (int i = 0; i < argc; i++){
        if (argv[i][0] == '-'){
            if (argv[i][1] == '\0'){
                continue;
            }
            switch(argv[i][1]){
                case 'n':
                    if (i+1 < argc){
                        createProject(argv[i+1], "c");
                    } else {
                        break;
                    }
                case 'h':
                    printHelp();
            }
        }
        
    }
    return 0;    
}

 
//Languages are parsed in func int parseLang(char *argv[])
void createProject(char * name, char *lang){

    //create dir with project name
    if (_mkdir(name) != 0){
        printf("Error:\n\t unable to create directory with path:\n\t %s", name);
        exit(1);
    }

    //Change to the project dir
    if(_chdir(name) != 0){
        printf("Error: \n\t unable to switch to project directory.");
        exit(1);
    }
    _mkdir("src");
    _mkdir("bin");

    createFile(".gitignore", "bin");
    createFile("readme.md", name);

    /*
    switch (*lang) {
        case 'go':
            CreateC();
        case 'c':
            CreateGo();
        case 'js':
            createJs();
        case  'w':
            createWeb();
        default:
            CreateBlank();
    }
    */

    return;
}

void createFile(char* name, char* content){
    FILE *fp;
    fp = fopen(name, "w");

    fputs(content, fp);

    fclose(fp);
}
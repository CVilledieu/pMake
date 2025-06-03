/*
To run make sure pMake is in system file path
*/
#include <options.h>
#include <stdlib.h>
#include <stdio.h>
#include <direct.h>
#include <fileinfo.h>

void createProject(char * name, enum languages language);
void createFile(char* name, char* content);


int main(int argc, char *argv[]) { 
    Project pro;
    pro = parseInput(argc, argv);
    createProject(pro.name, pro.language);
    return 0;    
}


 
//Languages are parsed in func int parseLang(char *argv[])
void createProject(char * name, enum languages language){

    //create dir with project name
    if (_mkdir(name) != 0){
        printf("Error:\n\t Unable to create directory with path:\n\t %s", name);
        exit(1);
    }

    //Change to the project dir
    if(_chdir(name) != 0){
        printf("Error: \n\t Unable to switch to project directory.");
        exit(1);
    }
    _mkdir("src");
    _mkdir("bin");

    createFile(".gitignore", "bin/*");
    createREADME(name);
    createMain(language);

    return;
}

void createFile(char* name, char* content){
    FILE *fp;
    fp = fopen(name, "w");

    fputs(content, fp);

    fclose(fp);
    return;
}
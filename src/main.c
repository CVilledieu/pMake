/*
To run make sure pMake is in system file path
*/
#include <options.h>
#include <stdlib.h>
#include <stdio.h>
#include <direct.h>


void cFiles(void);
void goFiles(void);
void createProject(char * name, enum languages language);
void createFile(char* name, char* content);
void createREADME(char* name);


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

    switch(language){
        case C:
            cFiles();
            break;
        case Go:
            goFiles();
            break;
        case Js:
            break;
        default:
            break;
    }
    return;
}

void createFile(char* name, char* content){
    FILE *fp;
    fp = fopen(name, "w");

    fputs(content, fp);

    fclose(fp);
    return;
}

void createREADME(char* name){
    FILE *fp;
    fp = fopen("README.md", "w");

    fputs("# ", fp);
    fputs(name,fp);

    fclose(fp);
    return;
}


void cFiles(void){
    //file pointer to main
    FILE *mainfp;
    mainfp = fopen("src/main.c","w");
    char *mainContent = "int main(void){\n"
    "\treturn 0;\n"
    "}";
    fputs(mainContent, mainfp);
    fclose(mainfp);

    FILE *makefp;
    makefp = fopen("makefile","w");
    char *makeContent = "CC = GCC\n"
    "\n"
    "CFLAGS = -Wall $(inc)\n"
    "out = ./bin\n"
    "sDir = ./src\n"
    "inc = -Isrc/include\n";
    fputs(makeContent, makefp);
    fclose(makefp);
    _mkdir("src/include");
    return;
}

void goFiles(void){
    FILE *mainfp;
    mainfp = fopen("src/main.go","w");
    char *mainContent = "package main\n"
    "func main(){\n}";
    fputs(mainContent, mainfp);
    fclose(mainfp);

    FILE *makefp;
    makefp = fopen("makefile","w");
    char *makeContent = "go build main.go";
    fputs(makeContent, makefp);
    fclose(makefp);

    system("go mod init main");
    
    return;
}

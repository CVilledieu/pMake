/*
To run make sure pMake is in system file path
*/
#include <options.h>
#include <stdlib.h>
#include <stdio.h>
#include <direct.h>


void cFiles(void);
void goFiles(void);
void jsFiles(void);
void webFiles(void);
void createGitignore(void);
void createREADME(char* name);


int main(int argc, char *argv[]) {
    Project project;
    project = parseInput(argc, argv);


    //create dir with project name
    if (_mkdir(project.name) != 0){
        printf("Error:\n\t Unable to create directory with path:\n\t %s", project.name);
        exit(1);
    }

    //Change to the project dir
    if(_chdir(project.name) != 0){
        printf("Error: \n\t Unable to switch to project directory.");
        exit(1);
    }

    //main src dir
    _mkdir("src");
    //main output dir
    _mkdir("bin");

    createGitignore();
 

    switch(project.language){
        case C:
            cFiles();
            break;
        case Go:
            goFiles();
            break;
        case Js:
            jsFiles();
            break;
        case Web:
            webFiles();
            break;
        default:
            break;
    }

    createREADME(project.name);
    return 0;    
}




void createGitignore(void){
    FILE *fp;
    fp = fopen(".gitignore", "w");
    char* content;
    content = ".gitignore";
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

void jsFiles(void){
    FILE *jsfp;
    jsfp = fopen("src/main.js","w");
    char *jsContent;
    jsContent = "main =()=>{\n}";
    fputs(jsContent, jsfp);
    fclose(jsfp);

    return;
}

void webFiles(void){
    FILE *webfp;
    webfp = fopen("src/index.js", "w");
    char* content;
    content = "main = ()=>{\n}";
    fputs(content, webfp);
    fclose(webfp);

    FILE *hfp;
    hfp = fopen("src/views/index.html","w");
    fclose(hfp);

    return;
}
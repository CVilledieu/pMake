#include <stdio.h>
#include <direct.h>
#include <stdlib.h>

void createEnv(void){
    FILE *fp;
    fp = fopen(".env","w");
    fclose(fp);
    return;
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
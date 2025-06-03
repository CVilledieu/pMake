#include <stdio.h>
#include <stdlib.h>
#include <options.h>

void createREADME(char* name){
    FILE *fp;
    fp = fopen("README.md", "w");

    fputs("# ", fp);
    fputs(name,fp);

    fclose(fp);
    return;
}

void createMain(enum languages language){
    FILE *fp;
    char* content;
    switch(language){
        case C:
            fp = fopen("src/main.c", "w");
            content = "int main(void){\n}";
            break;
        case Go:
            system("go mod init main");
            fp = fopen("src/main.go", "w");
            
            content = "func main(){\n}";
            break;
        case Js:
            content = "";
            break;
        case Unknown:
            content = "";
            break;
    }

    fputs(content,fp);
    fclose(fp);
    return;
}

/*
char* makeFile(char* language){
    FILE *fp;

    fclose(fp);
    return;

}



void languageSpecific(enum languages language){
    switch(language){
        case C:
        case Go:
            system("go mod init");
    }
}*/
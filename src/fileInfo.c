#include <stdio.h>
#include <stdlib.h>

void createREADME(char* name){
    FILE *fp;
    fp = fopen("README.md", "w");

    fputs("# ", fp);
    fputs(name,fp);

    fclose(fp);
    return;
}

void createMain(char* language){
    FILE *fp;
    char* content;
    if (*language == 'C'){
        fp = fopen("src/main.c", "w");
        content = "int main(void){\n}";
    } else if (*language == 'G') {
        system("go mod init main");
        fp = fopen("src/main.go", "w");
        
        content = "func main(){\n}";
    } else {
        content = "";
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



void languageSpecific(char* language){
    switch(language){
        case 'G':
            system("go mod init");
    }
}*/
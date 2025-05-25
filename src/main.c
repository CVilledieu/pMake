#include <create.h>
#include <options.h>


int main(int argc, char *argv[]) { 
    if (argc < 2){
        printf("%s\n", "No input arguments given");
        return 0;
    }

    return 0;    
}




void createCProject(char * name){

    //create dir with project name
    if (mkdir("./%s", name) != 0){
        printf("Error:\n\t unable to create directory with path:\n\t %s", name);
        exit(1);
    }

    //Change to the project dir
    if(chdir("./%s",name) != 0){
        printf("Error: \n\t unable to switch to project directory.");
        exit(1);
    }

    



}


char* sanitizeName(char* name){
    char* cleanName[MAX_F_NAME];
}
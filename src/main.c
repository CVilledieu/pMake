#include <options.h>


int main(int argc, char *argv[]) { 
    if (argc < 2){
        printf("%s\n", "No input arguments given");
        return 0;
    }
    char* sanatizedName[MAX_F_NAME];
    return 0;    
}



//0 = C, 1 = go, 2 = js, 3 = web
//Languages are parsed in func int parseLang(char *argv[])
void createCProject(char * name, int languageCode){

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

    switch (languageCode) {
        case 0:
            CreateC();
        case 1:
            CreateGo();
        case 2:
            createJs();
        case 3:
            createWeb();
        default:
            CreateBlank();
    }
    

    return;
}


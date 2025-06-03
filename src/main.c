/*

*/
#include <stdlib.h>
#include <stdio.h>
#include <direct.h>

#include <options.h>
#include <createfiles.h>

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
    createEnv();

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


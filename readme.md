# pMake

A simple command that sets up a new project directory and populates it with the core components all projects need.
File structure created:  
```
.
└── Project
    ├── Src
    │   └── main
    ├── Bin
    ├── makefile
    └── .gitignore
```

## How to use  

run `pMake [flags]`  

It is important that pMake is added to the system variables.  
No specific argument is required. If no path or project name is provided, then defaults will be used

## Flags and Options

* `-o [name]` Name of project / name of main dir
* `-l [lang]` To add language specific files
* `-h` Help message

### Currently supported language options

C, Go, Js, and Web

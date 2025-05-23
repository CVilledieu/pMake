#prefix table
#s = src
#

.PHONY: cleanObjs build clean all

CC = GCC
CFLAGS = -Wall

# directories
outDir = ./bin
sDir = ./src

OBJS = main.o

appName = pMake

all: build cleanObjs

build:$(sDir)/$(OBJS)
	$(CC) $^ -o $(outDir)/$(appName)

%.o: %.c
	$(CC) -c $(CFLAGS)  $< -o $@

cleanObjs: 
	rm -rf $(sDir)/*.o

clean: 
	rm -rf $(outDir)/*
	rm -rf $(sDir)/*.o
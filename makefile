#prefix table
#s = src
#

.PHONY: cleanObjs build clean all

CC = GCC
CFLAGS = -Wall $(inc)

# directories
outDir = ./bin
sDir = ./src
inc = -Isrc/include


OBJS = $(wildcard $(sDir)/*.c)
appName = pMake

all: build cleanObjs

build: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(outDir)/$(appName)

%.o: %.c
	$(CC) -c $(CFLAGS)  $< -o $@

cleanObjs: 
	rm -rf $(sDir)/*.o

clean: 
	rm -rf $(outDir)/*
	rm -rf $(sDir)/*.o
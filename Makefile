# Executable
BINFOLDER := bin/
# .hpp
INCFOLDER := inc/
# .cpp
SRCFOLDER := src/
# .o
OBJFOLDER := obj/
CC := g++
CFLAGS := -W -Wall -std=c++17 -pedantic -ggdb
LIBS := -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
INCLUDE_PATH := -I/usr/include/SDL2
SRCFILES := $(wildcard src/*.cpp)
all: $(SRCFILES:src/%.cpp=obj/%.o)
	@ echo 'linking file: $<'
	$(CC) obj/*.o -o bin/gamePenguin $(CFLAGS) $(LIBS)
	@ echo ' '

obj/%.o: src/%.cpp
	@ echo 'compiling: $<'
	$(CC) $(CFLAGS) $(LIBS) -c $< -o $@ -I./inc
	@ echo ' '

run: bin/gamePenguin
	bin/gamePenguin

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*

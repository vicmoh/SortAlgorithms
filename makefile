CC = gcc
CFLAGS = -Wall -pedantic -g -std=c99 -Iinclude
BIN = ./bin/
SRC = ./src/
AST = ./assets/

all: program

program:
	$(CC) $(CFLAGS) $(SRC)main.c $(SRC)functions.c -o $(BIN)runMe

runMe:
	$(BIN)runMe

clean:
	rm $(BIN)runMe
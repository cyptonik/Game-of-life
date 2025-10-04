CC = gcc
FLAGS = -Wall -Werror -Wextra -lncurses
SRC = src/*.c
BUILD = build/

all: clean game

game: $(SRC)
	$(CC) $(FLAGS) $^ -o $(BUILD)game

clean: 
	rm -f game

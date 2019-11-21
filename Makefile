all: game

game: game.o card.o
	cc -o game game.o card.o -L ~/lib

%.o: %.c card.h
    cc -g -c $< -L ~/lib
 
    
clean:
	rm -rf game game.o card.o

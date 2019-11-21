all: game

game: game.o card.o
	cc -o game game.o card.o

%.o: %.c
    cc -c *.c 
 
    
clean:
	rm -rf game game.o card.o

ALL: clean build 

clean:
	- rm card
	- rm card.o
	- rm alphabets.o

build: card

card: card.o alphabets.o
	gcc -g -o card card.o alphabets.o

card.o: card.c
	gcc -g -c card.c -o card.o

alphabets.o: alphabets.c alphabets.h
	gcc -g -c alphabets.c -o alphabets.o

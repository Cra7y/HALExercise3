CC = gcc

all: 
	gcc -o my_formatter my_formatter.c formatter.c txt_formatter.c html_formatter.c



clean:
	rm -f *.o ooc

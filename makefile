all: homework1.c
	gcc -std=c99 -g -pg -o test homework1.c

clean:
	$(RM) test
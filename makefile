all: homework1.c
	gcc -std=c99 -g -pg -O3 -o test homework1.c

clean:
	$(RM) test
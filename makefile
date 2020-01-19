all: homework1.c
	gcc -std=c99 -o test homework1.c

clean:
	$(RM) test
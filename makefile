all: homework1.c
	gcc -o test homework1.c

clean:
	$(RM) test
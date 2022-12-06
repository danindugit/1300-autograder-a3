CC=gcc
CFLAGS=-Wall -std=c99 -lm

autoGrader: a3Autograder.o studentCode.o
	$(CC) $(CFLAGS) studentCode.o a3Autograder.o -o autoGrader
a3Autograder.o:
	 $(CC) $(CFLAGS) -c a3Autograder.c
studentCode.o:
	 $(CC) $(CFLAGS) -c $(a3) -o studentCode.o
clean:
	rm *.o autoGrader 


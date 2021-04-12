C=gcc
CFLAGS= -O3 -Wall -g
#LIBS= -lm
LIBS= 
AR=ar

ALLBIN=s1c1

all: ${ALLBIN}

clean:
	rm -f *.o ${ALLBIN}

s1c1: s1c1.o functions.o
	$(CC) s1c1.o functions.o -o s1c1 ${LIBS}

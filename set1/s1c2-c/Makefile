C=gcc
CFLAGS= -O3 -Wall -g
#LIBS= -lm
LIBS= 
AR=ar

ALLBIN=s1c2

all: ${ALLBIN}

clean:
	rm -f *.o ${ALLBIN}

s1c2: s1c2.o functions.o
	$(CC) s1c2.o functions.o -o s1c2 ${LIBS}

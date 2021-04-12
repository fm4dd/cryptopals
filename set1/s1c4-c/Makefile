C=gcc
CFLAGS= -O3 -Wall -g
#LIBS= -lm
LIBS= 
AR=ar

ALLBIN=s1c4

all: ${ALLBIN}

clean:
	rm -f *.o ${ALLBIN}

s1c4: s1c4.o functions.o
	$(CC) s1c4.o functions.o -o s1c4 ${LIBS}

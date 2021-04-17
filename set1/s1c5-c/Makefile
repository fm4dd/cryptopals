C=gcc
CFLAGS= -O3 -Wall -g
#LIBS= -lm
LIBS= 
AR=ar

ALLBIN=s1c5

all: ${ALLBIN}

clean:
	rm -f *.o ${ALLBIN}

s1c5: s1c5.o functions.o
	$(CC) s1c5.o functions.o -o s1c5 ${LIBS}

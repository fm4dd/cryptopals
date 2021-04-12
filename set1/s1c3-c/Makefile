C=gcc
CFLAGS= -O3 -Wall -g
#LIBS= -lm
LIBS= 
AR=ar

ALLBIN=s1c3

all: ${ALLBIN}

clean:
	rm -f *.o ${ALLBIN}

s1c3: s1c3.o functions.o
	$(CC) s1c3.o functions.o -o s1c3 ${LIBS}

## Cryptopals Set 1 Challenge 4

https://cryptopals.com/sets/1/challenges/4

### Detect single-character XOR

One of the 60-character strings in the source file 4.txt has been encrypted by single-character XOR.

Find it.

(Your code from #3 should help.)

### 'C' Solution

Noticed that in source file 4.txt, one line is 1 char shorter then the rest

Compilation

```
pi@ms01:~/code/cryptopals/set1/s1c4-c$ make
cc -O3 -Wall -g   -c -o s1c4.o s1c4.c
cc -O3 -Wall -g   -c -o functions.o functions.c
cc s1c4.o functions.o -o s1c4 
```

Run

```
pi@ms01:~/code/cryptopals/set1/s1c4-c$ ./s1c4
OK opening the test data file [./4.txt]
The number of keys to test is [62]
The score for string check is [1.40e+00]
The '5' XOR-decoded string is [Now that the party is jumping
] line [170] source [7b5a4215415d544115415d5015455447414c155c46155f4058455c5b523f]
```

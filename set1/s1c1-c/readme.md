## Cryptopals Set 1 Challenge 1

https://cryptopals.com/sets/1/challenges/1

### Convert hex to base64

The string:

```
49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
```

Should produce:

```
SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
```

So go ahead and make that happen. You'll need to use this code for the rest of the exercises.

**Cryptopals Rule:** Always operate on raw bytes, never on encoded strings. Only use hex and base64 for pretty-printing.

### 'C' Solution

Compilation

```
pi@ms01:~/code/cryptopals/set1/s1c1-c$ make
cc -O3 -Wall -g   -c -o s1c1.o s1c1.c
cc -O3 -Wall -g   -c -o functions.o functions.c
cc s1c1.o functions.o -o s1c1
```

Run

```
pi@ms01:~/code/cryptopals/set1/s1c1-c$ ./s1c1 
The source data hex string is [49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d]
The hex string encoded b64 is [SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t]
The expected target string is [SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t]
```

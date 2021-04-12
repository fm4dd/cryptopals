## Cryptopals Set 1 Challenge 3

https://cryptopals.com/sets/1/challenges/3

### Single-byte XOR cipher

The hex encoded string:

```
1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
```

... has been XOR'd against a single character. Find the key, decrypt the message.

You can do this by hand. But don't: write code to do it for you.

How? Devise some method for "scoring" a piece of English plaintext. Character frequency is a good metric. Evaluate each output and choose the one with the best score.

**Achievement Unlocked:** You now have our permission to make "ETAOIN SHRDLU" jokes on Twitter.

### 'C' Solution

Compilation

```
pi@ms01:~/code/cryptopals/set1/s1c3-c$ make
cc -O3 -Wall -g   -c -o s1c3.o s1c3.c
cc -O3 -Wall -g   -c -o functions.o functions.c
cc s1c3.o functions.o -o s1c3 
```

Run

```
pi@ms01:~/code/cryptopals/set1/s1c3-c$ ./s1c3 
The source data hex string is [1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736]
The source data bin string is [7316?x+x413=x9x(7-6<x7>x:9;76] length is [34]
The number of keys to test is [52]
The score for english text is [1.40e+00]
The 'X' XOR-decoded string is [Cooking MC's like a pound of bacon]
```

I cheated a bit by not selecting the best score. I am printing all solutions below a certain score threshold.

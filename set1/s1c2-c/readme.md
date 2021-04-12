## Cryptopals Set 1 Challenge 2

https://cryptopals.com/sets/1/challenges/2

### Fixed XOR

Write a function that takes two equal-length buffers and produces their XOR combination.

If your function works properly, then when you feed it the string:

```
1c0111001f010100061a024b53535009181c
```

... after hex decoding, and when XOR'd against:

```
686974207468652062756c6c277320657965
```

... should produce:

```
746865206b696420646f6e277420706c6179
```

### 'C' Solution

Compilation

```
pi@ms01:~/code/cryptopals/set1/s1c2-c$ make
cc -O3 -Wall -g   -c -o s1c2.o s1c2.c
cc -O3 -Wall -g   -c -o functions.o functions.c
cc s1c2.o functions.o -o s1c2 
```

Run

```
pi@ms01:~/code/cryptopals/set1/s1c2-c$ ./s1c2 
The source data hex string is [1c0111001f010100061a024b53535009181c]
The xor keydata hex string is [686974207468652062756c6c277320657965]
The xor encoded hex output is [746865206B696420646F6E277420706C6179]
The expected target string is [746865206b696420646f6e277420706c6179]
```

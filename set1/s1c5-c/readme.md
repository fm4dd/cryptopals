## Cryptopals Set 1 Challenge 5

https://cryptopals.com/sets/1/challenges/5

### Implement repeating-key XOR

Here is the opening stanza of an important work of the English language:

```
Burning 'em, if you ain't quick and nimble
I go crazy when I hear a cymbal
```

Encrypt it, under the key "ICE", using repeating-key XOR.

In repeating-key XOR, you'll sequentially apply each byte of the key; the first byte of plaintext will be XOR'd against I, the next C, the next E, then I again for the 4th byte, and so on.

It should come out to:

```
0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272
a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f
```

Encrypt a bunch of stuff using your repeating-key XOR function. Encrypt your mail. Encrypt your password file. Your .sig file. Get a feel for it. I promise, we aren't wasting your time with this.

### Solution

Note: I am storing the input text inside a text file 5.txt for easier variation of text later.

Compilation

```
pi@ms01:~/code/c-code/cryptopals/s1c5$ make
cc -O3 -Wall -g   -c -o s1c5.o s1c5.c
cc -O3 -Wall -g   -c -o functions.o functions.c
cc s1c5.o functions.o -o s1c5 
```

Run

```
pi@ms01:~/code/c-code/cryptopals/s1c5$ ./s1c5 
OK opening the test data file [./5.txt]
Using this XOR encryption key [ICE]
The XOR-encoded string length [74]
The XOR-encoded hex string is [0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f]
The expected output hexstring [0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f]
```

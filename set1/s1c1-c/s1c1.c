/* ------------------------------------------------------------ *
 * file:        s1c1.c                                          *
 * purpose:     solution for cryptopals set 1 challenge 1       *
 *                                                              *
 * return:      0 on success, and -1 on errors.                 *
 * example:	./s1c1                                          *
 * author:      04/06/2021 Frank4DD                             *
 * ------------------------------------------------------------ */
#include <string.h>
#include <stdio.h>

size_t hexs2bin(const char *hex, unsigned char **out);
void b64_encode(unsigned char *clrstr, unsigned char *b64dst);

int main(int argc, char *argv[]) {
   char hexstr[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
   char target[] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
   unsigned char *binstr;
   size_t        binlen;
   unsigned char b64str[255];
   /* ---------------------------------------------------------- *
    * convert the hex string to binary first                     *
    * ---------------------------------------------------------- */
   binlen = hexs2bin(hexstr, &binstr);
   /* ---------------------------------------------------------- *
    * convert the binary data into base64 output                 *
    * ---------------------------------------------------------- */
   b64_encode(binstr, b64str);
   printf("The source data hex string is [%s]\n", hexstr);
   printf("The hex string encoded b64 is [%s]\n", b64str);
   printf("The expected target string is [%s]\n", target);
   return(0);
}

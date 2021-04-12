/* ------------------------------------------------------------ *
 * file:        s1c2.c                                          *
 * purpose:     solution for cryptopals set 1 challenge 2       *
 *                                                              *
 * return:      0 on success, and -1 on errors.                 *
 * example:	./s1c2                                          *
 * author:      04/06/2021 Frank4DD                             *
 * ------------------------------------------------------------ */
#include <string.h>
#include <stdio.h>

size_t hexs2bin(const char *hex, unsigned char **out);
unsigned char* bin2hex(const unsigned char *binstr, size_t len);

int main(int argc, char *argv[]) {
   char hexstr[] = "1c0111001f010100061a024b53535009181c";
   char hexkey[] = "686974207468652062756c6c277320657965";
   char target[] = "746865206b696420646f6e277420706c6179";
   unsigned char *binstr;
   size_t         binlen;
   unsigned char *xorkey;
   size_t         keylen;
   unsigned char xorout[255];
   unsigned char *xorstr;
   size_t         outlen = 0;
   /* ---------------------------------------------------------- *
    * convert the hex string to binary array                     *
    * ---------------------------------------------------------- */
   binlen = hexs2bin(hexstr, &binstr);
   /* ---------------------------------------------------------- *
    * convert the xor key string to binary                       *
    * ---------------------------------------------------------- */
   keylen = hexs2bin(hexkey, &xorkey);
   /* ---------------------------------------------------------- *
    * The size of xorout is longest array from binlen or keylen  *
    * here we only check that input and key have the same length *
    * ---------------------------------------------------------- */
    if(binlen == keylen) {
       outlen = binlen;
       int i;
       for(i=0; i<outlen; ++i) {
       /* ------------------------------------------------------ *
        * xor the binary input string with the binary xor key    *
        * ------------------------------------------------------ */
          xorout[i] = (char)(binstr[i] ^ xorkey[i]);
       }
   }

   // xorstr = bin2hex((unsigned char *)binstr, binlen);
   xorstr = bin2hex((unsigned char *)xorout, outlen);
   printf("The source data hex string is [%s]\n", hexstr);
   printf("The xor keydata hex string is [%s]\n", hexkey);
   printf("The xor encoded hex output is [%s]\n", xorstr);
   printf("The expected target string is [%s]\n", target);
   return(0);
}

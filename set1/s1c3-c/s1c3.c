/* ------------------------------------------------------------ *
 * file:        s1c3.c                                          *
 * purpose:     solution for cryptopals set 1 challenge 3       *
 *                                                              *
 * return:      0 on success, and -1 on errors.                 *
 * example:	./s1c3                                          *
 * author:      04/07/2021 Frank4DD                             *
 * ------------------------------------------------------------ */
#include <string.h>         // strlen()
#include <stdio.h>          // printf()

size_t hexs2bin(const char *hex, unsigned char **out);
float scorestring(const unsigned char *string);

int main(int argc, char *argv[]) {
   char hexstr[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
   char hexkey[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   unsigned char *binstr;     // the hex string converted in binary
   size_t         binlen;     // the length of the binary string (strlen doesn't work!)
   float score;               // the score from checking if solution hash english words
   float testscore = 1.4;     // the score to achieve if string is english text
   /* ---------------------------------------------------------- *
    * convert hex string to binary array, return array length    *
    * ---------------------------------------------------------- */
   binlen = hexs2bin(hexstr, &binstr);
   /* ---------------------------------------------------------- *
    * Find the length of the keys array for the decryption loop  *
    * ---------------------------------------------------------- */
   int charlen = strlen(hexkey);
   printf("The source data hex string is [%s]\n", hexstr);
   printf("The source data bin string is [%s] length is [%ld]\n", binstr, binlen);
   printf("The number of keys to test is [%d]\n", charlen);
   printf("The score for english text is [%0.2e]\n", testscore);
   /* ---------------------------------------------------------- *
    * cycle through each char in the alphabet as the XOR key     *
    * ---------------------------------------------------------- */
   for(int i=0; i < charlen; i++) {
      char key = hexkey[i];            // assign the XOR key char
      unsigned char xorout[255];       // the decoded binary string
      /* ------------------------------------------------------- *
       * cycle through each byte in the in string, XOR with char *
       * XOR decryption by aplying another XOR, which reverts it *
       * ------------------------------------------------------- */
      int j;
      for(j=0; j<binlen; j++) {
         xorout[j] = binstr[j] ^ key; // decrypt
      }
      xorout[binlen] = '\0';          // add the string terminator
      // debug: show each of the solutions
      // printf("The XOR decrypted instring is [%s]\n", xorout);
      /* ------------------------------------------------------- *
       * Check the decrypted string for english words            *
       * ------------------------------------------------------- */
      score = scorestring(xorout);
      if(score < testscore) {
         printf("The '%c' XOR-decoded string is [%s]\n", key, xorout);
      }
   }
   return(0);
}

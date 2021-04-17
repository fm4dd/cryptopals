/* ------------------------------------------------------------ *
 * file:        s1c5.c                                          *
 * purpose:     solution for cryptopals set 1 challenge 5       *
 *                                                              *
 * return:      0 on success, and -1 on errors.                 *
 * example:	./s1c5                                          *
 * author:      04/09/2021 Frank4DD                             *
 * ------------------------------------------------------------ */
#include <string.h>          // strlen()
#include <stdio.h>           // printf()
#include <stdlib.h>          // getline()

char *bin2hex(const unsigned char *bin, size_t len);

int main(int argc, char *argv[]) {
   FILE *fp;
   const char *in = "./5.txt";  // the input file with the text to encrypt
   const char *key = "ICE";     // the repeating XOR encryption key
   const char *match = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";
   unsigned char binstr[255];   // the XOR-encrypted string bytes
   char *hexstr;                // the XOR-encrypted string in hex
   /* ---------------------------------------------------------- *
    * Try to open the input file containing the hex string list  *
    * ---------------------------------------------------------- */
   if (! (fp = fopen(in, "r"))) {
      printf("Error: Cant open input file %s for reading.\n", in);
      return -1;
   }
   printf("OK opening the test data file [%s]\n", in);
   printf("Using this XOR encryption key [%s]\n", key);
   /* ---------------------------------------------------------- *
    * Cycle through the file bytes until EOF, encrypting XOR key *
    * ---------------------------------------------------------- */
   int i = 0; int j = 0; int c = 0;
   while (1) {
      c = getc(fp);
      if(c == EOF) break;
      // debug:
      //printf("The character [%d] read from file: [%d]\n", i, c);
      if(j == strlen(key)) j = 0;
      if(i == sizeof(binstr)) break;
      binstr[i] = (unsigned char) c ^ key[j];
      i++; j++;
   }
   fclose(fp);
   /* ---------------------------------------------------------- *
    * If the file has a trailing LF after the text, remove it:   *
    * ---------------------------------------------------------- */
   if(binstr[74] == 79) i--; // if the last char is LINEFEED, ignore

   printf("The XOR-encoded string length [%d]\n", i);
   hexstr = bin2hex(binstr, i);
   printf("The XOR-encoded hex string is [%s]\n", hexstr);
   printf("The expected output hexstring [%s]\n", match);
   return 0;
}

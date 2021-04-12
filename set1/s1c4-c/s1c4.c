/* ------------------------------------------------------------ *
 * file:        s1c4.c                                          *
 * purpose:     solution for cryptopals set 1 challenge 4       *
 *                                                              *
 * return:      0 on success, and -1 on errors.                 *
 * example:	./s1c4                                          *
 * author:      04/08/2021 Frank4DD                             *
 * ------------------------------------------------------------ */
#include <string.h>          // strlen()
#include <stdio.h>           // printf()
#include <stdlib.h>          // getline()

int hex_xor_charcheck(char *hexstr, char *keyset, float testscore, char *solution);

int main(int argc, char *argv[]) {
   FILE *fp;
   const char *in = "./4.txt";// the input file to analyze
   char * line = NULL;        // line data as a string
   ssize_t read;              // bytes read
   size_t len = 0;            // max length limit of the line to read
   char keyset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
   //char keyset[] = "0123456789";
   float testscore = 1.4;     // the score to achieve if string is english text
   char solution[255];        // a successfully decoded string
   /* ---------------------------------------------------------- *
    * Try to open the input file containing the hex string list  *
    * ---------------------------------------------------------- */
   if (! (fp = fopen(in, "r"))) {
      printf("Error: Cant open input file %s for reading.\n", in);
      return -1;
   }
   printf("OK opening the test data file [%s]\n", in);
   int charlen = strlen(keyset);
   printf("The number of keys to test is [%d]\n", charlen);
   printf("The score for string check is [%0.2e]\n", testscore);
   /* ---------------------------------------------------------- *
    * Cycle through the file line by line, extracting hex string *
    * ---------------------------------------------------------- */
   int i = 0;
   while ((read = getline(&line, &len, fp)) != -1) {
      line[strcspn(line, "\n")] = 0; // remove trailing newline
      // printf("The source data hex string is [%s]\n", line);
      int key = hex_xor_charcheck(line, keyset, testscore, solution);
      if(key > 0) printf("The '%c' XOR-decoded string is [%s] line [%d] source [%s]\n", key, solution, i, line);
      i++;
   }
   fclose(fp);
   return 0;
}

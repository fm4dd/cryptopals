/* ---------------------------------------------------------- *
 * functions.c - various helper functions                     *
 * ---------------------------------------------------------- */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------------- *
 * convert one hex character into a 4-bit wide binary string  *
 * ---------------------------------------------------------- */
int hexchr2bin(const char hex, char *out) {
   if (out == NULL) return 0;
   if (hex >= '0' && hex <= '9') *out = hex - '0';
   else if (hex >= 'A' && hex <= 'F') *out = hex - 'A' + 10;
   else if (hex >= 'a' && hex <= 'f') *out = hex - 'a' + 10;
   else return 0;
   return 1;
}

/* ---------------------------------------------------------- *
 * convert the hex string to binary string, returns bin len   *
 * binlen is needed because the bin string could contain \0.  *
 * ---------------------------------------------------------- */
size_t hexs2bin(const char *hex, unsigned char **out) {
  size_t len;
  char   b1;
  char   b2;
  size_t i;

  if (hex == NULL || *hex == '\0' || out == NULL) return 0;
  len = strlen(hex);
  if (len % 2 != 0) return 0;
  len /= 2;

  *out = malloc(len);
  memset(*out, 'A', len);
  for (i=0; i<len; i++) {
      if (!hexchr2bin(hex[i*2], &b1) || !hexchr2bin(hex[i*2+1], &b2)) {
         return 0;
      }
      (*out)[i] = (b1 << 4) | b2;
   }

   return len;
}

/* ---------------------------------------------------------- *
 * ---- Base64 Encoding/Decoding Table ---                    * 
 * ---------------------------------------------------------- */
char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/* ---------------------------------------------------------- *
 * Encode 3x 8-bit binary bytes as 4x '6-bit' characters      * 
 * ---------------------------------------------------------- */
void encodeblock( unsigned char in[], char b64str[], int len ) {
   char out[5];
   out[0] = b64[ in[0] >> 2 ];
   out[1] = b64[ ((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4) ];
   out[2] = (unsigned char) (len > 1 ? b64[ ((in[1] & 0x0f) << 2) |
            ((in[2] & 0xc0) >> 6) ] : '=');
   out[3] = (unsigned char) (len > 2 ? b64[ in[2] & 0x3f ] : '=');
   out[4] = '\0';
   strncat(b64str, out, 5);
}

/* ---------------------------------------------------------- *
 * Encode a byte sequence as base64, add padding if needed    * 
 * ---------------------------------------------------------- */
void b64_encode(char *clrstr, char *b64dst) {
   unsigned char in[3];
   int i, len = 0;
   int j = 0;

   b64dst[0] = '\0';
   while(clrstr[j]) {
      len = 0;
      for(i=0; i<3; i++) {
         in[i] = (unsigned char) clrstr[j];
         if(clrstr[j]) { len++; j++; }
         else in[i] = 0;
      }
      if(len) encodeblock(in, b64dst, len);
   }
}

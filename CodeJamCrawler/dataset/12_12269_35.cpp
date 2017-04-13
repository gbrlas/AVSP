#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include <errno.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>

#define ALPHABET 26
#define MAX_WORDS_PER_LINE (500)

using namespace std;

int main() {
   FILE *in = fopen("in.txt", "r");
//   FILE *in2 = fopen("in2.txt", "r");
   FILE *out = fopen("out.txt", "w");
   
   assert(in != NULL && out != NULL);
   int args;
   
   fscanf(in, "%d\n", &args);
   char *googlerese = "yhesocvxduiglbkrztnwjpfmaq";
   
   for (int TT = 0; TT < args; TT++) {
      char word[MAX_WORDS_PER_LINE];
      memset(word, '\0', MAX_WORDS_PER_LINE);
      char googled[MAX_WORDS_PER_LINE];
      memset(googled, '\0', MAX_WORDS_PER_LINE);

      while (fgets(word,sizeof(word),in) == NULL || strlen(word) == 1) {
         printf("Weird Case %d\n", TT+1);
      }
      
      word[strlen(word)-1] = '\0';
      printf("Test Case %d (strlen: %d)\n", TT+1, strlen(word));
           
      for (int i = 0; i < strlen(word); i++) {
         if (word[i] >= 'a' && word[i] <= 'z') {
            googled[i] = googlerese[word[i]-'a'];
         } else {
            googled[i] = word[i];
         }
      }
      
      fprintf(out, "Case #%d: ", TT+1);
      for (int i = 0; i < strlen(googled); i++) {
         fprintf(out, "%c", googled[i]);
      }
      fprintf(out, "\n");
   }
   
   fclose(in);
   fclose(out);
   
   return EXIT_SUCCESS;
}
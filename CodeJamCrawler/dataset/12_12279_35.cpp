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

#define BUFFER 15
#define CASE_FUN 2000001

using namespace std;


int main() {
   FILE *in = fopen("in.txt", "r");
   FILE *out = fopen("out.txt", "w");
   
   assert(in != NULL && out != NULL);
   int args;
   
   fscanf(in, "%d\n", &args);

   for (int TT = 0; TT < args; TT++) {
      int a,b;
      fscanf(in, "%d%d\n", &a, &b);
      
      int total = 0;
      char test[BUFFER];
      char newBuff[BUFFER];
      memset(test, '\0', BUFFER);
      memset(newBuff, '\0', BUFFER);
      
      for (int T = a; T <= b; T++) {
         sprintf(test, "%d", T);
         
         vector< vector<int> > vec;
         
         for (int i = 0; i < strlen(test) - 1; i++) {
            memcpy(newBuff+1, test, strlen(test)-1);
            memcpy(newBuff, test+strlen(test)-1, 1);
            memcpy(test, newBuff, strlen(test));
            
            int newA;
            sscanf(test, "%d", &newA);
            
            if (a <= T && T < newA && newA <= b) {
               printf("Pair (%d, %d)\n", T, newA);
               total++;
            }
         }
      }
      
      fprintf(out, "Case #%d: %d\n", TT+1, total);
   }
   
   fclose(in);
   fclose(out);
   
   return EXIT_SUCCESS;
}
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

#define EVENTS 3

using namespace std;

int main() {
   FILE *in = fopen("in.txt", "r");
   FILE *out = fopen("out.txt", "w");
   
   assert(in != NULL && out != NULL);
   int args;
   
   fscanf(in, "%d\n", &args);

   for (int TT = 0; TT < args; TT++) {
      int googlers, surprises, minimum;
      fscanf(in, "%d%d%d", &googlers, &surprises, &minimum);
      
      int total = 0;
      
      for (int i = 0; i < googlers; i++) {
         int score, average, remainder;
         fscanf(in, "%d", &(score));
         average = score / EVENTS;
         remainder = score % EVENTS;
         
         if (average >= minimum) {
            total++;
         } else if (average + 1 >= minimum) {
            if (remainder > 0) {
               total++;
            } else if (average - 1 >= 0 && surprises > 0){
               total++;
               surprises--;
            }
         } else if (average + 2 >= minimum) {
            if (remainder == 2 && surprises > 0) {
               total++;
               surprises--;
            }
         }
      }
      
      /*printf("Test case %d\n", TT+1);
      assert(surprises == 0); // wrong otherwise!*/
      
      fscanf(in, "\n");
      fprintf(out, "Case #%d: %d\n", TT+1, total);
   }
   
   fclose(in);
   fclose(out);
   
   return EXIT_SUCCESS;
}
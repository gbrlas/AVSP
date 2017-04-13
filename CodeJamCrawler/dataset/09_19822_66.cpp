#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *input, *output;
   int L, D, N;
   char Dict[5000][16];
   char curr_input[1000];
   int i, j, k, l, no_of_cases;

   input = fopen("A-large.in", "r");
   output = fopen("alienlang.out", "w");

   if (input == 0 || output == 0)
      printf("no files\n");
   
   fscanf(input, "%d %d %d", &L, &D, &N);
   
   i = 0;
   while (i < D) {
      fscanf(input, "%s", Dict[i]);
      i++;
   }

   i = 0;
   while (i < N) {
      fscanf(input, "%s", curr_input);
      
      j = 0;
      no_of_cases = 0;
      while (j < D) {
         k = 0; l = 0;
         while (1) {
            if (curr_input[l] != '(' && curr_input[l] != Dict[j][k])
               break;

            if (curr_input[l] == '(') {
               l++;
               while (curr_input[l] != ')' && curr_input[l] != Dict[j][k])
                  l++;
               if (curr_input[l] == ')') 
                  break;
               if (curr_input[l] == Dict[j][k]) {
                  while (curr_input[l] != ')')
                     l++;
               }
            }

            if (curr_input[l] != ')' && curr_input[l] != Dict[j][k])
               break;

            if (curr_input[l] == '\0') {
               no_of_cases++;
               break;
            }

            l++;
            k++;
         }

         j++;
      }
    
      fprintf(output, "Case #%d: %d\n", i + 1, no_of_cases);
      i++;
   }
}

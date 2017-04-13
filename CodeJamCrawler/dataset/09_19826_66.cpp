#include <stdio.h>

#define SIZE 1000

char next = 'a';

char find_sink(int i, int j, int H, int W, int map[][SIZE], char sink[][SIZE])
{
   int k, l, min, mini, minj;
 
   if (sink[i][j] != '*')
      return sink[i][j];
   
   min = map[i][j];

   k = i + 1; l = j;
   if (((k > -1) && (k < H)) && ((l > -1) && (l < W)) && map[k][l] <= min) {
      min = map[k][l];
      mini = k; minj = l;
   }
   
   k = i; l = j + 1;
   if (((k > -1) && (k < H)) && ((l > -1) && (l < W)) && map[k][l] <= min) {
      min = map[k][l];
      mini = k; minj = l;
   }
 
   k = i; l = j - 1;
   if (((k > -1) && (k < H)) && ((l > -1) && (l < W)) && map[k][l] <= min) {
      min = map[k][l];
      mini = k; minj = l;
   }

   k = i - 1; l = j;
   if (((k > -1) && (k < H)) && ((l > -1) && (l < W)) && map[k][l] <= min) {
      min = map[k][l];
      mini = k; minj = l;
   }

   if (map[i][j] == min)
      sink[i][j] = next++;
   else
      sink[i][j] = find_sink(mini, minj, H, W, map, sink);

   return sink[i][j];
}

int main()
{
   FILE *input, *output;
   int T, H, W;
   int i, j, k;
   int map[SIZE][SIZE];
   char sink[SIZE][SIZE];

   input = fopen("watershed.in", "r");
   output = fopen("watershed.out", "w");

   fscanf(input, "%d", &T);
   
   i = 0;
   while (i < T) {
      for (j = 0; j < SIZE; j++) {
         for (k = 0; k < SIZE; k++) {
            sink[j][k] = '*';
         }
      }
      next = 'a';

      fscanf(input, "%d %d", &H, &W);

      for (j = 0; j < H; j++) {
         for (k = 0; k < W; k++) {
            fscanf(input, "%d", &map[j][k]);
         }
      }

      for (j = 0; j < H; j++){
         for (k = 0; k < W; k++) {
            find_sink(j, k, H, W, map, sink);
         }
      }
      
      fprintf(output, "Case #%d:\n", i + 1);
      for (j = 0; j < H; j++) {
         for (k = 0; k < W; k++) {
            fprintf(output, "%c ", sink[j][k]);
         }
         fprintf(output, "\n");
      }
      
      i++;
   }   
}

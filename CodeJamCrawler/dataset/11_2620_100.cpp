// axc

#include <iostream>
#include <cstdio>
#include <cstdlib>

   using namespace std;

   int main()
   {
      FILE * w = fopen("goro.in", "r");
      FILE * o = fopen("goro.out", "w");
   
      int T;
      fscanf(w, "%d", &T);
      for(int t = 1; t <= T; t++)
      {
         int N;
         fscanf(w, "%d", &N);
         int k = 0;
         for(int i = 1; i <= N; i++)
         {
            int x;
            fscanf(w, "%d", &x);
            if(x != i)
               k++;
         }
         fprintf(o, "Case #%d: %d\n", t, k);
      }
   
      return 0;
   }
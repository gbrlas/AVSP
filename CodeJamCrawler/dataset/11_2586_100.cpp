// axc

#include <iostream>
#include <cstdio>
#include <cstdlib>

   using namespace std;

   int main()
   {
      FILE * w = fopen("bot.in", "r");
      FILE * o = fopen("bot.out", "w");
   
      int T;
      fscanf(w, "%d", &T);
      for(int t = 1; t <= T; t++)
      {
         int N;
         fscanf(w, "%d", &N);
         int olast = 1, blast = 1, otime = 0, btime = 0;
         for(int i = 0; i < N; i++)
         {
            char c[11];
            int b;
            fscanf(w, "%s%d", c, &b); 
            if(c[0] == 'O')
            {
               otime += abs(b - olast);
               olast = b;
               if(otime < btime)
                  otime = btime;
               otime++;
            }
            else
            {
               btime += abs(b - blast);
               blast = b;
               if(btime < otime)
                  btime = otime;
               btime++;
            }
         }
         fprintf(o, "Case #%d: %d\n", t, max(otime, btime));
      }
   
      return 0;
   }
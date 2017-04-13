#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

   using namespace std;

   int path[1111111];

   int main()
   {
      FILE * w = fopen("airport.in", "r");
      FILE * o = fopen("airport.out", "w");
   
      int T;
      fscanf(w, "%d", &T);
      for(int t = 1; t <= T; t++)
      {
         int L, WS, RS, RT, N;
         fscanf(w, "%d%d%d%d%d", &L, &WS, &RS, &RT, &N);
         for(int i = 0; i < L; i++)
            path[i] = WS;
         for(int i = 0; i < N; i++)
         {
            int a, b, c;
            fscanf(w, "%d%d%d", &a, &b, &c);
            for(int j = a; j < b; j++)
               path[j] += c;
         }
         sort(path, path + L);
         long double rt = RT;
         int i = 0;
         long double answer = 0.0, epsilon = 1.0e-8;
         while(i < L)
         {
            if(rt > 0)
            {
               int tempspeed = path[i] - WS + RS;
               if(rt + epsilon > 1.0 / tempspeed)
               {
                  rt -= 1.0 / tempspeed;
                  answer += 1.0 / tempspeed;
               }
               else // run for part of the time
               {
                  int tempspeed = path[i] - WS + RS;
                  long double dist = rt * tempspeed;
                  answer += rt;
                  rt = 0;
                  answer += (1.0 - dist) / path[i];
               }
            }	
            else
               answer += 1.0 / path[i];
            i++;
         }
         fprintf(o, "Case #%d: %.7Lf\n", t, answer);
      }
   
      return 0;
   }
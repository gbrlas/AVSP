// axc

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

   using namespace std;

   int main()
   {
      FILE * w = fopen("candy2.in", "r");
      FILE * o = fopen("candy2.out", "w");
   
      int T;
      fscanf(w, "%d", &T);
      for(int t = 1; t <= T; t++)
      {
         int N;
         fscanf(w, "%d", &N);
         vector<int> v;
         for(int i = 0; i < N; i++)
         {
            int x;
            fscanf(w, "%d", &x);
            v.push_back(x);
         }
         int answer = -1;
         for(int i = 1; i < (1 << N) - 1; i++)
         {
            int total1 = 0, total2 = 0, total3 = 0, total4 = 0;
            for(int j = 0; j < N; j++)
               if(i & (1 << j))
                  total1 ^= v[j], total3 += v[j];
               else
                  total2 ^= v[j], total4 += v[j];
            if(total1 == total2)
               answer = max(answer, max(total3, total4));
         }
         if(answer <= 0)
            fprintf(o, "Case #%d: NO\n", t);
         else
            fprintf(o, "Case #%d: %d\n", t, answer);
      }
   
      return 0;
   }
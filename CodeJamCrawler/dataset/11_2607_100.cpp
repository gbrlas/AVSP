// axc

#include <iostream>
#include <cstdio>
#include <cstdlib>

   using namespace std;

   int dp[2222222], dp2[2222222]; // dp[xor] = actual sum

   int main()
   {
      FILE * w = fopen("candy3.in", "r");
      FILE * o = fopen("candy3.out", "w");
   
      int T;
      fscanf(w, "%d", &T);
      for(int t = 1; t <= T; t++)
      {
      	cout << t << endl;
         for(int i = 0; i <= 1048576; i++)
            dp[i] = dp2[i] = 0;
         int N, total = 0, total2 = 0;
         fscanf(w, "%d", &N);
         for(int i = 0; i < N; i++)
         {
            int x;
            fscanf(w, "%d", &x);
            total2 += x;
            for(int j = 1048576; j >= 0; j--)
               if(dp[j] > 0 && !(i == N - 1 && dp[j] + x >= total2))
                  dp2[j ^ x] = max(dp[j ^ x], dp[j] + x);
            dp2[x] = max(dp[x], x);
            for(int j = 1048576; j >= 0; j--)
               dp[j] = dp2[j];
            total ^= x;
         }
         int answer = 0;
         for(int i = 0; i <= 1048576; i++)
            if((total ^ i) == i)
               answer = max(answer, dp[i]);
         if(answer == 0)
            fprintf(o, "Case #%d: NO\n", 50 + t);
         else
            fprintf(o, "Case #%d: %d\n", 50 + t, answer);
      }
   
      return 0;
   }
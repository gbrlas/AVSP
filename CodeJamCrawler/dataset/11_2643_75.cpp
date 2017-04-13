#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

   using namespace std;

   int N, C, D;
   long double dp[111111], epsilon = 1.0e-8;
   vector<int> pos;

   long double abs(long double x)
   {
      return x < 0 ? -x : x;
   }

   int main()
   {
      FILE * w = fopen("hotdogs.in", "r");
      FILE * o = fopen("hotdogs.out", "w");
   
      int T;
      fscanf(w, "%d", &T);
      for(int t = 1; t <= T; t++)
      {
      	pos.clear();
         cout << "***" << t << "***" << endl;
         fscanf(w, "%d%d", &C, &D);
         cout << C << " " << D << endl;
         for(int i = 0; i < C; i++)
         {
            int a, b;
            fscanf(w, "%d%d", &a, &b);
            for(int j = 0; j < b; j++)
               pos.push_back(a);
         }
         sort(pos.begin(), pos.end());
         N = pos.size();
         cout << N << endl;
      	
      	// binary search on answer
      	long double big = 1.0e12;
         long double low = 0, high = big;
         while(high - low > 1.0e-7)
         {
            long double move = (low + high) / 2.0; // guess
            //cout << "guessing: " << move << endl;
            bool can = true;
            long double last = pos[0] - move;
            //cout << last << endl;
            for(int i = 1; i < N; i++)
            {
            	// move i left as far as possible without exceeding guess or moving too much
               long double next = max(last + D, pos[i] - move);
               if(abs(next - pos[i]) > move + epsilon)
               {
                  can = false;
                  break;
               }
               last = next;
               //cout << last << endl;
            }
            if(can)
               high = move;
            else
               low = move;
         }
         fprintf(o, "Case #%d: %.8Lf\n", t, (low + high) / 2.0);
         cout << (low + high) / 2.0 << endl;
      	
      	if(abs(high - big) < epsilon)
      	{	
      		cout << "FAIL" << endl;
      	}
      }
   
      return 0;
   }
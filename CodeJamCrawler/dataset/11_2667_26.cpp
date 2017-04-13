#include <iostream>
#include <cstdio>
#include <cstdlib>

   using namespace std;

   long double epsilon = 1.0e-8;
   int grid[555][555], R, C, D;

   long double abs(long double x)
   {
      return x < 0 ? -x : x;
   }

   bool eq(long double a, long double b)
   {
      return abs(a - b) < epsilon;
   }

	// (0, 0) is the upper left corner
   bool possible(int r, int c, int d)
   {
      long double cr = r + (long double) d / 2.0;
      long double cc = c + (long double) d / 2.0;
      long double rsum = 0.0, csum = 0;
      for(int i = r; i <= r + d; i++)
         for(int j = c; j <= c + d; j++)
            rsum += (grid[i][j] + D) * (i - cr), csum += (grid[i][j] + D) * (j - cc);
      rsum -= (grid[r][c] + D) * (r - cr);
      rsum -= (grid[r][c + d] + D) * (r - cr);
      rsum -= (grid[r + d][c] + D) * (r + d - cr);
      rsum -= (grid[r + d][c + d] + D) * (r + d - cr);
      csum -= (grid[r][c] + D) * (c - cc);
      csum -= (grid[r][c + d] + D) * (c + d - cc);
      csum -= (grid[r + d][c] + D) * (c - cc);
      csum -= (grid[r + d][c + d] + D) * (c + d - cc);
      return eq(rsum, 0) && eq(csum, 0);
   }

   int main()
   {	
      FILE * w = fopen("blade.in", "r");
      FILE * o = fopen("blade.out", "w");
   
      int T;
      fscanf(w, "%d", &T);
      for(int t = 1; t <= T; t++)
      {
         cout << "***" << t << endl;
         fscanf(w, "%d%d%d", &R, &C, &D);
         for(int r = 1; r <= R; r++)
         {
            char x[555];
            fscanf(w, "%s", x);
            for(int c = 1; c <= C; c++)
               grid[r][c] = x[c - 1] - '0';
         }
         int answer = 0;
         for(int r = 1; r <= R; r++)
            for(int c = 1; c <= C; c++)
               for(int d = max(answer, 2); r + d <= R && c + d <= C; d++)
                  if(possible(r, c, d))
                  {
                     answer = max(answer, d);
                     cout << "\t possible " << r << " " << c << " " << d << endl;
                  }
         if(answer == 0)
            fprintf(o, "Case #%d: IMPOSSIBLE\n", t);
         else
            fprintf(o, "Case #%d: %d\n", t, answer + 1);
      }
   
      return 0;
   }
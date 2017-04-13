#include <iostream>
#include <cstdio>
#include <cstdlib>

   using namespace std;

   char res[111][111];
   long double wp[111], owp[111], oowp[111];
   int ngames[111];

   int main()
   {
      FILE * w = fopen("rpi.in", "r");
      FILE * o = fopen("rpi.out", "w");
   
      int T;
      fscanf(w, "%d", &T);
      for(int t = 1; t <= T; t++)
      {
      	cout << "***" << t << endl;
         fprintf(o, "Case #%d:\n", t);
         int N;
         fscanf(w, "%d", &N);
         for(int i = 0; i < N; i++)
         {
         	ngames[i] = 0;
            fscanf(w, "%s", res[i]);
            for(int j = 0; j < N; j++)
               if(res[i][j] != '.')
                  ngames[i]++;
            cout << i << " " << ngames[i] << endl;
         }
         for(int i = 0; i < N; i++)
         {
            long double wpi = 0.0;
            for(int j = 0; j < N; j++)
               if(res[i][j] == '1')
                  wpi++;
            wpi /= ngames[i];
            wp[i] = wpi;
            cout << i << " " << wp[i] << endl;
         }
         for(int i = 0; i < N; i++)
         {
            long double owpi = 0.0;
            for(int j = 0; j < N; j++)
               if(res[i][j] != '.')
                  owpi += (wp[j] * ngames[j] - (res[j][i] - '0')) / (ngames[j] - 1);
            owpi /= ngames[i];
            owp[i] = owpi;
            cout << i << " " << owp[i] << endl;
         }
         for(int i = 0; i < N; i++)
         {
            long double oowpi = 0.0;
            for(int j = 0; j < N; j++)
               if(res[i][j] != '.')
                  oowpi += owp[j];
            oowpi /= ngames[i];
            oowp[i] = oowpi;
            cout << i << " " << oowp[i] << endl;
         }
         for(int i = 0; i < N; i++)
            fprintf(o, "%.8Lf\n", 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]);
      }
   
      return 0;
   }
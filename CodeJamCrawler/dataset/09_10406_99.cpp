#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

int main()
{
      ifstream fin("C-large.in");
      FILE * fout;
      fout = fopen("C-large.out", "w");
      int N;
      fin >> N;
      string s;
      getline(fin, s);
      string f = "welcome to code jam";
      for (int casenum = 1; casenum <= N; casenum++)
      {
          getline(fin, s);
          int m = s.length();
          int found[m];
          for (int i = 0; i < m; i++)
                  found[i] = 0;
          for (int k = m-1; k >=0; k--)
              if (s[k] == 'm')
                 found[k] = 1;

          for (int n = 17; n >= 0; n--)
          {
              int currtotal = 0;
              for (int k = m-1; k >=0; k--)
              {
                  if (s[k] == f[n])
                     found[k] = currtotal;
                  else if (s[k] == f[n+1])
                       currtotal = (currtotal + found[k]) % 10000;
              }
          }

          int ans = 0;
          for (int k = 0; k < m; k++)
              if (s[k] == 'w')
                 ans = (ans + found[k]) % 10000;

          fprintf(fout, "Case #%d: %04d\n", casenum, ans);

      }
      fclose(fout);
      return 0;
}

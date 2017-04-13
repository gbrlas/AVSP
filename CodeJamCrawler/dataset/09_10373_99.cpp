#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

int main()
{
      ifstream fin("A-small.in");
      ofstream fout("A-small.out");
      int L, D, N, K;
      string s;
      vector<string> v;
      vector<string> dict;
      fin >> L >> D >> N;
      for (int w = 0; w < D; w++)
      {
          fin >> s;
          dict.push_back(s);
      }
      for (int i = 1; i <= N; i++)
      {
          v.clear();
          fin >> s;
          int start = 0;
          K = 0;
          bool br = false;
          for (int j = 0; j < s.length(); j++)
          {
             if (s[j] == '(')
             {
                start = j;
                br = true;
             }
             else if (s[j] == ')')
             {
                br = false;
                v.push_back(s.substr(start+1, j-start+1));
             }
             else if (!br)
                  v.push_back(string(1, s[j]));
          }

          for (int k = 0; k < D; k++)
          {
              bool poss = true;
              for (int m = 0; m < v.size(); m++)
              {
                  poss = false;
                  for (int let = 0; let < v[m].length(); let++)
                  {
                      if (v[m][let] == dict[k][m])
                      {
                         poss = true;
                         break;
                      }
                  }
                  if (!poss)
                     break;
              }
              if (poss)
                 K++;
          }

          fout << "Case #" << i << ": " << K << endl;
      }
      return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

int main()
{
      ifstream fin("B-small.in");
      ofstream fout("B-small.out");

      int T;
      fin >> T;
      for (int casenum = 1; casenum <= T; casenum++)
      {
          int H, W;
          fin >> H >> W;
          char grid[H+2][W+2];
          int alt[H+2][W+2];
          char dir[H+2][W+2];
          queue<int> q;
          char curr = 'A';
          for (int i = 1; i <= H; i++)
          {
              for (int j = 1; j <= W; j++)
              {
                  fin >> alt[i][j];
                  grid[i][j] = '#';
              }
          }
          for (int i = 0; i < H + 2; i++)
          {
              grid[i][0] = '@';
              grid[i][W+1] = '@';
              alt[i][0] = 20000;
              alt[i][W+1] = 20000;
              dir[i][0] = 'L';
              dir[i][W+1] = 'R';
          }
          for (int j = 0; j < W + 2; j++)
          {
              grid[0][j] = '@';
              grid[H+1][j] = '@';
              alt[0][j] = 20000;
              alt[H+1][j] = 20000;
              dir[0][j] = 'U';
              dir[H+1][j] = 'D';
          }
          for (int i = 1; i <= H; i++)
          {
              for (int j = 1; j <= W; j++)
              {
                  int minalt = alt[i][j];
                  int minx = 0, miny = 0;
                  for (int x = -1; x <= 1; x++)
                  {
                      for (int y = -1; y <= 1; y++)
                      {
                          if (abs(x-y) == 1)
                          {
                             if (alt[i+x][j+y] < minalt)
                             {
                                minalt = alt[i+x][j+y];
                                minx = x;
                                miny = y;
                             }
                          }
                      }
                  }
                  if (minx == 0 && miny == 0)
                     dir[i][j] = 'S';
                  else if (minx == -1 && miny == 0)
                       dir[i][j] = 'U';
                  else if (minx == 0 && miny == -1)
                       dir[i][j] = 'L';
                  else if (minx == 0 && miny == 1)
                       dir[i][j] = 'R';
                  else
                      dir[i][j] = 'D';
              }
          }

          for (int i = 1; i <= H; i++)
          {
              for (int j = 1; j <= W; j++)
              {
                   if (dir[i][j] == 'S')
                   {
                      q.push((W+2)*i + j);
                      while (!q.empty())
                      {
                         int x = q.front();
                         q.pop();
                         int y = x % (W+2);
                         x = x / (W+2);
                         grid[x][y] = curr;
                         cout << x << ' ' << y << endl;
                         if (dir[x-1][y] == 'D')
                             q.push((W+2)*(x-1) + y);
                         if (dir[x+1][y] == 'U')
                             q.push((W+2)*(x+1) + y);
                         if (dir[x][y-1] == 'R')
                             q.push((W+2)*x + (y-1));
                         if (dir[x][y+1] == 'L')
                             q.push((W+2)*x + (y+1));
                      }
                      curr++;
                   }
              }
          }
          char small[26];
          char currsmall = 'a';
          for (int k = 0; k < 26; k++)
              small[k] = '#';
          for (int i = 1; i <= H; i++)
          {
              for (int j = 1; j <= W; j++)
              {
                  if (small[grid[i][j] - 'A'] == '#')
                  {
                     small[grid[i][j] - 'A'] = currsmall;
                     currsmall++;
                  }
                  grid[i][j] = small[grid[i][j]-'A'];
              }
          }

          fout << "Case #" << casenum << ":" << endl;
          for (int i = 1; i <= H; i++)
          {
              fout << grid[i][1];
              for (int j = 2; j <= W; j++)
                  fout << ' ' << grid[i][j];
              fout << endl;
          }
      }
      return 0;
}

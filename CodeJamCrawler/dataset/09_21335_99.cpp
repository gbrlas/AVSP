#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

#define sz(c) ((int) (c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MAXH 105
#define MAXW 105

const int DI[] = {+1, 0, 0, -1};
const int DJ[] = {0, +1, -1, 0};

int T, H, W;
pair < int, int > adj[MAXH][MAXW][4];
int d[MAXH][MAXW], f[MAXH][MAXW], a[MAXH][MAXW];
bool b[MAXH][MAXW];
char res[MAXH][MAXW];
char let[MAXH * MAXW];

void go(int i, int j, int k)
{
   f[i][j] = k;
   for (int l = 0; l < d[i][j]; l++)
      go(adj[i][j][l].fi, adj[i][j][l].se, k);
}

int main()
{
   scanf("%d", &T);
   for (int tt = 0; tt < T; tt++)
   {
      scanf("%d%d", &H, &W);
      for (int i = 0; i < H; i++)
         for (int j = 0; j < W; j++)
            scanf("%d", &a[i][j]);
      memset(d, 0, sizeof(d));
      memset(b, 0, sizeof(b));
      for (int i = 0; i < H; i++)
         for (int j = 0; j < W; j++)
         {
            int mi = -1, mj = -1;
            for (int k = 0; k < 4; k++)
            {
               int ii = i + DI[k];
               int jj = j + DJ[k];
               if (ii >= 0 && jj >= 0 && ii < H && jj < W && a[ii][jj] < a[i][j])
                  if (mi == -1 || a[ii][jj] <= a[mi][mj])
                  {
                     mi = ii;
                     mj = jj;
                  }
            }
            if (mi != -1)
               adj[mi][mj][d[mi][mj]++] = mp(i, j);
            else
               b[i][j] = true;
         }
      int k = 0;
      for (int i = 0; i < H; i++)
         for (int j = 0; j < W; j++)
            if (b[i][j])
               go(i, j, ++k);
      char cur = 'a';
      memset(let, 0, sizeof(let));
      printf("Case #%d:\n", tt + 1);
      for (int i = 0; i < H; i++)
      {
         for (int j = 0; j < W; j++)
         {
            if (!let[f[i][j]])
               let[f[i][j]] = cur++;
            if (j)
               printf(" ");
            printf("%c", let[f[i][j]]);
         }
         puts("");
      }
   }
   return 0;
}

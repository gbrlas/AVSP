#include <iostream>
#include <string>
using namespace std;

const int mo = 10007;

const int maxn = 101;

int n, m, r;
int c[maxn][maxn];
int f[maxn][maxn];

int main()
{
   freopen("D-small-attempt0.in", "r", stdin);
   freopen("a.out", "w", stdout);
   int T;
   cin >> T;
   for (int t = 1; t <= T; t++) { 
       memset(c, 0, sizeof(c));
       cin >> n >> m >> r;
       for (int i = 1; i <= r; i++) {
           int x, y;
           cin >> x >> y;
           c[x][y] = 1;
       }
       f[1][1] = 1;
       for (int i = 1; i <= n; i++)
         for (int j = 1; j <= m; j++) {
             if (i == 1 && j == 1) continue;
             if (c[i][j]) { f[i][j] = 0;continue; }
             f[i][j] = 0;
             if (i - 2 > 0 && j - 1 > 0) f[i][j] =  (f[i][j] + f[i - 2][j - 1]) % mo;
             if (i - 1 > 0 && j - 2 > 0) f[i][j] =  (f[i][j] + f[i - 1][j - 2]) % mo;
         }
       cout << "Case #" << t << ": " << f[n][m] << endl;
   }

 //  while (1);
   return 0;
}

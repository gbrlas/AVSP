#include <iostream>
#include <string>
using namespace std;

const int maxn = 11;
int res;
int n, m;

int w;
int c[maxn][maxn];
int f[maxn][1024];

bool ok(int s1, int s2, int row)
{
     int a[11], b[11];
     memset(a, 0, sizeof(a));
     memset(b, 0, sizeof(b));
     w = 0;
     for (int i = 0; i < m; i++) if (s1 & (1 << i)) { a[i + 1] = 1; w++; }
     for (int i = 0; i < m; i++) if (s2 & (1 << i)) b[i + 1] = 1;
     for (int i = 1; i <= m; i++) if (a[i] == 1 && c[row][i] == 0) return 0;
  //   for (int i = 1; i <= m; i++) if (a[i] == 1 && b[i] == 1) return 0;
     for (int i = 2; i <= m; i++) if (a[i] == 1 && a[i - 1] == 1) return 0;
     for (int i = 2; i <= m; i++) if (a[i] == 1 && b[i - 1] == 1) return 0;
     for (int i = 1; i <= m - 1; i++) if (a[i] == 1 && b[i + 1] == 1) return 0;
     return 1;
     
}

void solve()
{
     memset(f, -1, sizeof(f));
     f[0][0] = 0;
     for (int i = 1; i <= n; i++)
         for (int k = 0; k < (1 << m); k++) if (f[i - 1][k] >= 0) {
             for (int j = 0; j < (1 << m); j++) if (ok(j, k, i)) {
                  f[i][j] = max(f[i][j], f[i - 1][k] + w);
             }
           
       }
     int res = 0;
     for (int i = 0; i < (1 << m); i++) res = max(res, f[n][i]);
     cout << res << endl;
     
}

int main()
{
   freopen("C-small-attempt0.in", "r", stdin);
   freopen("c.out", "w", stdout);
   int T;
   scanf("%d\n", &T);
   for (int t = 1; t <= T; t++) { 
       scanf("%d%d\n", &n, &m);
       for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= m; j++) {
             char ch;
             scanf("%c", &ch);
             if (ch == '.') c[i][j] = 1; else c[i][j] = 0;
//             printf("%d", c[i][j]);
         }
         scanf("\n");
  //       printf("\n");
       }
       cout << "Case #" << t << ": ";
       
       solve();
   }

 //  while (1);
   return 0;
}

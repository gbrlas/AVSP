#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int dy[] = {1, 1, 1, -1, -1, -1};
const int dx[] = {-1, 0, 1, 1, 0, -1};

const int maxn = 81;
int res;

int N, M;
int n, m;
int v[3201];
int cx[3201], cy[3201];
vector<int> linkx[3201], linky[3201];

int c[maxn][maxn], id[maxn][maxn];

int check(int x, int y)
{
    if (x <= 0) return 0;
    if (y <= 0) return 0;
    if (x > N) return 0;
    if (y > M) return 0;
    if (c[x][y] == 0) return 0;
    return 1;
}

void create()
{
    n = 0; m = 0;
    for (int i = 1; i <= M; i++) {
        if (i % 2 == 1) {
             for (int j = 1; j <= N; j++) if (c[j][i] == 1) {
                 n++;
                 id[j][i] = n;
             }
        }
        if (i % 2 == 0) {
              for (int j = 1; j <= N; j++) if (c[j][i] == 1) {
                  m++;
                  id[j][i] = m;
              }
        }
    }     
    for (int i = 1; i <= n; i++) linkx[i].clear();
    for (int i = 1; i <= m; i++) linky[i].clear();
    
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++) if (c[i][j] == 1) {
          int id1 = id[i][j];
          for (int k = 0; k <= 5; k++) {
              int x = i + dx[k], y = j + dy[k];
              if (!check(x, y)) continue;
              int id2 = id[x][y];
              if (j % 2 == 1) linkx[id1].push_back(id2);
              else linky[id1].push_back(id2);
          }   
      }
       
}

int path(int i)
{
   int len = linkx[i].size();
    for (int k = 0; k < len; k++) {
      int j = linkx[i][k];
      if ((!v[j]))
      {
        v[j] = 1;
        if ((!cy[j])||(path(cy[j])))
       {
         cx[i] = j;
         cy[j] = i;
         return 1;
       }
       }
  }
  return 0;
}

int match()
{
    int ans = 0;
    memset(cx, 0, sizeof(cx));
    memset(cy, 0, sizeof(cy));
    for (int i = 1; i <= n; i++) {
       int len = linkx[i].size();
       for (int k = 0; k < len; k++) {
             int j = linkx[i][k];
            if ((!cx[i])&&(!cy[j])) cx[i] = j, cy[j] = i, ans++;
       }
    }
    
    for (int i = 1; i <= n; i++) if (!cx[i]) {
        for (int j = 1; j <= m; j++) v[i] = 0;
        if (path(i)) ans++;
    }
    return ans;   
}


void solve()
{
     cout << n + m - match() << endl;
}

int main()
{
   freopen("c.in", "r", stdin);
 //  freopen("c.out", "w", stdout);
   int T;
   scanf("%d\n", &T);
   for (int t = 1; t <= T; t++) { 
       scanf("%d%d\n", &N, &M);
       for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= M; j++) {
             char ch;
             scanf("%c", &ch);
             if (ch == '.') c[i][j] = 1; else c[i][j] = 0;
//             printf("%d", c[i][j]);
         }
         scanf("\n");
  //       printf("\n");
       }
       cout << "Case #" << t << ": ";
       create();
       solve();
       cout << n << " " << m << endl;
   }

   //while (1);
   return 0;
}

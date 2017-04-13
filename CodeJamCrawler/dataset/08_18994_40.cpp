#include <iostream>
#include <string>
using namespace std;

const int INF = 1000000000;

int n, m;
int b[1000][1000];
int min1 = INF;
int res[10000], a[10000];

void check()
{
   int v[101];
   memset(v, 0, sizeof(v));
   for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) if (b[i][j] == a[j]) v[i] = 1;
   for (int i = 1; i <= m; i++) if (v[i] == 0) return;
   int now = 0;
   for (int i = 1; i <= n; i++) if (a[i] == 1) now++;
   if (now < min1) {
           min1 = now;
           for (int i = 1; i <= n; i++) res[i] = a[i];
   }
}

void search(int d)
{
    for (int i = 0; i <= 1; i++) {
        a[d] = i;
        if (d < n) search(d + 1); else check();
    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        min1 = INF;
        cin >> n;
        cin >> m;
        memset(b, -1, sizeof(b));
        for (int i = 1; i <= m; i++) {
            int num;
            cin >> num;
            for (int j = 1; j <= num; j++) {
                int x, y;
                cin >> x >> y;
                b[i][x] = y;
            }
        }
        search(1);
        cout << "Case #" << t << ": ";
        if (min1 == INF) cout << "IMPOSSIBLE"; else {
                  for (int i = 1; i <= n - 1; i++) cout << res[i] << " ";
                  cout << res[n];
        }
        cout << endl;
    }        
        
   // while (1);
    return 0;
}

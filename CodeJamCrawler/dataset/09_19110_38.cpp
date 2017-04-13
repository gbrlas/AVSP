#include <iostream>
using namespace std;

int n, m;
int a[21], b[21], v[21];
int ans;

void check()
{
     int c[1001];
     for (int i = 1; i <= m; i++) c[i] = a[b[i]];
     int vv[1001];
     memset(vv, 0, sizeof(vv));
     int now = 0;
     for (int i = 1; i <= m; i++) {
         vv[c[i]] = 1;
         int j = c[i] - 1;
         while (j > 0 && vv[j] == 0) {
               now++;
               j--;
         }
         j = c[i] + 1;
         while (j <= n && vv[j] == 0) {
               now++;
               j++;
         }
 //      if (i == 2)  cout << now << endl;
//       if (i == 2) while (1);
     } 
//     if (now == 23) cout << c[1] << " " << c[2] << " " << c[3] << endl;
     ans = min(ans, now);
}

void search(int d)
{
     for (int i= 1; i <= m; i++) if (!v[i]) {
         b[d] = i;
         v[i] = 1;
         if (d < m) search(d + 1); else check();
         v[i] = 0;
     }
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        ans = 100000000;
        cout << "Case #" << t << ": ";
        cin >> n;
        cin >> m;
        for (int i = 1; i <= m; i++) cin >> a[i];
        memset(v, 0, sizeof(v));
        search(1);
        cout << ans << endl;
    }
//    while (1);
    return 0;
}

#include<iostream>
#include <map>
using namespace std;

const int maxn = 101;
const int maxm = 1001;

int n, m;
int v[maxn];
map<string, int> f;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t; 
    for (int T = 1; T <= t; T++) {
          int total = 0;
          int ans = 0;
          cin >> n;
          scanf("%\n");
          int s = 0;
          for (int i = 1; i <= n; i++) {
              string s;
              getline(cin, s);     
              f[s] = i;   
          }
          
          cin >> m;
          scanf("%\n");
          memset(v, 0, sizeof(v)); total = 0;
          for (int i = 1; i <= m; i++) {
             string s;
             getline(cin, s);
             int id = f[s];
             if (v[id] == 0 && total == n - 1) {
                      ans++;
                      memset(v, 0, sizeof(v)); 
                      total = 1;
                      v[id] = 1;
             } else {
                if (v[id] == 0) {
                         total++;
                         v[id] = 1; }
                         
             }
          }
          cout << "Case #" << T << ": ";
          cout << ans << endl;
    }
//    while (1);
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 2
4
abcabcabcabc
3
abcabcabcabc
*/

int res;
int m;
string s, ss;
int n;

int a[20], v[20];

void check()
{
    // for (int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << endl;
    // getchar();
     int pos = 0;
     char c[1001], b[1001];
     string ss;
     ss = s;
     while (pos < m) {
           int now = pos;
           for (int i = 1; i <= n; i++) {
               c[i] = s[now];
               now++;
           }
           for (int i = 1; i <= n; i++) b[i] = c[a[i]];
           now = pos;
           for (int i = 1; i <= n; i++) {
               s[now] = b[i];
               now++;
           }
           pos = pos + n;
     }
     int w = 1;
     for (int i = 1; i < m; i++) if (s[i] != s[i - 1]) w++;
     res = min(res, w);
     s = ss;
}

void search(int d)
{
     for (int i = 1; i <= n; i++) if (!v[i]) {
         v[i] = 1;
         a[d] = i;
         if (d < n) search(d + 1); else check();
         v[i] = 0;
     }
         
}

int main()
{
   //freopen("input.txt", "r", stdin);
//    freopen("D-large.in", "r", stdin);
   freopen("D-small-attempt4.in", "r", stdin);    
    freopen("d.out", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) { 
        cin >> n;
        cin >> s;
        m = s.length();
        res = 100000;
        memset(v, 0, sizeof(v));
        search(1);              
     //   cout << n << " " << m << " " ;  
        cout << "Case #" << test << ": "; 
        cout << res << endl;
        
    }
  //  while (1);
    return 0;
}

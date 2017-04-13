#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, A;

int main()
{
//    freopen("input.txt", "r", stdin);
 //   freopen("B-large.in", "r", stdin);
    freopen("B-small-attempt2.in", "r", stdin);    
    freopen("b.out", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) { 
        cout << "Case #" << test << ": "; 
        cin >> n >> m >> A;
        int x1, y1, x2, y2, x3, y3;
        x1 = 0; y1 = 0;
        int have = 0;
        for (x2 = 1; x2 <= n; x2++) {
          for (y2 = 0; y2 <= m; y2++)  {
             for (x3 = 0; x3 <= n; x3++) {
                 int w = A + x3 * y2;
                 if (w % x2 == 0) {
                       y3 = w / x2;
                       if (y3 >= 0 && y3 <= m) {
//                              cout << w << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
                              have = 1; break;
                               }
                 }
                 if (have) break;
             }
             if (have) break;
             }
             if (have) break;
             }
        if (!have) cout << "IMPOSSIBLE" << endl;
        else cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;

    }
  //  while (1);
    return 0;
}

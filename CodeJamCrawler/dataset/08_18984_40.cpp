#include <iostream>
#include <string>
using namespace std;

int n;
long long a[1000], b[1000];

int main()
{
   freopen("A-small-attempt0.in", "r", stdin);
   freopen("a.out", "w", stdout);
   int T;
   cin >> T;
   for (int t = 1; t <= T; t++) {
       long long res = 0;
       cin >> n;
       for (int i = 1; i <= n; i++) cin >> a[i];
       for (int i = 1; i <= n; i++) cin >> b[i];
       sort(a + 1, a + n + 1);
       sort(b + 1, b + n + 1);
       for (int i = 1; i <= n; i++) res = res + a[i] * b[n - i + 1];   
       cout << "Case #" << t << ": " << res << endl;
   }

  // while (1);
   return 0;
}

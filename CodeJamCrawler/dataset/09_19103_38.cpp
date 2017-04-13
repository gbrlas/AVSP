#include <iostream>
#include <set>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("asmall.out", "w", stdout);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        cout << "Case #" << t << ": ";
        set<char> ff;
        string number;
        cin >> number;
        int n = number.size();
        for (int i = 0; i < n; i++) ff.insert(number[i]);
        long long w = max(2, (int)ff.size());
        int v[150];
        memset(v, -1, sizeof(v));
        int ww[150];
        memset(ww, 0, sizeof(ww));
        long long a[101];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)  {
            if (v[number[i]] >= 0) a[i] = v[number[i]]; else {
                             int start;
               if (i == 0) start = 1; else start = 0;
               while (ww[start]) start++;
               ww[start] = 1;
               v[number[i]] = start;
               a[i] = v[number[i]];
            }
        }
        long long res = 0;
        for (int i = 0; i < n; i++) res = res * w + a[i];
        cout << res << endl;
    }
//    while (1);
    return 0;
}

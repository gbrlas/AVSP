#include <set>
#include <map>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

int sum, Min, s, n, T;
    
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    cin >> T;
    for (int TT = 1; TT <= T; TT ++)
    {
        printf("Case #%d: ", TT);
        cin >> n;
        sum = s = 0, Min = 1 << 20;
        for (int i = 1; i <= n; i ++)
        {
            int x;
            cin >> x;
            sum ^= x;
            s += x;
            Min = min(Min, x);
        }
        if (sum)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << s - Min << endl;
    }
    return 0;
}

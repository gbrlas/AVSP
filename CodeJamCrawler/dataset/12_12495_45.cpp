#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t, a, b;

int pd(int e)
{
    int check[11];
    int k, w = e, q = e, ans1 = 0, x = 10;
    if ((q > 0) && (q < 10)) k = 1;
    if ((q > 9) && (q < 100)) k = 10;
    if ((q > 99) && (q < 1000)) k = 100;
    if ((q > 999) && (q < 10000)) k = 1000;
    if ((q > 9999) && (q < 100000)) k = 10000;
    if ((q > 99999) && (q < 1000000)) k = 100000;
    if ((q > 999999) && (q < 10000000)) k = 1000000;
    while (k > 1){
        q = w;
        q %= k;
        q = q * x + w / k;
        if ((q > w) && (q <= b)) check[++ ans1] = q;
        x *= 10;
        k /= 10;
    }
    q = ans1;
    for (int i = 1;i <= ans1; i ++)
        for (int j = i + 1; j <= ans1; j ++)
            if (check[i] == check[j]) q --;
    //if (ans1 != 0) cout << e << " " << ans1 << endl;
    return q;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    cin >> t;
    for (int r = 1; r <= t; r ++)
    {
        cin >> a >> b;
        int ans = 0;
        for (int i = a; i <= b; i ++)
            ans += pd(i);
        cout << "Case #" << r << ": " << ans << endl;
    }
    return 0;
}

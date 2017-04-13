#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
#include <stdio.h>
#include <math.h>
using namespace std;

long long v[512];
long long p[512];
long long n, d;

bool check(double LEN)
{
    double left = -1e15;
    for(int i = 0; i < n; i++)
    {
        if(left < p[i] - LEN)
            left = p[i] - LEN;
        if(left + (v[i] - 1) * d > p[i] + LEN + 1e-10)
            return false;
        left += v[i] * d;
    }
    return true;
}

void solve()
{
    cin >> n >> d;
    long long minP = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> p[i] >> v[i];
        minP = (minP < p[i]) ? minP : p[i];
    }
    for(int i = 0; i < n; i++)
    {
        p[i] -= minP;
    }
    double L = 0;
    double R = 1e15;
    while(fabs(R - L) > 1e-10)
    {
        double c = (L + R) / 2.0;
        if(check(c))
            R = c;
        else
            L = c;
    }
    printf("%.8lf", R);
}

int main()
{
    freopen("/home/bellnox/input.txt", "r", stdin);
    freopen("/home/bellnox/output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cout << "Case #" << (i + 1) << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
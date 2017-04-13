#include <iostream>
#include <cstring>
#include <set>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <queue>
#define mod  747474747
using namespace std;
int dp[1002];
bool p[1002];
bool palin (int x)
{
    int y,a=x;
    y = 0;
    while (x != 0) {
        y = y*10 + (x%10);
        x = x/10;
    }
    if (a == y) {
        return true;
    }
    return false;
}

void pp()
{
    int i;
    for (i = 0; i <= 1000; i++) {
        p[i] = false;
    }
    for (i = 1; i <= 31; i++) {
        if (palin (i) && palin (i*i)) {
            p[i*i] = true;
        }
    }
    for (i = 0; i <= 1000; i++) {
        if (i == 0) {
            dp[i] = 0;
        } else {
            dp[i] = dp[i-1];
        }
        if (p[i]) {
            dp[i]++;
        }
    }

}

int main()
{
    pp();
    int t,ii,a,b;
    ii = 1;
freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;

    while (t--) {
        cin >> a >> b;
        cout << "Case #" << ii << ": ";
        ii++;
        cout << dp[b]-dp[a-1]<< endl;
    }
    return 0;
}

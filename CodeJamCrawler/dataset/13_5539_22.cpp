#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#define mod 10000000007

using namespace std;
int n;
int a[1000003];
int dp[2090][2090];
int fun (int value, int index)
{
    if (index == n) {
        return 0;
    }
    int &result = dp[value][index];
    if (result != -1) {
        return result;
    }
    result = 1000000;
    if (value > a[index]) {
        result = fun (a[index]+value, index+1);
        return result;
    }
    result = 1 + fun (value, index+1);
    result = min (result, 1 + fun (2*value - 1, index));
    return result;
}

 int main()
{
    freopen("ii.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j,aa,ii=1;
    cin >> t;
    while (t--) {
        cin >> aa >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort (a, a+n);
        for (i = 0; i < 2090; i++) {
            for (j = 0; j < 2090; j++) {
                dp[i][j] = -1;
            }
        }
        cout << "Case #" << ii << ": ";
        ii++;
        cout << fun (aa, 0) << endl;
    }
    return 0;
}

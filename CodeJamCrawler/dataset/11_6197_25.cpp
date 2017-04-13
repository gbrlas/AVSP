#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main()
{

    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    int a, tmp;
    for(int i = 0; i < t; ++i) {
        cin >> a;
        int xr;
        long long sum = 0;
        int min = 10000*10000;
        for(int j = 0; j < a; ++j) {
            cin >> tmp;
            if(j == 0)
                xr = tmp;
            else
                xr = xr ^ tmp;
            if(tmp < min)
                min = tmp;
            sum += tmp;
        }
        cout << "Case #" << i + 1 << ": ";
        if(xr != 0)
            cout << "NO" << endl;
        else
            cout << sum - min << endl;
    }
    return 0;
}

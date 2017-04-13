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
set <long long int> s;
bool palin (long long int x)
{
    long long int a=x,b=0;
    while (x != 0) {
        b = b*10 + (x%10);
        x = x/10;
    }
    if (a == b) {
        return true;
    }
    return false;
}
int main()
{
    long long int t,ii,i,n,m;
    ii = 1;
    for (i = 1; i <= 10000000; i++) {
        if (palin (i) && palin (i*i)) {
            s.insert (i*i);
        }
    }

    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;

    while (t--) {
       cin >> n >> m;

        cout << "Case #" << ii << ": ";
        ii++;
        long long int sum = 0;
        set <long long int> :: iterator it;
        for (it = s.begin(); it != s.end(); it++) {
            if ((*it) < n) {
                continue;
            }
            if ((*it) > m) {
                break;
            }
            sum++;
        }
        cout << sum << endl;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>
#define mod 10000000007

using namespace std;
long long int n,flag;
long long int a[1000003];
map <pair <int, int>, int> m;
long long int fun (long long int value, long long int index)
{

    if (index == n) {
        return 0;
    }
    pair <int, int> p (value, index);
    if (m.find (p) != m.end()) {
        return m[p];
    }
    m[p] = 1000000;
    long long int result;
    long long int xx=0;
    result = 1000000;
    if (value > a[index]) {
        result = fun (a[index]+value, index+1);
        m[p] = result;
        return result;
    }
    result = 1 + fun (value, index+1);

    result = min (result, 1 + fun (2*value - 1, index));
    m[p] = result;
    return result;
}

int main()
{
    flag = 0;
    freopen("ii.in","r",stdin);
    freopen("out.txt","w",stdout);
    long long int t,i,j,aa,ii=1;
    cin >> t;
    while (t--) {
        cin >> aa >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort (a, a+n);
        m.clear();
        cout << "Case #" << ii << ": ";
        ii++;
        cout << fun (aa, 0) << endl;
    }
    return 0;
}

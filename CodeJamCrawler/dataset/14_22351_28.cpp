#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
                   
using namespace std;
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long

int main() {
    int n;
    int f[50];
    f[1]=1;
    f[2]=1;
    for (int i=3; i<=41; i++) f[i]=f[i-1]+f[i-2];
    while (cin >> n) {
        int ans=0;
        for (int i=1; i<=n; i++) ans+=f[i];
        cout << ans << endl;
    }
    return 0;
}

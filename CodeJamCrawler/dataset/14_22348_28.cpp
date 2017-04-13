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

ll powmod(int a,int b,int mod) {
    if (b==1) return a%mod;
    if (b%2==0) {
        ll tmp=powmod(a,b/2,mod);
        return (tmp*tmp)%mod;
    }
    else {
        ll tmp=powmod(a,(b-1)/2,mod);
        return (((ll)(a%mod)*tmp*tmp))%mod;
    }
}

int main() {
    int n,m,k;
    while (cin >> n >> m >> k) {
        int x,ans=0;
        for (int i=0; i<n; i++) {
            cin >> x;
            if (powmod(x,m,k)==0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

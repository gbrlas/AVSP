#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <ctype.h>
using namespace std;

typedef long long LL;
typedef long double LD;
const int inf=1000000000, N=100+5;
const double eps=1e-10;

LL unlucky(LL n, LL p) {
    LL l=1, r=1LL<<n;
    while (l<r) {
        LL mid=(l+r+1)>>1;
        LL ans=0, tmp=mid-1;
        for (int j=1; j<=n; j++) {
            if (!tmp) {
                ans<<=1;
            } else {
                ans<<=1;
                ans+=1;
                tmp-=1;
                tmp>>=1;
            }
        }
        if (ans+1<=p)
            l=mid;
        else
            r=mid-1;
    }
    return l-1;
}

LL lucky(LL n, LL p) {
    LL l=1, r=1LL<<n;
    while (l<r) {
        LL mid=(l+r+1)>>1;
        LL ans=0, tmp=(1LL<<n)-mid;
        for (int j=1; j<=n; j++) {
            if (!tmp) {
                ans<<=1;
                ans+=1;
            } else {
                ans<<=1;
                tmp-=1;
                tmp>>=1;
            }
        }
        if (ans+1<=p)
            l=mid;
        else
            r=mid-1;
    }
    return l-1;
}

int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int total;
    cin>>total;
    for (int t=1; t<=total; t++) {
        LL n, p;
        cin>>n>>p;
        cout<<"Case #"<<t<<": "<<unlucky(n, p)<<" "<<lucky(n, p)<<endl;
    }
    return 0;
}

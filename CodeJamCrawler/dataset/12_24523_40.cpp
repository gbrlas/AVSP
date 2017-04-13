#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORN(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int Free[10001110];

int main() {
    freopen("c.inp","r",stdin);
    freopen("c.out","w",stdout);
    int _;
    cin >> _;
    int cnt=0;
    long long pow[100];
    pow[0]=1;
    FOR(i,1,15) pow[i]=pow[i-1]*10;
    FOR(test,1,_) {
        int a,b;
        cin >> a >> b;
        long long s[20];
        s[0]=0;
        int res=0;
        FOR(u,a,b) {
            int n=u,scs=0;
            while (n>0) s[++scs]=n % 10,n/=10;
            FOR(i,1,scs) s[i+scs]=s[i];
            long long tmp=1;
            FOR(i,2,2*scs) tmp*=10,s[i]=s[i-1]+tmp*s[i];
            cnt++;
            FOR(i,scs,2*scs-1) {
                int v=(s[i]-s[i-scs])/pow[i-scs];
                if (Free[v]==cnt) continue;
                Free[v]=cnt;
                if (u<v && a<=v && v<=b) res++;
            }
        }
        cout << "Case #"<<test <<": "<<res << endl;
    }
}

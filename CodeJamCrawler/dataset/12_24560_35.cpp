//Written by technolt
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define DOWN(i,a,b) for(int i = a; i >= b; i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define maxn 11111

int d[maxn],f[maxn],l[maxn],n,D;

int main() {
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    int numtest;
    cin >> numtest;
    FOR(test,1,numtest) {
        cout << "Case #" << test << ": ";
        cin >> n;
        FOR(i,1,n) scanf("%d%d",&d[i],&l[i]);
        cin >> D;
        d[n+1]=D;
        memset(f,-1,sizeof(f));
        f[1]=min(l[1],d[1]);
        FOR(i,1,n+1) {
            FOR(j,i+1,n+1) {
                if (d[j]-d[i]<=f[i]) {
//                    cout << min(d[j]-d[i],l[j]) <<endl;
                    f[j]=max(f[j],min(d[j]-d[i],l[j]));
                }
            }
//            cout << f[i] << " ";
        }
        if (f[n+1]!=-1) cout<<"YES\n";
        else cout <<"NO\n";
        cerr << test << endl;
    }
	return 0;
}

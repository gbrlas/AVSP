#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define DEC(i,k) for (int i=(k); i>=0; --i)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

int B;
set<int> st[8];

int dfs(int target, int upper) {
    //cout<<target<<","<<upper<<endl;
    if (target<0) return 0;
    if (target==0) return 1;
    int res=0;
    for (int j=upper; j>0; --j) {
        vector<int> v;
        int u=j;
        for (; u>0; ) {
            v.push_back(u%B);
            u/=B;
        }
        REP(k,SZ(v)) {
            if (FIND(st[k], v[k])) goto NEXT;
        }
        REP(k,SZ(v)) {
            st[k].insert(v[k]);
        }
        res+=dfs(target-j,j-1);
        REP(k,SZ(v)) {
            set<int>::iterator it=st[k].find( v[k] );
            st[k].erase( it );
        }
NEXT:;
    }
    return res;
}

int main()
{
    int T;
    cin>>T;
    while (T--) {
        static int test=1;
        printf("Case #%d: ",test++);
        int N;
        cin>>N>>B;
        REP(j,8) st[j].clear();

        printf("%d\n",dfs(N,N));
    }
}

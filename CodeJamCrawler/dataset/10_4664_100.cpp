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

int main()
{
    int T;
    cin>>T;
    while (T--) {
        ll L,P,C;
        cin>>L>>P>>C;
        ll n=0, cur=P;
        while (cur>C*L) {
            cur=(cur+C-1)/C;
            ++n;
        }
        ll res=0;
        for (; n>((1LL<<res)-1); ++res);
        static int test=1;
        printf("Case #%d: %lld\n",test++,res);
    }
}


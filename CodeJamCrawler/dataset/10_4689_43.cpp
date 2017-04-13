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

int M[1<<11], cost[1<<11];
bool buy[1<<11];

int main()
{
    int T;
    cin>>T;
    while (T--) {
        int P; cin>>P;
        REP(j,1<<P) cin>>M[j];
        DEC(lv,P-1) REP(j,1<<lv) cin>>cost[(1<<lv)+j];

        MEMSET(buy,false);
        REP(j,1<<P) {
            int mu=P-M[j], cur=1, inf=0, sup=(1<<P)-1;
            REP(k,mu) {
                buy[cur]=true;
                int mid=(inf+sup)/2;
                if (inf<=j&&j<=mid) {
                    sup=mid;
                    cur=cur<<1;
                } else {
                    inf=mid+1;
                    cur=(cur<<1)|1;
                }
            }
        }
        int res=0;
        REP(j,1<<P) if (buy[j]) res+=cost[j];
        static int test=1;
        printf("Case #%d: %d\n",test++,res);
    }
}

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

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define DEC(i,k) for (int i=(k); i>=0; --i)

typedef long long Int;

const double EPS = 1e-9;
const double PI = acos(-1.0);

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

Int v[1002];
Int g[1002], c[1002];
int visited[1002], costed[1002];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        static int test=1;
        printf("Case #%d: ",test++);
        Int R,K,N;
        scanf("%lld%lld%lld",&R,&K,&N);
        REP(j,N) scanf("%lld",&v[j]);
        Int sum=0;
        REP(j,N) sum+=v[j];
        if (sum<=K) {
            printf("%lld\n",sum*R);
            continue;
        }
        REP(j,N) {
            for (Int s=v[j],k=1; ; ++k) {
                Int prev=s;
                s+=v[(j+k)%N];
                if (s>K) {
                    g[j]=(j+k)%N;
                    c[j]=K-prev;
                    break;
                }
            }
        }
        MEMSET(visited,-1);
        Int total=0;
        for (Int id=0,t=0; t<R; ) {
            if (visited[id]>=0) {
                Int rest=R-t;
                Int e=t-visited[id];
                total+=(rest/e)*(total-costed[id]);
                t+=(rest/e)*e;
                MEMSET(visited,-1);
            }
            else {
                costed[id]=total;
                visited[id]=t;
                total+=c[id];
                id=g[id];
                ++t;
            }
            //cout<<t<<"=>"<<total<<endl;
        }
        printf("%lld\n",K*R-total);
    }
}


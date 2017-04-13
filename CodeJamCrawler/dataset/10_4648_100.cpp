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
        int N;
        cin>>N;
        vector<int> v(N),w(N);
        REP(j,N) cin>>v[j]>>w[j];
        int res=0;
        REP(j,N) {
            REP(k,j) {
                if ((v[j]-v[k])*(w[j]-w[k])<0) res++;
            }
        }
        static int test=1;
        printf("Case #%d: %d\n",test++,res);
    }
}


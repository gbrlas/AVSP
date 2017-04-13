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
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);
        int C,D; scanf("%d%d", &C, &D);
        vector<int> pos;
        REP(j, C) {
            int V, P; scanf("%d%d", &V, &P);
            REP(itr, P) pos.push_back(V);
        }
        sort(pos.begin(), pos.end());

            // binary search
        double lo=0.0, hi=1e10;
        REP(itr, 100) {
            double mid=(lo+hi)/2.0;
            bool success=true;
            double lh=-1e10;
            REP(j, SZ(pos)) {
                if (pos[j]+mid < lh+D) { success=false; break; }
                lh=max(lh+D, pos[j]-mid);
            }
            if (success) hi=mid;
            else lo=mid;
        }
        printf("%.14f\n", lo);
    }
}

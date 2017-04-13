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

void solve() {
    int X, S, R, T, N; scanf("%d%d%d%d%d", &X, &S, &R, &T, &N);
    vector<pair<int,int> > vp;

    int rest=X;
    REP(i, N) { int b,e,w; scanf("%d%d%d", &b, &e, &w); vp.push_back(make_pair(w+S, e-b)); rest-=e-b; }
    vp.push_back(make_pair(S, rest));

    sort(vp.begin(), vp.end());
    double delta = R-S;

        // greedy sol
    double runt = T, res = 0;
    FORIT(it, vp) {
        double len = it->second, speed = it->first;
        double curt = len / (speed + delta);

        if (runt - curt < 0) {
            res += runt;
            len -= runt*(speed+delta);
            runt = 0;
            res += len / speed;
        } else {
                // all run
            runt -= curt;
            res += curt;
        }
    }

    printf("%.13f\n", res);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);
        solve();
    }
}

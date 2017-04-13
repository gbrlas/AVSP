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

typedef vector<int> V;
int N, M;
vector<V> vg;

int neigh[420];

struct P { int id, dist; };
int dist[420];

int res1, res2;
vector<int> lg;
int temp[420];
void dfs(int id, int depth, int last) {
    //if (dist[id] != depth) return; // ???
    if (depth == res1) {
        if (id != last) return;
            // count threatenining planets
        MEMSET(temp, 0);
        REP(j, SZ(lg)) {
            int n=lg[j];
            FORIT(it, vg[n]) temp[*it]=1;
        }
        REP(j, SZ(lg)) {
            int n=lg[j];
            temp[n]=0;
        }

        int cnt=0;
        REP(j, N) if (temp[j]) cnt++;

        res2 = max(res2, cnt);
        return;
    }

    FORIT(it, vg[id]) if (dist[*it] == depth+1) {
        lg.push_back(*it);
        dfs(*it, depth+1, last);
        lg.pop_back();
    }
}

void solve() {
    scanf("%d%d", &N, &M);
    vg = vector<V>(N);
    MEMSET(neigh, 0);
    REP(itr, M) {
        int x,y; scanf("%d,%d", &x, &y);
        vg[x].push_back(y);
        vg[y].push_back(x);
        if (x==1 || y==1) neigh[x] = neigh[y] = 1;
    }

    if (neigh[0]) { // edge case
        printf("0 %d\n", SZ(vg[0]));
        return;
    }

    res1=666, res2=0;
    FORIT(it, vg[1]) { // AI's home
        int last = *it;
            // BFS
        queue<P> q;
        MEMSET(dist, -1);
        q.push( (P){0, 0} );
        while (!q.empty()) {
            P p=q.front(); q.pop();
            if (dist[p.id] != -1) continue;
            dist[p.id] = p.dist;

            FORIT(jt, vg[p.id]) {
                if (neigh[*jt] && *jt != last) continue; // impossible
                q.push( (P){*jt, p.dist+1} );
            }
        }

        if (dist[last] == -1 || res1 < dist[last]) continue; // invalid last selection

        if (dist[last] < res1) { res1 = dist[last]; res2 = 0; }
        lg.clear();
        lg.push_back(0);
        dfs(0, 0, last);
    }

    printf("%d %d\n", res1, res2);
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

#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 2000000000;
#define REP(i, n) for(int i = 0;i<(n);i++)
#define ALL(u) (u).begin(),(u).end()

typedef pair<int,int> PI;
typedef long long LL;

struct event {
    int type, t, cnt;
    event(int _type, int _t, int _cnt) {
        type = _type;
        t = _t;
        cnt = _cnt;
    }
    bool operator<(const event & a) const {
        if (t != a.t) {
            return t < a.t;
        }
        return type < a.type;
    }
};

LL fsq(LL t) {
    return ((t * (t + 1)) - 1) / 2;
}

LL cost(LL count, LL dur, LL N) {
    return count * (fsq(N) - fsq(N - dur));
}

void solve(int cas) {
    int N, M;
    cin >> N >> M;
    vector <event> V;
    LL orig = 0;
    REP(i, M) {
        int o, e, cnt;
        cin >> o >> e >> cnt;
        V.push_back(event(0, o, cnt));
        V.push_back(event(1, e, cnt));
        orig += cost(cnt, e - o, N);
    }
    sort(ALL(V));
    vector <PI> tickets;
    int first = 0;
    LL res = 0;
    for(int i = 0;i<V.size();i++) {
        event top = V[i];
        if (top.type == 0) {
            tickets.push_back(PI(V[i].t, V[i].cnt));
        }
        else {
            while(top.cnt > 0 and first < tickets.size()) {
                int used = min(tickets.back().second, top.cnt);
                tickets.back().second -= used;
                top.cnt -= used;
                res += cost(used, top.t - tickets.back().first, N);
                if (tickets.back().second == 0) tickets.pop_back();
            }
        }
    }
    cout << "Case #" << cas << ": " << orig - res << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1;i<=T;i++) solve(i);
    return 0;
}


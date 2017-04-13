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

typedef long long LL;
typedef pair<LL,LL> PI;
typedef vector <int> VI;

void calcinc(vector <int> &tab, vector <int> &res) {
    vector <int> help;
    REP(i, tab.size()) {
        int pos = lower_bound(ALL(help), tab[i]) - help.begin();
        if (help.size() == pos) {
            help.push_back(tab[i]);
        }
        help[pos] = tab[i];
        res[i] = help.size();
    }
}

template <typename T>
ostream & operator<<(ostream & out, vector <T> &in) {
    out << "[";
    REP(i, in.size()) {
        out << in[i] << " ";
    }
    out << "]";
    return out;
}

bool gen(VI &A, VI &B, VI &res, int val, int limit) {
    if (val > limit) return true;
    //cout << val << endl;
    VI inc(res.size(), INF);
    calcinc(res, inc);
    VI dec(res.size(), INF);
    reverse(ALL(res));
    calcinc(res, dec);
    reverse(ALL(res));
    reverse(ALL(dec));
    //cout << inc << endl;
    //cout << dec << endl;
    for(int i = 0;i<A.size();i++) {
        if (A[i] == inc[i] and B[i] == dec[i] and res[i] == INF) {
            res[i] = val;
            //cout << res << endl;
            if (gen(A, B, res, val+1, limit)) {
                return true;
            }
            res[i] = INF;
        }
    }
    return false;
}

void solve(int cas) {
    int N;
    cin >> N;
    vector <int> A(N, 0);
    vector <int> B(N, 0);
    REP(i, N) {
        int val;
        cin >> val;
        A[i] = val;
    }
    REP(i, N) {
        int val;
        cin >> val;
        B[i] = val;
    }
    vector <int> res(N, INF);
    gen(A, B, res, 1, N);
    cout << "Case #" << cas << ":";
    REP(i, res.size()) cout << " " << res[i];
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1;i<=T;i++) solve(i);
    return 0;
}


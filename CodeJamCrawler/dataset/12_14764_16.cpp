#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

bool calc(vector<ll>& s, int d, vector<ll>& l, vector<ll>& r, ll& u, ll& v) {
    if(!l.empty() && !r.empty() && u == v) {
        assert(accumulate(l.begin(), l.end(), 0LL) == u);
        assert(accumulate(r.begin(), r.end(), 0LL) == v);
        cout << endl; for(int i = 0; i < l.size(); ++i) cout << (i == 0 ? "" : " ") << l[i];
        cout << endl; for(int i = 0; i < r.size(); ++i) cout << (i == 0 ? "" : " ") << r[i];
        return true;
    }
    if(d == s.size()) return false;
    ll t = s[d];
    l.push_back(t);
    u += t;
    if(calc(s, d+1, l, r, u, v)) return true;
    l.pop_back();
    u -= t;

    if(!l.empty()) {
        r.push_back(t);
        v += t;
        if(calc(s, d+1, l, r, u, v)) return true;
        r.pop_back();
        v -= t;
    }

    if(calc(s, d+1, l, r, u, v)) return true;

    return false;
}

int main(void) {
    int T, N;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        vector<ll> s;
        cin >> N;
        for(int j = 0; j < N; ++j) {
            ll t; 
            cin >> t;
            s.push_back(t);
        }
        vector<ll> l, r;
        ll u = 0, v = 0;
        if(calc(s, 0, l, r, u, v) == false) cout << "\nImpossible";
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

ll price(ll n, ll a, ll b) {
    return (2 * n + a - b + 1) * (b - a) / 2;
}

int main() {
    int t;
    cin>>t;
    for (int tt = 1; tt <= t; ++tt) {
        cout<<"Case #"<<tt<<": ";
        ll n, m;
        cin>>n>>m;
        ll md = 1000002013;
        ll tot = 0;
        map< ll, pair< vector< ll >, vector< ll > > > mp;
        set< ll > st;
        for (int i = 0; i < m; ++i) {
            ll o, e, p;
            cin>>o>>e>>p;
            tot = (tot + (price(n, o, e) % md * p % md)) % md;
            st.insert(o);
            st.insert(e);
            mp[o].first.push_back(p);
            mp[e].second.push_back(p);
        }
        vector< ll > stops(st.begin(), st.end());
        sort(stops.begin(), stops.end());
        stack< pair< ll, ll > > pool;
        ll ans = 0;
        for (int i = 0; i < stops.size(); ++i) {
            ll cur = stops[i];
            for (vector< ll >::iterator pi = mp[cur].first.begin(); pi != mp[cur].first.end(); ++pi) {
                pool.push(make_pair(cur, *pi));
            }
            for (vector< ll >::iterator pi = mp[cur].second.begin(); pi != mp[cur].second.end(); ++pi) {
                ll ct = *pi;
                while (ct) {
                    ll ls = pool.top().first;
                    ll lc = pool.top().second;
                    pool.pop();
                    ll subs = min(ct, lc);
                    ans = (ans + (price(n, ls, cur) % md * subs % md)) % md;
                    lc -= subs;
                    ct -= subs;
                    if (lc) {
                        pool.push(make_pair(ls, lc));
                    }
                }
            }
        }
        ans = (2 * md + tot - ans) % md;
        cout<<ans<<endl;
    }
    return 0;
}


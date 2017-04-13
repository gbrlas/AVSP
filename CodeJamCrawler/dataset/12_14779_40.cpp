#include<iostream>
#include<deque>
#include<numeric>
#include<algorithm>
#include<cassert>
using namespace std;
typedef long long ll;
struct pair_t {
    ll dur;
    int type;
};
ll dfs(deque<pair_t> a, deque<pair_t> b) {
    //cout << "a "; for(int i = 0; i < a.size(); ++i) cout << a[i].dur << " " << a[i].type << endl;
    //cout << "b "; for(int i = 0; i < b.size(); ++i) cout << b[i].dur << " " << b[i].type << endl;
    if(a.empty() || b.empty()) return 0LL;
    ll r = 0LL, d = 0LL;
    if(a.front().type == b.front().type) {
        bool f = false, g = false;
        ll dur = min(a.front().dur, b.front().dur);
        a.front().dur -= dur;   
        if(a.front().dur == 0LL){
            a.pop_front();
            f = true;
        }
        b.front().dur -= dur;   
        if(b.front().dur == 0LL){
            b.pop_front();
            g = true;
        }
        r += dur;
        if(f || g)
            return r + dfs(a, b);
    }
    if(a.empty() || b.empty()) return r;
    deque<pair_t> x(a), y(b);
    x.pop_front();
    d = max(d, dfs(x, y));
    //cout << "  " << r << " " << d << endl;
    x = a;
    y.pop_front();
    d = max(d, dfs(x, y));
    //cout << r << " " << d << endl;
    return r + d;
}
int main(void){
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        int N, M;
        cin >> N >> M;
        deque<pair_t> a(N), b(M);
        for(int j = 0; j < N; ++j) cin >> a[j].dur >> a[j].type;
        for(int j = 0; j < M; ++j) cin >> b[j].dur >> b[j].type;
        cout << dfs(a, b) << endl;
    }
    return 0;
}

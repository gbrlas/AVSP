#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>


using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

void solve() {
    bool rev = false;

    int n, W, L;
    cin >> n >> W >> L;
    vector<pair<int, int> > r(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        r.pb(mp(x, i));
    }
    sort(all(r));
    reverse(all(r));

    if (L > W) {
        swap(L, W);
        rev = true;
    }

    vector <pair<int, int> > res;
    int xmax = 0;
    int ymax = 0;
    int xnow = 0;
    int ind = 0;
    while (true) {
        if (ind >= n) break;
        int d = r[ind].first;
        int y = 0;
        if (ymax > 0) {
            y = ymax + d;
        }
        if (y > L) {
            xnow = xmax + d;
            xmax = xnow + d;
            ymax = 0;
            y = 0;
        }
        res.pb(mp(xnow, y));
        ymax = y + d;
        xmax = max(xmax, xnow + d);
        ++ind;
    }
    assert(sz(res) == n);

    vi x_ans(n);
    vi y_ans(n);

    for (int i = 0; i < n; ++i) {
        int x = res[i].first;
        int y = res[i].second;
        if (rev) {
            swap(x, y);
        }
        int ind = r[i].second;
        x_ans[ind] = x;
        y_ans[ind] = y;
    }
    for (int i = 0; i < n; ++i) {
        cout << x_ans[i] << " " << y_ans[i] << " ";
    }

    cout << endl;
}


int main () {
    //freopen("", "rt", stdin);
    //freopen("", "wt", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cerr << t << endl;
        printf("Case #%d: ", t + 1);
        solve();
    }

    return 0;
}


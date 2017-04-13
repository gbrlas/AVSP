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


vi rs(int a1, int a2, int a3) {
    vi ans;
    ans.pb(a1);
    ans.pb(a2);
    ans.pb(a3);
    return ans;
}

vi get_surprise(int x) {
    for (int a = 0; a < 10; ++a) {
        for (int b = a; b <= a + 2; ++b) {
            if (a + a + 2 + b == x) return rs(a + 2, a, b);
        }
    }
    return rs(-1, -1, -1);
}


void solve() {
    int n, x, p;
    cin >> n >> x >> p;
    vi s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int now = s[i];
        if ((now / 3) + (now % 3 != 0)>= p) ++ans;
        else {
            if (x == 0) continue;
            int pos = get_surprise(now)[0];
            if (pos <= 10 && pos >= p) {
                ++ans;
                --x;
            }
        }
    }
    cout << ans << endl;
}


int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        printf("Case #%d: ", t + 1);
        solve();
    }

    return 0;
}


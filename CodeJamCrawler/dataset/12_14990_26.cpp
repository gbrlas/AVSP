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

const int nx =  10010;

char dp[nx][nx];
int D;

vi d;
vi l;



char go_dp(int i, int j) {
    // cout << "go_dp" << i << " " << j << endl;
    if (dp[i][j] >= 0) return dp[i][j];

    int delta = min(l[j], d[j] - d[i]);
    int last = d[j] + delta;
    if (last >= D) return 1;
    char ans = 0;
    for (int st = j + 1; st < sz(d); ++st) {
        if (d[st] > last) break;
        if (go_dp(j, st)) {
            ans = 1;
            break;
        }
    }
    dp[i][j] = ans;
    return ans;
}


void solve() {
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    ++n;

    d.resize(n);
    l.resize(n);
    d[0] = 0;
    l[0] = 0;
    for (int i = 1; i < n; ++i) {
        cin >> d[i];
        cin >> l[i];
    }

    cin >> D;
    char ans = go_dp(0, 1);
    if (ans == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
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


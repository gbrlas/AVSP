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


int to_int(string s) {
    return atoi(s.c_str());
}

void solve() {
    string sa, sb;
    cin >> sa >> sb;
    int n = sz(sa);
    int mul = 1;
    for (int i = 1; i < n; ++i) {
        mul *= 10;
    }
    //cout << " mul = " << mul << endl;

    int a = to_int(sa);
    int b = to_int(sb);

    int64 ans = 0;
    for (int i = a; i <= b; ++i) {
        int now = i;
        set < int > nums;
        //cout << "i = " << i << endl;
        for (int j = 0; j < n; ++j) {
            now = mul * (now % 10) + now / 10;
            //cout << "now = " << now << endl;
            if (i < now && now <= b) {
                nums.insert(now);
            }
        }
        ans += sz(nums);
    }
    cout << ans << endl;
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


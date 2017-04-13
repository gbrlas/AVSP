#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b)      for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b)     for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c)   for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c)          (c).begin(),(c).end()
#define TRACE(x)        cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x)        cerr << #x << " = " << x << endl;
#define eprintf(...)    fprintf(stderr, __VA_ARGS__)

typedef long long               ll;
typedef long double             ld;
typedef unsigned long           ulong;
typedef unsigned long long      ull;
typedef vector<int>             VI;
typedef vector<vector<int> >    VVI;
typedef vector<char>            VC;

bool win(const vector<string> &v, char c) {
    bool ans = false;
    REP(i,4) {
        bool xok = true, yok = true;
        REP(j,4) {
            if (v[i][j] != c && v[i][j] != 'T')
                xok = false;
            if (v[j][i] != c && v[j][i] != 'T')
                yok = false;
        }
        ans |= xok || yok;
    }
    bool lok = true;
    bool rok = true;
    REP(i,4) {
        if (v[i][i] != c && v[i][i] != 'T')
            lok = false;
        if (v[i][3-i] != c && v[i][3-i] != 'T')
            rok = false;
    }
    return ans || lok || rok;
}

int main() {
    //freopen("input",  "r", stdin);
    //freopen("output", "w", stdout);
    int TN;
    vector<string> v(4);
    string ans;
    scanf("%d", &TN);
    FOR(TI,1,TN) {
	    bool anydots = false;
	    REP(i,4) {
            cin >> v[i];
            REP(j,4)
	            if (v[i][j] == '.')
		            anydots = true;
	    }
        bool xwins = win(v, 'X');
        bool owins = win(v, 'O');
        if (xwins)
	        if (owins) {
		        cerr << "Case #" << TI << " is IMPOSSIBLE" << endl;
                ans = "Draw";
	        } else
                ans = "X won";
        else if (owins)
            ans = "O won";
        else if (anydots)
            ans = "Game has not completed";
        else
	        ans = "Draw";
        cout << "Case #" << TI << ": " << ans << endl;
    }
    return 0;
}

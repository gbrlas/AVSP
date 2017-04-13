#if 1
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <sstream>
#include <iostream>
#include <bitset>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int , int> pii;
typedef vector <int> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbgv(x) {cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "a"

bool solve(int test)
{
    int r1, r2;
    vector<int> a1(4), a2(4);
    cin >> r1;
    r1 --;
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
        {
            int x;
            if (i == r1)
                cin >> a1[j];
            else
                cin >> x;
        }
    cin >> r2;
    r2 --;
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
        {
            int x;
            if (i == r2)
                cin >> a2[j];
            else
                cin >> x;
        }
    vector<int> res;
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
            if (a1[i] == a2[j])
                res.pb(a1[i]);
    if (res.size() == 0)
        cout << "Case #" << test << ": Volunteer cheated!\n";
    else if (res.size() > 1)
        cout << "Case #" << test << ": Bad magician!\n";
    else
        cout << "Case #" << test << ": " << res[0] << endl;
    return true;


}


int main()
{
    //freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    freopen(NAME ".in","r",stdin);freopen(NAME ".out","w",stdout);
    int z;
    cin >> z;
    for (int t = 0; t < z; ++ t)
        solve(t + 1);

    return 0;
}
/*************************
*************************/
#endif

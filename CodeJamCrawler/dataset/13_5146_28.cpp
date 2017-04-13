#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

#define x               first
#define y               second

using namespace std;

const int MaxM = 1100;
const long long Mod = 1000002013ll;

int n, m;
vector<pair<long long, long long> > s;
long long Ans;
map<long long, long long> Pool;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("A-small-attempt1.in.txt", "r", stdin);
	freopen("A-small-attempt1.out.txt", "w", stdout);
	#endif
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        s.clear();
        Pool.clear();
        Ans = 0;
        cin >> n >> m;
        long long x, y, z;
        for (int i = 1; i <= m; ++i)
        {
            cin >> x >> y >> z;
            Ans += z*(2*n+x-y+1)*(y-x)/2;
            Ans %= Mod;
            s.push_back(make_pair(x, -z));
            s.push_back(make_pair(y, z));
        }
        sort(s.begin(), s.end());
        long long d, k;
        for (int i = 0; i < s.size(); ++i)
            if (s[i].y < 0)
                Pool[-s[i].x] -= s[i].y;
            else
            {
                for (k = s[i].y; Pool.size() && Pool.begin() -> y <= k; Pool.erase(Pool.begin()))
                {
                    d = s[i].x+Pool.begin() -> x;
                    Ans -= (n*2-d+1)*d/2*Pool.begin() -> y;
                    k -= Pool.begin() -> y;
                }
                if (k && Pool.size())
                {
                    d = s[i].x+Pool.begin() -> x;
                    Ans -= (n*2-d+1)*d/2*k;
                    Pool[Pool.begin() -> x] -= k;
                }
                Ans %= Mod;
            }
        Ans = (Ans % Mod+Mod) % Mod;
        cout << "Case #" << Test << ": " << Ans << endl;
    }
	return 0;
}

#include <cfloat>
#include <climits>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <complex>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
string s, r;
vector <int> vi;

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int __cases;
    cin >> __cases;
    for (int __cs = 1; __cs <= __cases; ++ __cs)
    {
        cin >> k >> s;
        n = s.size();
        r.resize(n);
        vi.resize(k);
        for (int i = 0; i < k; ++ i)
            vi[i] = i;
        int ans = n;
        do
        {
            int t = 1;
            for (int i = 0; i < n; ++ i)
                r[i] = s[vi[i % k] + i - i % k];
            for (int i = 1; i < n; ++ i)
                if (r[i] != r[i - 1]) ++ t;
            ans = min(ans, t);
        } while (next_permutation(vi.begin(), vi.end()));
        cout << "Case #" << __cs << ": " << ans << endl;
    }
    return 0;
}

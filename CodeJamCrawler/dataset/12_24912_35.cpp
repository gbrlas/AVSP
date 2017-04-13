#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

#define FOR(i,n) for (int i = 0; i < (n); i++)
#define FORTO(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,n) for (int i = (n)-1; i >= 0; i--)

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;
#define SIZE(x) int(x.size())

typedef pair<int, int> PII;
typedef long long ll;

//////////////////////////////////////////////////////////////////

int t, n, s, p, go, ans;

int main()
{
    //freopen(".in", "r", stdin);
    cin >> t;
    FOR(e,t)
    {
        ans = 0;
        cin >> n >> s >> p;
        for(int i=0; i<n; i++)
        {
            cin >> go;
            if(p == 0)
            {
                ans ++;
            }
            else if(p >= 1 && go >= 3*p - 2)
            {
                ans ++;
            }
            else if(p >= 2 && go >= 3*p - 4 && s > 0)
            {
                s --;
                ans ++;
            }
        }
        cout << "Case #" << e+1 << ": " << ans << endl;
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

#define LL long long
#define PII pair<int, int>
#define VS vector<string>
#define VI vector<int>
#define pb push_back

map<string, int> m;
VI v;
int mem[1005][105];

int f(int pos, int type) 
{
    if(pos >= v.size()) return 0;

    int &res = mem[pos][type];
    if(res == -1)
    {
        while(pos < v.size() && v[pos] != type) pos++;
        if(pos == v.size()) return res = 0;

        for(int i = 1; i <= m.size(); i++)
        {
            if(type == i) continue;
            int res2 = 1 + f(pos + 1, i);
            if(res == -1 || res2 < res)
                res = res2;
        }
    }
    return res;
}

int main() 
{
    freopen("a.in", "rt", stdin);
    freopen("a.out", "wt", stdout);

    int n, x;
    char str[105];

    cin >> n;
    for(int t = 1; t <= n; t++) 
    {
        memset(mem, -1, sizeof(mem));
        m.clear();
        v.clear();
        cin >> x;
        cin.get();
        for(int i = 0; i < x; i++)
        {
            cin.getline(str, sizeof(str));
            m[str] = i + 1;
        }
        cin >> x;
        cin.get();
        for(int i = 0; i < x; i++) 
        {
            cin.getline(str, sizeof(str));
            v.pb(m[str]);
        }
        int mn = v.size();
        for(int i = 1; i <= m.size(); i++) 
            mn = min(mn, f(0, i));
        cout << "Case #" << t << ": " << mn << endl;
    }

    return 0;
}
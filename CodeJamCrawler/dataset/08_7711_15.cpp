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

#define pb push_back
#define pii pair<int, int>
#define int64 long long
#define vi vector<int>
#define forr(i, n) for(int i = 0; i < (n); i++)
#define be(v) v.begin(), v.end()
#define sstr stringstream

int mas[40];
int cur[40];
int M, V;
        
int rec(int v)
{
    if(v <= (M-1)/2) {
        int x1 = rec(2*v), x2 = rec(2*v + 1);
        if(mas[v] == 1) 
            return x1 & x2;
        else 
            return x1 | x2;
    }
    else
    {
        return mas[v];
    }
}

int main()
{
    freopen("A.in", "rt", stdin);
    freopen("A.out", "wt", stdout);

    int test;
    cin >> test;
    for(int t = 1; t <= test; t++) 
    {
        cin >> M >> V;
        int nodes = (M-1)/2;
        vi ch;
        int a, b;
        forr(i, M)
        {
            cin >> cur[i+1];
            if(i < nodes)
            {
                cin >> b;
                if(b==1) ch.pb(i+1);
            }
        }
        
        memcpy(mas, cur, 4*40);

        int n = (1<<ch.size());
        int res = 10000;
        forr(mask, n)
        {
            int mmcount = 0;
            forr(i, ch.size())
            {
                int mm = (bool)(mask&(1<<i));
                if(mm)
                    mas[ch[i]] = !cur[ch[i]];
                else
                    mas[ch[i]] = cur[ch[i]];
                mmcount += mm;
            }
            if(rec(1) == V) res = min(res, mmcount);
        }
        cout << "Case #" << t << ": ";
        if(res == 10000)
               cout << "IMPOSSIBLE";
        else 
            cout << res;
        cout << endl;
    }
    return 0;
}
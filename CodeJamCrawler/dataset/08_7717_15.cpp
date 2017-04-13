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

int x[3], y[3];

int sq2()
{
    int res = 0;
    forr(i, 3) 
    {
        res += (x[(i+1)%3] - x[i]) * (y[(i+1)%3] + y[i]);
    }
    return abs(res);
}

int main()
{
    freopen("B.in", "rt", stdin);
    freopen("B.out", "wt", stdout);

    int test;
    cin >> test;
    for(int t = 1; t <= test; t++) 
    {
        int N, M, A;
        x[0] = 0, y[0] = 0;
       
        cin >> N >> M >> A;
        N++, M++;
        cout << "Case #" << t << ":";

        forr(i, N) forr(j, M) forr(i1, N) forr(j1, M)
        {
            x[1] = i, y[1] = j;
            x[2] = i1, y[2] = j1;
            if(sq2() == A)
            {
                forr(z, 3)
                    cout << " " << x[z] << " " << y[z];
                cout << endl;
                goto NEXT;
            }
        }
        cout << " IMPOSSIBLE" << endl;
NEXT:;
    }
    return 0;
}
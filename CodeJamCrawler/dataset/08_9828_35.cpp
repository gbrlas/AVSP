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

using namespace std;

typedef long long ll;

const int M = (1 << 14);

int m, tar;
int change[M];
int val[M][2];
int gate[M];

#define OR 0
#define AND 1

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int __cases;
    cin >> __cases;
    for (int __cs = 1; __cs <= __cases; ++ __cs)
    {
        int i, t, x, y;
        
        cin >> m >> tar;
        memset(change, 0, sizeof(change));
        memset(val, 0, sizeof(val));
        memset(gate, 0, sizeof(gate));
        for (i = 0; i < m / 2; ++ i)
        {
            cin >> gate[i] >> change[i];
        }
        for (; i < m; ++ i)
        {
            cin >> t;
            val[i][t] = 0;
            val[i][!t] = 10 * m;
        }
        
        for (i = m / 2 - 1; i >= 0; -- i)
        {
            x = 2 * i + 1;
            y = x + 1;
            
            val[i][0] = val[i][1] = 10 * m;
            //cout << gate[i] << " " << change[i] << endl;
            if (gate[i] == AND || change[i])
            {
                //cout << "X\n";
                t = (gate[i] != AND);
                val[i][0] = min(val[i][0], val[x][0] + val[y][0] + t);
                val[i][0] = min(val[i][0], val[x][0] + val[y][1] + t);
                val[i][0] = min(val[i][0], val[x][1] + val[y][0] + t);
                val[i][1] = min(val[i][1], val[x][1] + val[y][1] + t);
            }
            if (gate[i] == OR || change[i])
            {
               // cout << "Y\n";
                t = (gate[i] != OR);
                val[i][0] = min(val[i][0], val[x][0] + val[y][0] + t);
                val[i][1] = min(val[i][1], val[x][0] + val[y][1] + t);
                val[i][1] = min(val[i][1], val[x][1] + val[y][0] + t);
                val[i][1] = min(val[i][1], val[x][1] + val[y][1] + t);
            }
            //cout << i << " " << val[i][0] << " " << val[i][1] << endl; 
        }
        
        //cout << tar << endl;
        cout << "Case #" << __cs << ": ";
        if (val[0][tar] == 10 * m) cout << "IMPOSSIBLE" << endl;
        else cout << val[0][tar] << endl;
    }
    return 0;
}

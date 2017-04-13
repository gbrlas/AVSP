#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))

ifstream cin("D-small-attempt0.in");
ofstream cout("D-small-attempt0.out");

int p = 10007;

int main()
{

    int testNum = 0;
    cin >> testNum;
    for(int test = 1; test <= testNum; ++test)
    {
        int result = 0;
        int n, m, r, x, y;
        cin >> n >> m >> r;
        --n; --m;
        vector <vector <bool> > t(n + 1, vector<bool>(m + 1, true));
        REP (i, r)
        {
            cin >> x >> y;
            -- x; -- y;
            t[x][y] = false;
        }

         vector <vector <int> > num(n + 1, vector<int>(m + 1, 0));
         num [0][0] = 1;

         REP(i, n + 1) REP(j, m + 1)
         {
             if (t[i][j] == false)
             {
                 continue;
             }
             int x = i - 1;
             int y = j - 2;
             if (x >= 0 && y >= 0)
             {
                 num [i][j] += num[x][y];
             }

             x = i - 2;
             y = j - 1;
             if (x >= 0 && y >= 0)
             {
                 num [i][j] += num[x][y];
             }

             num[i][j] %= p;
         }



        cout << "Case #" << test <<": " << num[n][m] <<endl;
    }
    return 0;
}
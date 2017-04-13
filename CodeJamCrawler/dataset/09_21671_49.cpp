#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
using namespace std;
#define sz(c) (int)c.size()
#define pb push_back
#define all(c) c.begin(), c.end()


void initialize()
{
    freopen("C.in","r",stdin);
    freopen("output.txt","w",stdout);
}


const int MAX = 110, MAXK = 30, INF = 100000;
int a[MAX][MAXK];
int n, k;

char Less(int n1, int n2)
{
    bool less = false, more = false;
    for (int i = 0; i < k; ++i)
    {
        if (a[n1][i] == a[n2][i]) return 0;
        if (a[n1][i] < a[n2][i]) less = true;
        if (a[n1][i] > a[n2][i]) more = true;
    }
    if (less && !more) return -1;
    if (more && !less) return 1;
    return 0;
}

int par[MAX];
bool visited[MAX];
vector<int> reb[MAX];

bool dfs(int num)
{
    if (!visited[num] && !reb[num].empty())
    {
        visited[num] = true;
        int i;
        for (i = 0; i < reb[num].size(); i++)
        {
            if ((par[reb[num][i]] == -1) || (par[reb[num][i]] != -1 && dfs(par[reb[num][i]])))
            {
                par[reb[num][i]] = num;
                return true;
            }
        }
    }
    return false;
}



int main()
{
    initialize();

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        for (int i = 0; i < MAX; ++i)
        {
            par[i] = -1;
            reb[i].clear();
        }

        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < k; ++j)
                scanf("%d", &a[i][j]);
        }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                if (Less(i, j) == -1) reb[i].pb(j);
                if (Less(i, j) == 1) reb[j].pb(i);
            }


        int s = 0;
        for (int i = 0; i < n; ++i)
        {
            memset(visited, 0, sizeof(visited));
            if (dfs(i))
                s++;
        }


        printf("Case #%d: %d\n", t, n - s);
    }


    return 0;
}
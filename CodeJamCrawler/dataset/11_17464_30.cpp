#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int ll;

char dic[10101][111], LS[30];
int n, len[10101], pen[10101], Link[10101];
bool ex[10101][200], checked[200];

int mark(char * word, char *bb, char x)
{
    int ret = 1;
    for (int i = 0; word[i]; ++i)
        if (word[i] == x)
        {
            bb[i] = x;
            ret = 0;
        }
    //printf("\n%c %d", x, ret);
/*
    if (ret)
    {
        int p = 0, q = Link[0];
        while (q != 0)
        {
            if (ex[q][x])
                Link[p] = Link[q];
                else p = q;
            q = Link[q];
        }
    }
*/
    return ret;
}

bool maybe(char *bb, int le, char x)
{
    int p = 0, q = Link[0];
    while (q != 0)
    {
        bool ok = true;
        if (len[q] != le) ok = false;
        for (int i = 0; i < le; ++i)
        {
            if (bb[i] && bb[i] != dic[q][i]) ok = false;
            if (!bb[i] && checked[dic[q][i]]) ok = false;
        }
        if (ok)
        {
            if (ex[q][x]) return true;
            p = q; q = Link[q];
        } else
        {
            Link[p] = Link[q];
            q = Link[q];
        }
    }
    return false;
}


void solve(char *list)
{
    char see[111];
    for (int at = 1; at <= n; ++at)
    {
       // printf("\n%s ----", dic[at]);
        memset(checked, 0, sizeof checked);
        for (int i = 0; i < n; ++i)
            Link[i] = i + 1;
        Link[n] = 0;
        memset(see, 0, sizeof see);
        int all = len[at];
        pen[at] = 0;
        for (int k = 0; k < 26; ++k)
        {
            if (maybe(see, all, list[k]))
                pen[at] += mark(dic[at], see, list[k]);
            checked[list[k]] = true;
        }
        //printf("%d\n", pen[at]);
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i)
        if (pen[i] > pen[ans]) ans = i;
    printf(" %s", dic[ans]);
}

int main()
{
    freopen("b1.in", "r", stdin);
    freopen("b1.out", "w", stdout);
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas)
    {
        printf("Case #%d:", cas);
        int m; scanf("%d%d", &n, &m);
        memset(ex, 0, sizeof ex);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", dic[i]);
            len[i] = strlen(dic[i]);
            for (int j = 0; j < len[i]; ++j)
                ex[i][dic[i][j]] = true;
        }
        for (int i = 1; i <= m; ++i)
        {
            scanf("%s", LS);
            solve(LS);
        }
        puts("");
    }
    return 0;
}

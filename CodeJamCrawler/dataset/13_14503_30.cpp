//Copyright @ 2013, Chow-Shing Shih, All rights reserved.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>
#include <utility>
#include <iostream>
#include <cmath>
#define rep(i, n) for (int i = 1; i <= n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define INF 0x7fffffff
#define MP(x, y) (make_pair(x, y))
#define pb(x) push_back(x)
#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long llu;

inline int Lowbit(int i){return i & (-i);}
inline void read(int &n)
{
    char c;
    for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar());
    n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}

int T, cases;
char s[100][100];

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 4; ++i)    scanf("%s", s[i] + 1);
        bool f1 = 0, f2 = 0;
        for (int i = 1; i <= 4; ++i)
        {
            int tot1 = 0, tot2 = 0;
            for (int j = 1; j <= 4; ++j)
                if (s[i][j] == 'X') tot1++;
                else if (s[i][j] == 'O')    tot2++;
                else if (s[i][j] == 'T')    tot1++, tot2++;
            if (tot1 == 4)  f1 = 1;
            if (tot2 == 4) f2 = 1;
            tot1 = 0, tot2 = 0;
            tot1 = 0, tot2 = 0;
            for (int j = 1; j <= 4; ++j)
                if (s[j][i] == 'X') tot1++;
                else if (s[j][i] == 'O')    tot2++;
                else if (s[j][i] == 'T')    tot1++, tot2++;
            if (tot1 == 4)  f1 = 1;
            if (tot2 == 4)  f2 = 1;
        }
        if ((s[1][1] == 'X' || s[1][1] == 'T')
        && (s[2][2] == 'X' || s[2][2] == 'T')
        && (s[3][3] == 'X' || s[3][3] == 'T')
        && (s[4][4] == 'X' || s[4][4] == 'T'))
            f1 = 1;
        if ((s[4][1] == 'X' || s[4][1] == 'T')
        && (s[3][2] == 'X' || s[3][2] == 'T')
        && (s[2][3] == 'X' || s[2][3] == 'T')
        && (s[1][4] == 'X' || s[1][4] == 'T'))
            f1 = 1;
        if ((s[1][1] == 'O' || s[1][1] == 'T')
        && (s[2][2] == 'O' || s[2][2] == 'T')
        && (s[3][3] == 'O' || s[3][3] == 'T')
        && (s[4][4] == 'O' || s[4][4] == 'T'))
            f2 = 1;
        if ((s[4][1] == 'O' || s[4][1] == 'T')
        && (s[3][2] == 'O' || s[3][2] == 'T')
        && (s[2][3] == 'O' || s[2][3] == 'T')
        && (s[1][4] == 'O' || s[1][4] == 'T'))
            f2 = 1;
        bool over = 1;
        for (int i = 1; i <= 4; ++i)
            for (int j = 1; j <= 4; ++j)
                if (s[i][j] == '.') over = 0;
        printf("Case #%d: ", ++cases);
        if (!over && !f1 && !f2) 
            puts("Game has not completed");
        else if (f1 && !f2)
            puts("X won");
        else if (!f1 && f2)
            puts("O won");
        else puts("Draw");
    }
    return 0;
}

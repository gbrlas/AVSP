#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int t,n;

struct str{
    int d,l;
};

str st[10010];

int D;

bool dfs(int a, int b)
{
    if (a == n)
        return 1;
    int i;
    for (i = n;i > a;i--)
            {
                if (st[i].d - st[a].d <= b)
                {
                    if (dfs(i, min(st[i].l, st[i].d - st[a].d)))
                        return 1;
                }
            }
            return 0;
}

int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k;
    scanf("%d", &t);
    for (k = 1;k <= t;k++)
    {
        scanf("%d", &n);
        for (i = 0;i < n;i++)
            scanf("%d%d", &st[i].d, &st[i].l);
        scanf("%d", &D);
        st[n].d = D;
        st[n].l = 0;
        int now = 0;
        printf("Case #%d: ", k);
        if (dfs(now, st[now].d))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

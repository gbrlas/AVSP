#include <cstdio>
#include <cstring>

int main()
{
    freopen("b.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int  ncase, c, d, n;
    char com[120][120], opp[120][120];
    char str[105], ans[105];

    scanf("%d", &ncase);
    for (int nc=1; nc<=ncase; nc++)
    {
        memset(com, 0, sizeof(com));
        memset(opp, 0, sizeof(opp));
        scanf("%d", &c);
        while (c--)
        {
            scanf("%s", str);
            com[str[0]][str[1]] = str[2];
            com[str[1]][str[0]] = str[2];
        }
        scanf("%d", &d);
        while (d--)
        {
            scanf("%s", str);
            opp[str[0]][str[1]] = 1;
            opp[str[1]][str[0]] = 1;
        }
        scanf("%d", &n);
        scanf("%s", str);
        int j = 0;
        for (int i=0; i<n; i++)
        {
            ans[j++] = str[i];
            if (j > 1 && com[ans[j-2]][str[i]] > 0)
            {
                ans[j-2] = com[ans[j-2]][str[i]];
                j--;
            }
            else
            {
                for (int k=0; k<j-1; k++)
                    if (opp[ans[j-1]][ans[k]])
                    {
                        j = 0;
                        break;
                    }
            }
        }
        printf("Case #%d: [", nc);
        for (int i=0; i<j; i++)
        {
            printf("%c", ans[i]);
            if (i < j-1)
                printf(", ");
        }
        printf("]\n");
    }
}

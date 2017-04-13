#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    freopen("aa.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int ncase, nc, r, c;
    char ch[100][100];

    scanf("%d", &ncase);
    for (nc=1; nc<=ncase; nc++)
    {
        scanf("%d %d", &r, &c);
        for (int i=0; i<r; i++)
            scanf("%s", ch[i]);
        int tag = 1;
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (ch[i][j] == '#')
                {
                    if (j+1 < c && i+1 < r && ch[i][j+1] == '#'
                        && ch[i+1][j] == '#' && ch[i+1][j+1] == '#')
                    {
                        ch[i][j] = ch[i+1][j+1] = '/';
                        ch[i][j+1] = ch[i+1][j] = '\\';
                    }
                    else
                    {
                        tag = 0;
                        goto loop;
                    }
                }
            }
        }
        loop:
        printf("Case #%d:\n", nc);
        if (!tag)
            printf("Impossible\n");
        else
        {
            for (int i=0; i<r; i++)
            {
                printf("%s\n", ch[i]);
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mine
{
    int line[4],row[4],p1[4],p2[4];
}a[5];
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int t,cas=0;
    char s[5][5];
    scanf("%d",&t);
    while (t--)
    {
        int i,j,dian=0;
        for (i=0;i<4;i++) scanf("%s",&s[i]);
        getchar();
        memset(a,0,sizeof(a));
        for (i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
            {
                if (s[i][j]=='.') dian++;
                switch(s[i][j])
                {
                    case 'X':a[i].line[1]++;break;
                    case 'O':a[i].line[2]++;break;
                    case 'T':a[i].line[3]++;break;
                }
                switch(s[j][i])
                {
                    case 'X':a[i].row[1]++;break;
                    case 'O':a[i].row[2]++;break;
                    case 'T':a[i].row[3]++;break;
                }
            }
            switch (s[i][i])
            {
                case 'X':a[4].p1[1]++;break;
                case 'O':a[4].p1[2]++;break;
                case 'T':a[4].p1[3]++;break;
            }
            switch (s[i][2-i+1])
            {
                case 'X':a[4].p2[1]++;break;
                case 'O':a[4].p2[2]++;break;
                case 'T':a[4].p2[3]++;break;
            }
        }
        int u=0;
        for (i=0;i<4;i++)
        {
            if (a[i].line[1]==4||(a[i].line[1]==3&&a[i].line[3]==1)||a[i].row[1]==4||(a[i].row[1]==3&&a[i].row[3]==1))
            {
                u=1;
                break;
            }
            if (a[i].line[2]==4||(a[i].line[2]==3&&a[i].line[3]==1)||a[i].row[2]==4||(a[i].row[2]==3&&a[i].row[3]==1))
            {
                u=2;
                break;
            }
        }
        if (a[4].p1[1]==4||(a[4].p1[1]==3&&a[4].p1[3]==1)||a[4].p2[1]==4||(a[4].p2[1]==3&&a[4].p2[3]==1))
        {
            u=1;
        }
        if (a[4].p1[2]==4||(a[4].p1[2]==3&&a[4].p1[3]==1)||a[4].p2[2]==4||(a[4].p2[2]==3&&a[4].p2[3]==1))
        {
            u=2;
        }
        if (u==0&&dian>0) u=3;
        printf("Case #%d: ",++cas);
        switch (u)
        {
            case 0:printf("Draw\n");break;
            case 1:printf("X won\n");break;
            case 2:printf("O won\n");break;
            case 3:printf("Game has not completed\n");break;
        }
    }
    return 0;
}

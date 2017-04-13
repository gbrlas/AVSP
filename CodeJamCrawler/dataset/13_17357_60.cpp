//source here
#include<cstdio>
#include<map>
#include<string>
#include<string.h>
#include<iostream>

using namespace std;
char a[10][10];
int main()
{
    //freopen("A-small-attempt6.in","r",stdin);
    //freopen("A.out","w",stdout);
    int t,x,o,n,xx,yy;
    scanf("%d",&t);
    for(int kk=1; kk<=t; ++kk)
    {
        printf("Case #%d: ",kk);
        //getchar();
        n=0;
        for(int j=0;j<4;j++)
        {
            scanf("%s",a[j]);
            for(int k=0;k<4;k++)
             {if(a[j][k]=='T')
             {
                 xx=j;yy=k;
             }
             else
              if(a[j][k]=='.')n++;
             }
        }
        x=o=0;
        a[xx][yy]='X';
        for(int i=0;i<4;i++)
        {
            if(a[i][0]=='X'&&a[i][1]=='X'&&a[i][2]=='X'&&a[i][3]=='X')
            {
                x=4;break;
            }
            if(a[0][i]=='X'&&a[1][i]=='X'&&a[2][i]=='X'&&a[3][i]=='X')
            {
                x=4;break;
            }
        }
        if(a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X'&&a[3][3]=='X')
            {
                x=4;
            }
            if(a[0][3]=='X'&&a[1][2]=='X'&&a[2][1]=='X'&&a[3][0]=='X')
            {
                x=4;
            }

            if(x==4)
        {
            printf("X won\n");continue;
        }
        a[xx][yy]='O';
        for(int i=0;i<4;i++)
        {
            if(a[i][0]=='O'&&a[i][1]=='O'&&a[i][2]=='O'&&a[i][3]=='O')
            {
                o=4;break;
            }
            if(a[0][i]=='O'&&a[1][i]=='O'&&a[2][i]=='O'&&a[3][i]=='O')
            {
                o=4;break;
            }
        }
        if(a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O'&&a[3][3]=='O')
            {
                o=4;
            }
            if(a[0][3]=='O'&&a[1][2]=='O'&&a[2][1]=='O'&&a[3][0]=='O')
            {
                o=4;
            }


        if(o==4)
        {
            printf("O won\n");continue;
        }
        if(n>0)
        {
            printf("Game has not completed\n");
            continue;
        }
        printf("Draw\n");
    }
    return 0;
}

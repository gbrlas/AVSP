#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string a[4];
    int t,flag,i,j,k;
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d ",&t);
    for(k=1;k<=t;k++)
    {
        for(i=0;i<4;i++)
           cin>>a[i];
        flag=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(a[i][j]=='O' || a[i][j]=='.')
                    break;
            }
            if(j==4)
            {
                flag=1;
                printf("Case #%d: X won\n",k);
                break;
            }
        }
        if(!flag)
        {
            for(i=0;i<4;i++)
            {
            for(j=0;j<4;j++)
            {
                if(a[j][i]=='O' || a[j][i]=='.')
                break;
            }
            if(j==4)
            {
                flag=1;
                printf("Case #%d: X won\n",k);
                break;
            }
            }
        }
        if(!flag)
        {
            for(i=0;i<4;i++)
            {
              if(a[i][i]=='O' || a[i][i]=='.')
                break;
            }
            if(i==4)
            {
                flag=1;
                printf("Case #%d: X won\n",k);
            }
        }
        if(!flag)
        {
            for(i=0;i<4;i++)
            {
              if(a[i][3-i]=='O' || a[i][3-i]=='.')
                break;
            }
            if(i==4)
            {
                flag=1;
                printf("Case #%d: X won\n",k);
            }
        }
        if(!flag)
        {
            for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(a[i][j]=='X' || a[i][j]=='.')
                break;
            }
            if(j==4)
            {
                flag=1;
                printf("Case #%d: O won\n",k);
                break;
            }
        }
        }

        if(!flag)
        {
            for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(a[j][i]=='X' || a[j][i]=='.')
                break;
            }
            if(j==4)
            {
                flag=1;
                printf("Case #%d: O won\n",k);
                break;
            }
        }
        }

        if(!flag)
        {
            for(i=0;i<4;i++)
            {
              if(a[i][i]=='X' || a[i][i]=='.')
                break;
            }
            if(i==4)
            {
                flag=1;
                printf("Case #%d: O won\n",k);
            }
        }
        if(!flag)
        {
            for(i=0;i<4;i++)
            {
              if(a[i][3-i]=='X' || a[i][3-i]=='.')
                break;
            }
            if(i==4)
            {
                flag=1;
                printf("Case #%d: O won\n",k);
            }
        }
        if(!flag)
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(a[i][j]=='.')
                        break;
                }
                if(j!=4)
                    break;
            }
            if(i==4)
                printf("Case #%d: Draw\n",k);
            else
                printf("Case #%d: Game has not completed\n",k);
        }
    }
    return 0;
}

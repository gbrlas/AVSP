#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char a[10][10];
int flage;
int main()
{
    freopen("d:\\1.txt","r",stdin);
    freopen("d:\\out.txt","w",stdout);
    int i,j,n,ncase;
    int sum_p;
    scanf("%d",&ncase);
    for(n = 1; n<= ncase; n++)
    {
        int sum_x = 0;
        int sum_t = 0;
        int sum_o = 0;
        flage = 0;
        sum_p = 0;
        for(i = 1; i<=4 ;i++)
            for(j = 1;j<=4 ;j++)
            {
                cin>>a[i][j];
                if(a[i][j] == '.')
                    sum_p++;
            }
        for(i = 1 ; i <=4 ; i++)
        {
             sum_x = 0;
             sum_t = 0;
             sum_o = 0;
            for(j = 1 ; j<= 4 ; j++)
            {
                if(a[i][j] == 'X')
                    sum_x++;
                if(a[i][j] == 'T'&&sum_t == 0)
                    sum_t = 1;
                if(a[i][j] == 'O')
                    sum_o++;
            }
            if(sum_t+sum_x == 4)
            {
                flage = 1;
                printf("Case #%d: X won\n",n);
                break;
            }
            if(sum_o + sum_t == 4)
            {
                flage = 2;
                printf("Case #%d: O won\n",n);
                break;
            }
        }
        if(flage)
            continue;


        for(i = 1 ; i <=4 ; i++)
        {
             sum_x = 0;
             sum_t = 0;
             sum_o = 0;
            for(j = 1 ; j<= 4 ; j++)
            {
                if(a[j][i] == 'X')
                    sum_x++;
                if(a[j][i] == 'T'&&sum_t == 0)
                    sum_t = 1;
                if(a[j][i] == 'O')
                    sum_o++;
            }
            if(sum_t+sum_x == 4)
            {
                flage = 1;
                printf("Case #%d: X won\n",n);
                break;
            }
            if(sum_t+sum_o == 4)
            {
                flage = 2;
                printf("Case #%d: O won\n",n);
                break;
            }
        }
        if(flage) continue;
            sum_x = 0;
            sum_t = 0;
            sum_o = 0;
        for(i = 1 ; i <= 4 ;i++)
        {
            if(a[i][i] == 'X')
                sum_x++;
            if(a[i][i] == 'O')
                sum_o++;
            if(a[i][i] == 'T'&&sum_t==0)
                sum_t++;
        }
        if(sum_x+sum_t==4)
        {
             printf("Case #%d: X won\n",n);
             continue;
        }
        if(sum_o+sum_t==4)
        {
            printf("Case #%d: O won\n",n);
            continue;
        }

            sum_x = 0;
            sum_t = 0;
            sum_o = 0;
        for(i=1;i<=4;i++)
        {
            if(a[i][5-i] == 'X')
                sum_x++;
            if(a[i][5-i] == 'O')
                sum_o++;
            if(a[i][5-i] == 'T'&&sum_t==0)
                sum_t++;
        }
        if(sum_x+sum_t==4)
        {
             printf("Case #%d: X won\n",n);
             continue;
        }
        if(sum_o+sum_t==4)
        {
            printf("Case #%d: O won\n",n);
            continue;
        }
        if(sum_p)
        {
            printf("Case #%d: Game has not completed",n);
            continue;
        }
        else
        {
            printf("Case #%d: Draw",n);
        }
    }
    return 0;
}

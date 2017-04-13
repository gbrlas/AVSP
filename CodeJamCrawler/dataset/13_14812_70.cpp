#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int n,m;
int map[105][105];
int k = 1;
bool check1(int num, int x, int y)
{
    bool flag = 1;
    for (int i=0; i<m; i++)
    {
        if(map[x][i]>num)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
bool check2(int num, int x, int y)
{
    bool flag = 1;
    for (int i=0; i<n; i++)
    {
        if(map[i][y]>num)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main()
{
    freopen("bin.txt","r",stdin);
    freopen("bout.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int flag;
    int k = 1;
    while(t--)
    {
        flag = 1;
        scanf("%d %d",&n ,&m);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%d",&map[i][j]);
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(check1(map[i][j],i,j) || check2(map[i][j],i,j))
                {

                }
                else
                {
                    flag = 0;
                    break;
                }
            }
        }
        printf("Case #%d: ",k++);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}

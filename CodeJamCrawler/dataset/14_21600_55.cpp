#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int i,j,t,a,b,g=1;
    int f[5][5],ff[5][5],countx,tt;
    scanf("%d",&t);
    while(t--)
    {
        countx=0;
        scanf("%d",&a);
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                scanf("%d",&f[i][j]);
        scanf("%d",&b);
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                scanf("%d",&ff[i][j]);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(f[a-1][i]==ff[b-1][j])
                {
                    countx++;
                    tt=f[a-1][i];
                }
            }
        }
        printf("Case #%d: ",g++);
        if(countx==1) printf("%d\n",tt);
        else if(countx>1) printf("Bad magician!\n");
        else printf("Volunteer cheated!\n");
    }
    return 0;
}

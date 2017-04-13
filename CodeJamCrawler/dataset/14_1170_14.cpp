#include <cstdio>
int a[6][6],b[6][6];
int main()
{
    int T,cas=0;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
     int t1,t2;
     scanf("%d",&t1);
     for(int i=1;i<=4;++i)
        for(int j=1;j<=4;++j)scanf("%d",a[i]+j);
     scanf("%d",&t2);
     for(int i=1;i<=4;++i)
        for(int j=1;j<=4;++j)scanf("%d",b[i]+j);
     int ans,nu=0;
     for(int i=1;i<=4;++i)
     for(int j=1;j<=4;++j)
      if(a[t1][i]==b[t2][j])
      {
       ans=a[t1][i];
       ++nu;
      }
     printf("Case #%d: ",++cas);
     if(nu==1)printf("%d\n",ans);
     else if(nu==0)puts("Volunteer cheated!");
     else puts("Bad magician!");
    }
    return 0;
}

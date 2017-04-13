#include<stdio.h>
int main()
{
 int n,i,j,k,t,x;
 int power[100],on[100];
   freopen("a.in","r",stdin);
    freopen("output.txt","w",stdout);
 scanf("%d",&t);
 power[0]=1;
for(x=0;x<t;x++)
           {
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
     {
     if(i==1) { power[i]=1; on[i]=0; }
     else { power[i]=0; on[i]=0; }
     }
     
    for(j=1;j<=k;j++)
    {
        for(i=1;i<=n;i++)
           if(power[i]==1) if(on[i]==1) on[i]=0; else  on[i]=1;

        for(i=2;i<=n;i++)
            if(power[i-1]==1 && on[i-1]==1)  power[i]=1;  else power[i]=0;
       /* for(i=1;i<=n;i++)
          printf("%d ",on[i]);
          printf("\n");
         */
    }
    if(on[n]==1 && power[n]==1) printf("Case #%d: ON\n",x+1);
    else printf("Case #%d: OFF\n",x+1);
           }
    return 0;
}
     

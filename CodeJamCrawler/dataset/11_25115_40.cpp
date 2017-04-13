#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int tt,L,N,C,a,dis[1005],last[10];
bool mark[1005],chans;
long long T,at[1005],ans;
void gen(int h)
{
        if(h<=L)
        {
                for(int i=last[h-1]+1;i<N;i++)
                {
                        last[h]=i;
                        mark[i]=1;
                        gen(h+1);
                        mark[i]=0;
                }
                return;
        }
        /*for(int i=0;i<N;i++)
        {
                printf("%d ",mark[i]);
        }
        printf("\n");*/
        //system("pause");
        for(int i=0;i<N;i++)
        {
                //printf("%d %I64d ",dis[i],at[i]);
                if(!mark[i])
                {
                        at[i+1]=at[i]+dis[i]*2;
                }
                else
                {
                        //printf("AHA ");
                        //can use at begin
                        if(at[i]>=T)
                        {
                                at[i+1]=at[i]+dis[i];
                        }else
                        //can use between
                        if(at[i]+dis[i]*2>T)
                        {
                                //printf("OO ");
                                at[i+1]=T/2+dis[i]+at[i]/2;
                        }
                        else at[i+1]=at[i]+dis[i]*2;
                }
                //printf("%I64d ",at[i+1]);
        }
        if(!chans)
        {
                chans=1;
                ans=at[N];
        }
        else
        {
                ans=min(ans,at[N]);
        }
        //printf("%\n");
        //printf("%I64d\n",at[N]);
}
int main()
{
        freopen("inB.txt","r",stdin);
        freopen("outB.txt","w",stdout);
        scanf("%d",&tt);
        for(int rr=1;rr<=tt;rr++)
        {
                chans=0;
                last[0]=-1;
                at[0]=0;
                scanf("%d %I64d %d %d",&L,&T,&N,&C);
                for(int i=0;i<C;i++)
                {
                        scanf("%d",&a);
                        for(int j=i;j+1<=N;j+=C)
                        {
                                dis[j]=a;
                        }
                }
                gen(1);
                printf("Case #%d: %I64d\n",rr,ans);
        }
        //system("pause");
}
                
                        

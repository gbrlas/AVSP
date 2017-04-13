#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,N,p[1005],np,maxx,g[1005],minn,now;
bool mark[1005];
bool a[1005];
int main()
{
        freopen("inC.txt","r",stdin);
        freopen("outC.txt","w",stdout);
        scanf("%d",&t);
        for(int rr=1;rr<=t;rr++)
        {
                scanf("%d",&N);
                for(int i=0;i<1000;i++) { mark[i]=0; a[i]=0; }
                p[0]=2;
                np=1;
                //gen prime
                for(int i=3;i<=N;i+=2)
                {
                        if(!a[i])
                        {
                                p[np]=i;
                                np++;
                                for(int j=i*2;j<=N;j+=i)
                                {
                                        a[j]=1;
                                }
                        }
                }
                maxx=1;
                for(int i=0;i<np;i++)
                {
                        for(int k=p[i];k<=N;k*=p[i])
                        {
                                maxx++;
                                g[i]=k;
                        }
                }
                /*for(int i=0;i<np;i++)
                {
                        printf("%d %d\n",p[i],g[i]);
                }*/
                if(N!=1)
                minn=0;
                else minn=1;
                for(int i=np-1;i>=0;i--)
                {
                        if(mark[i])continue;
                        mark[i]=1;
                        minn++;
                        now=g[i];
                        for(int j=i-1;j>=0;j--)
                        {
                                if(now*g[j]<=N)
                                {
                                        now*=g[j];
                                        mark[j]=1;
                                }
                        }
                }
                //printf("%d %d\n",maxx,minn);
                if(N==1)
                {
                        printf("Case #%d: 0\n",rr);
                }
                else
                {
                        printf("Case #%d: %d\n",rr,maxx-minn);
                }
                        
        }
        //system("pause");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int X,S,R,N;
double T;
int in1,in2;
struct node {
        int w,d;
        bool operator < (const node &o) const { return w<o.w; }
}a[1005];
int t;
double t_use,d_get,d_left,ans;
int main()
{
        freopen("inA.txt","r",stdin);
        freopen("outA.txt","w",stdout);
        scanf("%d",&t);
        for(int rr=1;rr<=t;rr++)
        {
                ans=0;
                scanf("%d %d %d %lf %d",&X,&S,&R,&T,&N);
                for(int i=0;i<N;i++)
                {
                        scanf("%d %d %d",&in1,&in2,&a[i].w);
                        a[i].d=in2-in1;
                        X-=a[i].d;
                }
                a[N].w=0;
                a[N].d=X;
                sort(&a[0],&a[N+1]);
                for(int i=0;i<=N;i++)
                {
                        if(T<a[i].d*1.0/(R+a[i].w))
                        {
                                d_get=T*(R+a[i].w);
                                ans+=T;
                                d_left=a[i].d-d_get;
                                ans+=d_left/(S+a[i].w);
                                T=0;
                        }
                        else
                        {
                                t_use=a[i].d*1.0/(R+a[i].w);
                                T-=t_use;
                                ans+=t_use;
                        }
                }
                /*for(int i=0;i<=N;i++)
                {
                        printf("%d %d\n",a[i].d,a[i].w);
                }*/
                printf("Case #%d: %.9lf\n",rr,ans);
        }
        //system("pause");
}

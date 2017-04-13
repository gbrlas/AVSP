#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
typedef long long int64;
using namespace std;

struct point
{
    int64 x,y;
}p[600][600],sum[600][600];

int ma[600][600],ms[600][600];

point operator +(point a,point b)
{
    point c;

    c.x=a.x+b.x;
    c.y=a.y+b.y;
    return c;
}

point operator -(point a,point b)
{
    point c;

    c.x=a.x-b.x;
    c.y=a.y-b.y;
    return c;
}

point getsum(int i,int j,int k)
{
    point res=sum[i+k-1][j+k-1]+sum[i-1][j-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1];

    res=res-p[i][j]-p[i+k-1][j+k-1]-p[i][j+k-1]-p[i+k-1][j];
    return res;
}

int getsum2(int i,int j,int k)
{
    int res=ms[i+k-1][j+k-1]+ms[i-1][j-1]-ms[i-1][j+k-1]-ms[i+k-1][j-1];

    res=res-ma[i+k-1][j+k-1]-ma[i][j]-ma[i][j+k-1]-ma[i+k-1][j];
    return res;
}

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
    freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
    int test;

    cin>>test;
    for(int times=1;times<=test;times++)
    {
        int n,m,d;
        int best=2;

        memset(p,0,sizeof p);
        memset(sum,0,sizeof sum);
        memset(ma,0,sizeof ma);
        memset(ms,0,sizeof ms);
        cin>>n>>m>>d;
        for(int i=1;i<=n;i++)
        {
            char s[1000];
            

            cin>>s;
            for(int j=0;j<m;j++)
            {
                ma[i][j+1]=s[j]-'0';
                p[i][j+1].x=i*(s[j]-'0');
                p[i][j+1].y=(j+1)*(s[j]-'0');
            }
		}
        for(int i=0;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                sum[i][j]=sum[i][j-1]+p[i][j];
                ms[i][j]=ms[i][j-1]+ma[i][j];
            }

        for(int i=1;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                sum[i][j]=sum[i][j]+sum[i-1][j];
                ms[i][j]=ms[i][j]+ms[i-1][j];
            }

            
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=best+1;i+k-1<=n && j+k-1<=m;k++)
                {
                    point xt=getsum(i,j,k),real;
                    int mm=getsum2(i,j,k);

                    xt.x*=2;xt.y*=2;
                    real.x=mm*(i+i+k-1);
                    real.y=mm*(j+j+k-1);
                    if(real.x==xt.x && real.y==xt.y)
                        best=max(k,best);
                }

        if(best==2)
        {
			printf("Case #%d: IMPOSSIBLE\n",times);
        }
        else
        {
			printf("Case #%d: %d\n",times,best);
        }
    }
    return 0;
}


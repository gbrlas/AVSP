#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1010;
const double eps=1e-9;
double x,r,s,t;

struct node
{
       double b;
       double e;
       double w;
       bool operator < (node obj) const
       {
            return b<obj.b;
       }
};

struct seg
{
    double d;
    double w;
    bool operator < (seg obj) const
    {
            return w<obj.w;
    }
};

node arr[MAXN];
seg sarr[MAXN*2];
int n,ns;

double runner(double &t,double d,double s,double r,double w)
{
     if(t<=eps)
     {
            return d/(s+w);
     }
     else
     {
            double res,v=r+w;
            if(d<=t*v)
            {
                res=d/v;
                t-=d/v;
            }
            else
            {
                res=t;
                d=d-v*t;
                t=0;
                res+=d/(s+w);
            }
            return res;
      }
}

double calc()
{
    double res=0;
    for(int i=0;i<ns;i++)
    {
        res+=runner(t,sarr[i].d,s,r,sarr[i].w);
    }
    return res;
}

double work()
{
    double loc=0,res=0;
    double d,w;
    ns=0;
    for(int i=0;i<n;i++)
    {
        d=arr[i].b-loc;
        w=0;
        if(d>eps)
        {
            sarr[ns].d=d;
            sarr[ns].w=w;
            ns++;
        }
        d=arr[i].e-arr[i].b;
        w=arr[i].w;
        if(d>eps)
        {
            sarr[ns].d=d;
            sarr[ns].w=w;
            ns++;
        }
        loc=arr[i].e;
    }
    sort(sarr,sarr+ns);
    
    return calc();
}

int main()
{
    int i,cas,tt;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("a_out.txt","w",stdout);
    scanf("%d",&tt);
    for(cas=1;cas<=tt;cas++)
    {
        scanf("%lf%lf%lf%lf%d",&x,&s,&r,&t,&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&(arr[i].b),&(arr[i].e),&(arr[i].w));
        }
        arr[n].b=arr[n].e=x;
        arr[n].w=0;
        n++;
        sort(arr,arr+n);
        double res=work();
         printf("Case #%d: %.9f\n",cas,res);
    }
    return 0;
}

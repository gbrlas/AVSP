#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct inter
{
    int l,w;
}p[2000];

inline bool cmp(inter a,inter b)
{
    return a.w<b.w;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
    //freopen("-large.in","r",stdin);freopen("-large.out","w",stdout);
    int test;

    cin>>test;
    for(int times=1;times<=test;times++)
    {
        int x,s,r,n;
        double t;

        cin>>x>>s>>r>>t>>n;
        for(int i=0;i<n;i++)
        {
            int ei,bi;

            cin>>bi>>ei>>p[i].w;
            p[i].l=ei-bi;
            x-=p[i].l;
        }
        p[n].l=x;
        p[n].w=0;
        sort(p,p+n+1,cmp);

        double res=0;

        for(int i=0;i<=n;i++)
        {
            double tmp=min(t,(double)p[i].l/(p[i].w+r));

            res+=tmp;
            t-=tmp;
            res+=(p[i].l-tmp*(p[i].w+r))/((double)p[i].w+s);
        }
        printf("Case #%d: %.8lf\n",times,res);
    }
    return 0;
}


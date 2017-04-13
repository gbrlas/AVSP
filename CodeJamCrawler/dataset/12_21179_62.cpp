#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=100000+5,inf =1000000000;

int W,L;

struct Node
{
    int r;
    int id,x,y;
}a[N];

bool cmp (const Node &a,const Node &b)
{
    return a.r<b.r;
}

bool cmp_(const Node &a,const Node &b )
{
    return a.id<b.id;
}

int main()
{
    freopen("in2.txt","r",stdin);
   freopen("out.txt","w",stdout);
    int total,cc=0;
    cin>>total;
    while (total--)
    {
        int n;
        scanf("%d",&n);
        scanf("%d %d",&W,&L);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i].r),a[i].id=i;
        sort(a,a+n,cmp);

        int i=0,j;
        int lim,x,y,Y=-inf;
        for (;i<n;)
        {
            j=i;
            x=0;
            lim=x+a[i].r;
            y=a[i].r;
            a[i].x=x;

            for (i=i+1;i<n;i++)
            {
                if (lim+a[i].r<=W)
                {
                    x=lim+a[i].r;
                    lim=x+a[i].r;
                    y=a[i].r;
                    a[i].x=x;
                }else break;
            }

            Y=max(0,Y+y);
            for (int k=j;k<i;k++)
                a[k].y=Y;
            Y+=y;
        }

        sort(a,a+n,cmp_);
        printf("Case #%d:",++cc);
        for (int i=0;i<n;i++)
            printf(" %d %d",a[i].x,a[i].y);
        printf("\n");
    }
}
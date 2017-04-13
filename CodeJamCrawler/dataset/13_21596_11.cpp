#include <cstdio>

using namespace std;

int main()
{
    freopen ("A-small-attempt1.in","r",stdin);
    freopen ("output.txt","w",stdout);
    int T,i; long long r,t,s,a,p;
    scanf("%d",&T);
    for (i=1;i<=T;i++)
    {
    s=0;
    p=0;
    scanf ("%I64d %I64d",&r,&t);
    a=(r+1)*(r+1)-(r*r);
    p=p+a;
    r++;
    while (p<=t)
    {
        s++;
        r+=2;
        a=(r*r)-(r-1)*(r-1);
        p=p+a;
    }
    printf("Case #%d: %I64d\n",i,s);
    }
    return 0;
}

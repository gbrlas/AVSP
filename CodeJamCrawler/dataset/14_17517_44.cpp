/**

*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#define eps 1e-8
using namespace std;

int a[20],t;
double c,f,x,r;
double ans;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d",&t);
    int __=0;
    while(t--)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        r=2;
        ans=0;
        while(1)
        {
            if(x/r<(c/r+x/(r+f))-eps)
            {
                ans+=x/r;
                break;
            }
            ans+=c/r;
            r+=f;
        }
        printf("Case #%d: %.7f\n",++__,ans);
    }

    return 0;
}

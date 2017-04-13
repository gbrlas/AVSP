#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,tcase=0;
    scanf("%d",&t);
    double C,F,X;
    while(t--)
    {
        scanf("%lf%lf%lf",&C,&F,&X);
        double times=0,rate=2.0,tmp1,tmp2;
        while(true)
        {
            tmp1=X/rate;
            tmp2=C/rate;
            tmp2+=X/(rate+F);
            if(dcmp(tmp1-tmp2)<=0)
            {
                times+=tmp1;
                break;
            }
            else
            {
                times+=C/rate;
                rate+=F;
            }
        }
        printf("Case #%d: %.7lf\n",++tcase,times);
    }
    return 0;
}

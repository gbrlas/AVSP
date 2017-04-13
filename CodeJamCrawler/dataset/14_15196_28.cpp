#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define sca(a) scanf("%d",&a)
#define sc(a,b) scanf("%d%d",&a,&b)
#define pri(a) printf("%d\n",a)
#define lson i<<1,l,mid
#define rson i<<1|1,mid+1,r
#define MM 500000004
#define MN 166666668
#define INF 1000000007
#define eps 1e-7
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int main()
{
    int t,pp;
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    sca(t);
    for(pp=1;pp<=t;pp++)
    {
        double c,f,x,v=2.0,sum,sum1,Max;
        scanf("%lf%lf%lf",&c,&f,&x);
        sum=c/v,sum1=x/v,v+=f;
        Max=sum1;
        while(sum<=sum1)
        {
            sum1=sum;
            sum1+=x/v;
            sum+=c/v;
            if(sum1>Max) break;
            Max=sum1;
            v+=f;
        }
        printf("Case #%d: %.7f\n",pp,Max);
    }
    return 0;
}


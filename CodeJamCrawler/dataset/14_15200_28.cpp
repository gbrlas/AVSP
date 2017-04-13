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
#define MN 1008
#define INF 100000007
#define eps 1e-7
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
double a[MN],b[MN];
int main()
{
    int t,pp;
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    sca(t);
    for(pp=1;pp<=t;pp++)
    {
        int n,i,j,k,Max=-INF,Max1=-INF;
        sca(n);
        for(i=0;i<n;i++) scanf("%lf",&a[i]);
        for(i=0;i<n;i++) scanf("%lf",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        for(i=n-1;i>=0;i--)
        {
            int sum=0;
            for(j=i,k=n-1;j>=0;j--,k--)
                if(a[k]>b[j]) sum++;
            Max=max(sum,Max);
        }
        for(i=n-1;i>=0;i--)
        {
            int sum=0;
            for(j=i,k=n-1;j>=0;j--,k--)
                if(b[k]>a[j]) sum++;
            Max1=max(sum,Max1);
        }
        printf("Case #%d: %d %d\n",pp,Max,n-Max1);
    }
    return 0;
}


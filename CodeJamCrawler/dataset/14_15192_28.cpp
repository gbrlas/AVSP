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
#define MM 16005
#define MN 40010
#define INF 1000000007
#define eps 1e-7
using namespace std;
typedef long long ll;
typedef unsigned long long ULL;

int main()
{
    int t,pp;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    sca(t);
    for(pp=1;pp<=t;pp++)
    {
        int i,j,k,n,m,sum=0,a[5][6],b[5][6];
        sca(n);
        set<int>s;
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
            {
                sca(a[i][j]);
                if(n==i) s.insert(a[i][j]);
            }
        sca(m);
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
            {
                sca(a[i][j]);
                if(m==i&&s.find(a[i][j])!=s.end()) {sum++;k=a[i][j];}
            }
        if(sum==1) printf("Case #%d: %d\n",pp,k);
        else if(sum>1) printf("Case #%d: Bad magician!\n",pp);
        else printf("Case #%d: Volunteer cheated!\n",pp);
    }
    return 0;
}


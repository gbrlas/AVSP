#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
template <class T> void out(T x, int n){  for(int i = 1; i <= n; ++i)  cout << x[i] << ' ';    cout << endl;    }
template <class T> void out(T x, int n, int m){  for(int i = 1; i <= n; ++i)    out(x[i], m);    cout << endl;    }
#define OUT(x) (cout << #x << " = " << x << endl)
#define  Set(a,b)  memset(a,b,sizeof(a))
#define  LL long long
#define  eps 1e-8
const int maxn = 1005,INF = 0x7fffffff;

int n,m;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int i,j,k,t,T,x,y,sum,index;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        scanf("%d%d",&n,&k);
        k%=(1<<n);
        if(k+1==(1<<n)) printf("Case #%d: ON\n",t);
        else printf("Case #%d: OFF\n",t);
    }
    return 0;
}

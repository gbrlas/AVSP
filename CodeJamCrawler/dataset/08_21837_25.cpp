#include	<cstdio>
#include	<cstdlib>
#include	<cstring>
#include	<string>
#include	<vector>
#include	<cmath>
#include	<algorithm>
#include	<cassert>
#include	<set>
#include	<map>
#include	<queue>
#include	<iostream>
#include <fstream>
using namespace std;
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);i++ ) 

typedef long long LL;
typedef pair<int,int> piii;


#define MAXN 1100000

int p[MAXN];
int prime(int n)
{
  int num = 0;
  bool a[MAXN];
  memset(a, 0, sizeof(a));
  for (int i=2;i<=n;i++)
  {
    if (!a[i]) p[num++] = i;
    for (int j=0;j<num&&i*p[j]<=n;j++)
    {
      a[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
  return num;
}

int r[MAXN];

inline int find(int t)
{
        //cout<<t<<' '<<r[t]<<endl;
        if (r[t]<0)
                return t;
        else
                return r[t]=find(r[t]);
}

inline void u(int i,int j)
{
        //cout<<"u"<<i<<' '<<j<<endl;
        if (find(i)!=find(j))
                r[find(i)]=find(j);
}

inline LL upper(LL i, int j)
{
        if (i%j==0)
                return i/j;
        else
                return i/j+1;
}
inline LL lower(LL i,int j)
{
        return i/j;
}

int main()
{
        LL res=0;
        int t=prime(1000000);
        int T;
        cin>>T;
        REP(tt,T)
        {
                LL A,B,P;
                cin>>A>>B>>P;
                memset(r,-1,sizeof r);
                REP(i,t)
                {
                        if (p[i]<P)
                                continue;
                        LL L=upper(A,p[i]);
                        LL R=lower(B,p[i]);
                        
                        if (L<=R)
                        //cout<<"p"<<i<<' '<<p[i]<<' '<<L<<' '<<R<<endl;
                        for (LL j=L;j<=R;j++)
                                u(L*p[i]-A,j*p[i]-A);
                }
                int res=0;
                for (LL i=A;i<=B;i++)
                        if (find(i-A)==i-A)
                        {
                                //cout<<i<<endl;
                                res++;
                        }
                printf("Case #%d: %d\n",tt+1,res);
                cerr<<tt<<endl;
        }
        return 0;
}


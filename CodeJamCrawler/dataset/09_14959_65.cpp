#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <string.h>
#include <memory.h>
using namespace std;
template <class T> void OUT(T x, int n){  for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;    }
template <class T> void OUT(T x, int n, int m){  for(int i = 1; i <= n; ++i)    out(x[i], m);    cout << endl;    }
template <class T> void checkmod(T& a,T m){ a=(a%m+m)%m;}
#define  eps 1e-8
#define  LL long long
inline LL mod(LL x, LL y) { return x - floor(1.0 * x / y+eps) * y; }
#define  out(x) (cout << #x << " = " << x << endl)
#define  Set(a,b)  memset(a,b,sizeof(a))
#define  Sqr(x) ((x) * (x))
#define  pi  acos(-1.0)
const int maxn = 100005,INF = 0x7fffffff;

int n,m;
char in[maxn];
int change[40];
int flag[40];
int num[maxn],len;
LL solve(int r)
{
     int i;
     LL ret=0;
     for(i=0;i<len;i++)
     {
         ret=ret*(LL)r+(LL)num[i];
     }
     return ret;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,t,T,x,y,sum,index;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        for(i=0;i<=36;i++)
          change[i]=-1;
        Set(flag,0);
        scanf("%s",in);
//        cout<<in<<endl;
        len=strlen(in);
        for(i=0;i<len;i++)
        {
           if(in[i]>='0'&&in[i]<='9')
           {
                if(i!=0)
                {
                    if(change[in[i]-'0']==-1)
                    {
                        for(j=0;j<36;j++)
                            if(flag[j]==0)
                            {
                               change[in[i]-'0']=j;
                               flag[j]=1;
                               num[i]=j;
                               break;
                            }
                    }
                    else num[i]=change[in[i]-'0'];
                }
                else
                {
                    num[i]=1;
                    flag[1]=1;
                    change[in[i]-'0']=1;
                }
           }
           else
           {
                if(i!=0)
                {
                    if(change[in[i]-'a'+10]==-1)
                    {
                        for(j=0;j<36;j++)
                            if(flag[j]==0)
                            {
                               change[in[i]-'a'+10]=j;
                               flag[j]=1;
                               num[i]=j;
                               break;
                            }
                    }
                    else num[i]=change[in[i]-'a'+10];
                }
                else
                {
                    num[i]=1;
                    flag[1]=1;
                    change[in[i]-'a'+10]=1;
                }
           }
        }
//        OUT(num,len);
        int r=2;
        for(i=0;i<len;i++)
          r=max(num[i]+1,r);
        LL ans=solve(r);
        printf("Case #%d: ",t);
        cout<<ans<<endl;
    }
    return 0;
}

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
template <class T> void OUT(T x, int n){  for(int i = 1; i <= n; ++i)  cout << x[i] << ' ';    cout << endl;    }
template <class T> void OUT(T x, int n, int m){  for(int i = 1; i <= n; ++i)    out(x[i], m);    cout << endl;    }
template <class T> void checkmod(T& a,T m){ a=(a%m+m)%m;}
#define  eps 1e-8
#define  LL long long
inline LL mod(LL x, LL y) { return x - floor(1.0 * x / y+eps) * y; }
#define  out(x) (cout << #x << " = " << x << endl)
#define  Set(a,b)  memset(a,b,sizeof(a))
#define  Sqr(x) ((x) * (x))
#define  pi  acos(-1.0)
const int maxn = 1005,INF = 0x7fffffff;

int n,m;
int main()
{
    freopen("in.IN","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,T,t,sum,index;
    cin>>T;
    double x,y,z,vx,vy,vz;

    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        double X=0,Y=0,Z=0,VX=0,VY=0,VZ=0;
        for(i=1;i<=n;i++)
        {
           scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&z,&vx,&vy,&vz);
           X+=x;Y+=y;Z+=z,VX+=vx,VY+=vy,VZ+=vz;
        }
//        out(X);out(Y);out(Z);out(VX);out(VY);out(VZ);
        double t_,d;
//        out((VX*X+VY*Y+VZ*Z));
//        out((VX*VX+VY*VY+VZ*VZ));
        if((VX*VX+VY*VY+VZ*VZ)!=0) t_=-1.0*(VX*X+VY*Y+VZ*Z)/(VX*VX+VY*VY+VZ*VZ);
        else t_=0;
        if(t_<0) t_=0;
        d=Sqr(X+VX*t_)+Sqr(Y+VY*t_)+Sqr(Z+VZ*t_);
//        out(d);
        if(d<=eps) printf("Case #%d: 0.00000000 %.8lf\n",t,t_);
        else printf("Case #%d: %.8lf %.8lf\n",t,sqrt(d)/n,t_);
    }
    return 0;
}

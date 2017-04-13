#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn=510;
double x[maxn], y[maxn], z[maxn], vx[maxn], vy[maxn], vz[maxn];
double X, Y, Z, VX, VY, VZ, A, B, C, T, dis;
int main(void)
{
    int t, n;
    freopen("B-small-attempt2.in","r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);

    scanf("%d", &t);
    for (int ca=1; ca<=t; ca++)
    {
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
        {
            scanf("%lf%lf%lf%lf%lf%lf", &x[i], &y[i], &z[i], &vx[i], &vy[i], &vz[i]);
        }
        VX=VY=VZ=X=Y=Z=0;
        for (int i=1; i<=n; i++)
        {
            X+=x[i];
            Y+=y[i];
            Z+=z[i];
            VX+=vx[i];
            VY+=vy[i];
            VZ+=vz[i];
        }
   //     X/=n, Y/=n, Z/=n, VX/=n, VY/=n, VZ/=n;
        A = VX*VX + VY*VY + VZ*VZ;
        B = 2 * ( X*VX + Y*VY + Z*VZ);
        C = X*X + Y*Y + Z*Z;
        dis=0, T=0;
     //   cout<<A<<' '<<B<<' '<<C<<endl;
        if (A==0)
        {
            dis = sqrt(X*X + Y*Y + Z*Z)/n;
            printf("Case #%d: %.8lf %.8lf\n", ca, dis, 0);
            continue;
        }
        T=B/2.0/A;
        if (T>0) T=0;
        if (T==0) dis=sqrt(X*X + Y*Y + Z*Z)/n;
        else {
          //  if (C - B*B/4.0/A<0) dis=0;
            dis=sqrt(C - B*B/4.0/A)/n;
        }
        printf("Case #%d: %.8lf %.8lf\n", ca, dis, -T);
    }
    
    return 0;
}

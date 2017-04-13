#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;



double x[1000] , y[1000] , z[1000] , vx[1000] , vy[1000] , vz[1000] , n;
int i,  j,  k;

int main()
{
    freopen("d:/input.txt" , "r" , stdin);
    freopen("d:/output.txt" , "w" , stdout);

	int t;
    cin>>t;
	int i;
    for (int tt = 1; tt <= t; tt++)
    {
       cin>>n;
	   double xx = 0 , yy = 0 , zz  = 0 , vxx = 0 , vyy = 0 , vzz = 0;
	   for (i = 0; i < n; i++)
	   {
		   cin>>x[i]>>y[i]>>z[i]>>vx[i]>>vy[i]>>vz[i];
		   xx += x[i];
		   yy += y[i];
		   zz += z[i];

		   vxx += vx[i];
		   vyy += vy[i];
		   vzz += vz[i];	
	   }
	   xx /= n;
	   yy /= n;
	   zz /= n;

	   vxx /= n;
	   vyy /= n;
	   vzz /= n;
	
		double t = 0;
		if (vxx*vxx + vyy*vyy + vzz * vzz < 1e-9); else
	    t = (-vxx*xx - vyy*yy - vzz*zz) / (vxx*vxx + vyy*vyy + vzz*vzz);

		if (t < 1e-9)
			t = 0;
	   
		double d = (xx + vxx*t)*(xx + vxx*t) + (yy + vyy*t)*(yy + vyy*t) + (zz + vzz*t)*(zz + vzz*t);
	    d = sqrt(d);
		

	   printf("Case #%d: %.8lf %.8lf\n" , tt , d , t);
        
    }

    return 0;
}
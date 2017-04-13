#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x,y,z,vx,vy,vz,ans,tx,ty,tz,tvy,tvx,tvz;
	int n,T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++) {
		ans=0.0;
		scanf("%d",&n);
		x=y=z=vx=vy=vz=0.0;
		for(int i=0;i<n;i++) {
			scanf("%lf %lf %lf %lf %lf %lf",&tx,&ty,&tz,&tvx,&tvy,&tvz);
			x += tx;
			y += ty;
			z += tz;
			vx += tvx;
			vy += tvy;
			vz += tvz;
		}
		double time = -(x*vx+y*vy+z*vz)/(vx*vx+vy*vy+vz*vz);
		if(vx==0.0 && vy==0.0 && vz==0.0)
			time = 0.0;
		if(time < 0.0) time = 0.0;
		double sum = (x*x+y*y+z*z+2*time*(x*vx+y*vy+z*vz)+time*time*(vx*vx+vy*vy+vz*vz));
		double minD = sqrt(sum)/(n*1.0);
		if(sum<0.0) minD = 0.0;
		if(minD == -0.0) minD = 0.0;
		if(time == -0.0) time = 0.0;
		printf("Case #%d: %0.8lf %0.8lf\n",t,minD,time);
	}
	return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cc;
	long long a,b,c,d,e,f;
	cin>>cc;
	for(int zz=1;zz<=cc;++zz)
	{
		int n;
		long long x=0,y=0,z=0,vx=0,vy=0,vz=0;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b>>c>>d>>e>>f;
			x+=a;
			y+=b;
			z+=c;
			vx+=d;
			vy+=e;
			vz+=f;
		}
		double t;
		if(vx*vx+vy*vy+vz*vz==0) t=0;
		else t=(-x*vx-y*vy-z*vz)/double(vx*vx+vy*vy+vz*vz);
		if(t<0) t=0;
		double dx=(vx*t+x)/n,dy=(vy*t+y)/n,dz=(vz*t+z)/n;
		double d=sqrt(dx*dx+dy*dy+dz*dz);
		printf("Case #%d: %.8lf %.8lf\n",zz,d,t);
	}
	return 0;
}


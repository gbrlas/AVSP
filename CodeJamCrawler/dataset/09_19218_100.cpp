#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
int main()
{
	int i,j,n;vector <double> outd,outt;cin>>n;
	for(i=0;i<n;i++){
		int a,b,c,d,e,f,m;
		double nx=0.0,ny=0.0,nz=0.0,vx=0.0,vy=0.0,vz=0.0,x=0.0,y=1e10,dis1,dis2;
		cin>>m;
		for(j=0;j<m;j++){
			cin>>a>>b>>c>>d>>e>>f;
			nx+=a;ny+=b;nz+=c;vx+=d;vy+=e;vz+=f;
		}
		nx/=m;ny/=m;nz/=m;vx/=m;vy/=m;vz/=m;
		for(j=0;j<1000;j++){
			double l=(2*x+y)/3,r=(x+2*y)/3;
			dis1=sqrt((nx+l*vx)*(nx+l*vx)+(ny+l*vy)*(ny+l*vy)+(nz+l*vz)*(nz+l*vz));
			dis2=sqrt((nx+r*vx)*(nx+r*vx)+(ny+r*vy)*(ny+r*vy)+(nz+r*vz)*(nz+r*vz));
			if(dis1>dis2) x=l;else y=r;
		}
		outt.pb((x+y)/2);
		outd.pb(sqrt((nx+outt[i]*vx)*(nx+outt[i]*vx)+(ny+outt[i]*vy)*(ny+outt[i]*vy)+(nz+outt[i]*vz)*(nz+outt[i]*vz)));
	}
	for(i=0;i<n;i++) cout<<"Case #"<<i+1<<": "<<outd[i]<<' '<<outt[i]<<'\n';
	return 0;
}

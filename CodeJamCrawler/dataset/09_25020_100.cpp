#include<iostream>
#include<string>
#include<cmath>

using namespace std;

double dis(double a,double b,double c){
	return sqrt(a*a+b*b+c*c);
}

int main(){
	freopen("out.out","w",stdout);
	int i,len,cs,CSN,cnt;
	int N;
	double d,dt,pos[600][3],v[600][3],x,y,z,vx,vy,vz,nowx,nowy,nowz,t;

	scanf("%d",&CSN);

	for(cs=1;cs<=CSN;cs++){
		printf("Case #%d: ",cs);
		scanf("%d",&N);
		x = y = z = 0;
		vx = vy = vz = 0;
		for(i=0;i<N;i++){
			scanf("%lf%lf%lf%lf%lf%lf",&pos[i][0],&pos[i][1],&pos[i][2],&v[i][0],&v[i][1],&v[i][2]);
			x += pos[i][0]; y += pos[i][1]; z += pos[i][2];
			vx += v[i][0]; vy += v[i][1]; vz += v[i][2];
		}
		
		
		if(fabs(vx*vx+vy*vy+vz*vz)<1E-8){
			t = 0;
		}
		else{
			t = -(2*x*vx+2*y*vy+2*z*vz)/2/(vx*vx+vy*vy+vz*vz);
			if(fabs(t)<1E-8||t<0)
				t = 0;

		}
		printf("%.8lf %.8lf\n",dis((x+vx*t)/N,(y+vy*t)/N,(z+vz*t)/N),t);
	}

}
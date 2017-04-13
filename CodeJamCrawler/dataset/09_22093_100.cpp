#include<cstdio>
#include<cmath>

double inf=1e20;

struct pt{
	double x, y, z;
	pt(double X=0, double Y=0, double Z=0):x(X),y(Y),z(Z){}
	void div(double w){ x/=w; y/=w; z/=w; }
};

pt operator + (pt a, pt b){
	return pt( a.x+b.x, a.y+b.y, a.z+b.z);
}

pt cent, Vcent;

double d(double t){
	pt p=cent + pt(Vcent.x*t, Vcent.y*t, Vcent.z*t);
	return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}

bool zero(){
	return Vcent.x==0. && Vcent.y==0. && Vcent.z==0;
}

void go(){
	double l=0, r=inf,res;
	if(zero()) res=0;
	else{
		for(int i=0; i<1000000; i++){
			//printf("%lf %lf %lf\n",l,r,r-l);
			double p=l+ (r-l)/3., q=l+2*(r-l)/3.;
			if(d(p)<d(q)){
				r=q;
			}
			else l=p;
		}
		res=(l+r)/2.;
	}
	if(d(0)<d(res))res=0.;
	//printf("\n%lf %lf %lf, %lf %lf %lf\n",cent.x, cent.y, cent.z,
	//Vcent.x, Vcent.y, Vcent.z);
	//printf("%lf\n", d(0));
	printf("%lf %lf\n", d(res), res);
}

main(){
	int t;
	scanf("%d",&t);
	for(int c=1; c<=t; c++){
		int n; scanf("%d",&n);
		cent=pt(0,0,0); Vcent=pt(0,0,0);
		double x,y,z,vx,vy,vz;
		for(int i=0; i<n; i++){
			scanf("%lf %lf %lf",&x,&y,&z);
			cent=cent+pt(x,y,z);
			scanf("%lf %lf %lf",&vx,&vy,&vz);
			Vcent=Vcent+pt(vx,vy,vz);
		}
		cent.div(n); Vcent.div(n);
		printf("Case #%d: ", c);
		go();
	}
}

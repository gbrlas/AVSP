#include <cstdio>
#include <cstring>
#include <cmath>
#define REP(i,n) for(int i = 0;i<n;i++)
#define LD long double

using namespace std;

LD il_skal(LD a, LD b, LD c, LD x, LD y, LD z) {
	return a*x+b*y+c*z;
}

LD len(LD a, LD b, LD c) {
	return a*a+b*b+c*c;
}

int main() {
	int T;
	scanf("%d", &T);
	LD t[1000][6];
	REP(z,T) {
		printf("Case #%d: ", z+1);
		int n;
		scanf("%d", &n);
		REP(i,n) REP(j,6) scanf("%Lf", &t[i][j]);
		LD p[3], v[3];
		REP(i,3) p[i]=v[i]=0;
		REP(i,n) {
			REP(j,3) p[j]+=t[i][j];
			REP(j,3) v[j]+=t[i][3+j];
		}
		REP(i,3) {p[i]/=n; v[i]/=n;}
		if(il_skal(v[0],v[1],v[2],-p[0],-p[1],-p[2])<=0) {
			printf("%.8Lf 0.00000000\n", sqrt(len(-p[0],-p[1],-p[2])));
			continue;
		}
		LD p1=il_skal(v[0],v[1],v[2],-p[0],-p[1],-p[2]);
		p1/=sqrt(len(-p[0],-p[1],-p[2]));
		LD p3 = len(v[0],v[1],v[2])-p1*p1;
		LD res = p3*len(-p[0],-p[1],-p[2]);
		res/=len(v[0],v[1],v[2]);
		if(res<0.0) res=0.0;
		printf("%.8Lf ", sqrt(res));
		LD czas = il_skal(-p[0],-p[1],-p[2],v[0],v[1],v[2])/len(v[0],v[1],v[2]);
		printf("%.8Lf\n", czas);
	}
	return 0;
}

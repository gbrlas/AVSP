#include <cstdio>

const double eps=1e-8;

struct point{
	double x,y;
};

point p1[110],p2[110];
double sum1[110],sum2[110];
int L,U,G;

double count( double x ){
	double ret=0;
	for ( int i=0; i<L; ++i )
		if ( p1[i].x>x ){
			ret-=sum1[i-1];
			if ( p1[i].x>p1[i-1].x )
				ret-=(p1[i-1].y+p1[i-1].y+(p1[i].y-p1[i-1].y)*(x-p1[i-1].x)/(p1[i].x-p1[i-1].x))*(x-p1[i-1].x)/2;
			break;
		}
	for ( int i=0; i<U; ++i )
		if ( p2[i].x>x ){
			ret+=sum2[i-1];
			if ( p2[i].x>p2[i-1].x )
				ret+=(p2[i-1].y+p2[i-1].y+(p2[i].y-p2[i-1].y)*(x-p2[i-1].x)/(p2[i].x-p2[i-1].x))*(x-p2[i-1].x)/2;
			break;
		}
	return ret;
}

int main(){
//	freopen("a.in","r",stdin);
	int test=0;
	scanf("%d",&test);
	for ( int T=1; T<=test; ++T ){
		scanf("%d%d%d%d",&L,&L,&U,&G);
		sum1[0]=0;
		for ( int i=0; i<L; ++i ){
			scanf("%lf%lf",&p1[i].x,&p1[i].y);
			if (i)
				sum1[i]=sum1[i-1]+(p1[i].y+p1[i-1].y)*(p1[i].x-p1[i-1].x)/2;
		}
		for ( int i=0; i<U; ++i ){
			scanf("%lf%lf",&p2[i].x,&p2[i].y);
			if (i)
				sum2[i]=sum2[i-1]+(p2[i].y+p2[i-1].y)*(p2[i].x-p2[i-1].x)/2;
		}
		double sum=(sum2[U-1]-sum1[L-1])/G;
		double now=0;
		printf("Case #%d:\n",T);
		for ( int i=0; i<G-1; ++i ){
			double l=now,r=p1[L-1].x,re=now;
			while (l+eps<r){
				double m=(l+r)/2;
				if ( count(m)>sum+i*sum ){
					re=m;
					r=m-eps;
				}else
					l=m+eps;
			}
			printf("%.6lf\n",l);
			now=l;
		}
	}
}

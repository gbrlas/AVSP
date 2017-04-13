#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct l{
	int s,t;
	double v;
};

l p[1010],pp[10010];
int n,np;
int x,s,r,t;

bool cmp( l p1, l p2 ){
	return p1.s<p2.s;
}

bool cmp1( l p1, l p2 ){
	return p1.v<p2.v;
}

int main(){
	int test=0;
	scanf("%d",&test);
	for ( int T=1; T<=test; ++T ){
		printf("Case #%d: ", T);
		scanf("%d %d %d %d %d",&x,&s,&r,&t,&n);
		r=r-s;
		for ( int i=0; i<n; ++i )
			scanf("%d %d %lf", &p[i].s, &p[i].t, &p[i].v);
		sort(p,p+n,cmp);
		np=1;
		pp[0].s=0; pp[0].t=p[0].s;
		pp[0].v=s;
		for ( int i=1; i<n; ++i ){
			pp[np].s=p[i-1].t;
			pp[np].t=p[i].s;
			pp[np].v=s;
			++np;
		}
		pp[np].s=p[n-1].t;
		pp[np].t=x;
		pp[np].v=s;
		++np;
		for ( int i=0; i<n; ++i ){
			pp[np++]=p[i];
			pp[np-1].v+=s;
		}
		sort(pp,pp+np,cmp1);
		double tot=0,ans=0;
		for ( int i=0; i<np; ++i ){
			//printf("%d %d %.2lf\n", pp[i].s, pp[i].t, pp[i].v);
			if ( pp[i].t>pp[i].s ){
				double tt=(pp[i].t-pp[i].s)/(pp[i].v+r);
				if ( tt>t-tot ){
					if ( tot==t )
						tt=(pp[i].t-pp[i].s)/pp[i].v;
					else{
						tt=((pp[i].t-pp[i].s)-(pp[i].v+r)*(t-tot))/pp[i].v+t-tot;
						tot=t;
					}
				} else
					tot+=tt;
				//printf("%.4lf %.4lf\n",tt,t-tot);
				ans+=tt;
			}
		}
		printf("%.8lf\n",ans);
	}
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define eps 1e-9

struct point{
	double x,y;
	point operator-(point a){
		point ans=(*this);
		ans.x-=a.x;
		ans.y-=a.y;
		return ans;
	}
};

double cross(point a,point b){
	return a.y*b.x-a.x*b.y;
}

bool zero(double a){
	if(a<0)a=-a;
	return a<eps;
}

point cut(point a,point b,double l){
	if(b.x<a.x)
		swap(a,b);
	if(l>=b.x)
		return b;
	if(l<=a.x)
		return a;
	point ans;
	ans.x=l;
	ans.y=a.y+((b.y-a.y)*(l-a.x)/(b.x-a.x));
	return ans;
}

double ar(point a,point b){
	return (a.y+b.y)*(b.x-a.x)/2;
}

double arlr(point a,point b,double l,double r){
	if(l>=b.x)
		return 0;
	if(r<=a.x)
		return 0;
	point ta=a,tb=b;
	if(l>a.x)
		ta=cut(a,b,l);
	if(r<b.x){
		//printf("%lf %lf %lf\n",a.x,b.x,r);
		tb=cut(a,b,r);
	}
	return ar(ta,tb);
}



struct line{
	int n;
	point p[1000];
	double alr(double l,double r){
		double ans=0;
		int i;
		for(i=1;i<n;i++){
			//printf("%lf %lf %lf %lf %lf\n",l,r,p[i].x,p[i+1].x,arlr(p[i],p[i+1],l,r));
			ans+=arlr(p[i],p[i+1],l,r);
		}
		return ans;
	}
}up,low;

double cutmid(double l,double r){
	return up.alr(l,r)-low.alr(l,r);
}

double w,lowest;

int i,j,n,m;

int main(){
	int ii,nn;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d:\n",ii);
		scanf("%lf %d %d %d",&w,&low.n,&up.n,&n);
		for(i=1;i<=low.n;i++){
			scanf("%lf %lf",&low.p[i].x,&low.p[i].y);
			//low.p[i].y+=1001;
		}
		for(i=1;i<=up.n;i++){
			scanf("%lf %lf",&up.p[i].x,&up.p[i].y);
			//up.p[i].y+=1001;
		}
		double all=cutmid(0,w),last=0,l,r,mid,temp;
		all/=n;
		//printf("%lf\n",cutmid(5,13));
		//printf("aaa\n ");
		//printf("%lf\n",cutmid(5,15));
		for(i=1;i<n;i++){
			l=last+eps,r=w;
			for(j=1;j<=64;j++){
				mid=(l+r)/2;
				temp=cutmid(last,mid);
				if(temp<all)
					l=mid;
				else 
					r=mid;
			}
			printf("%.8lf\n",last=mid);
		}
	}
	return 0;
}

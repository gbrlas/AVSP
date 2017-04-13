#include <iostream>
#include <cmath>
#include <algorithm>
struct Circle{
	double x,y,r;
};
double min(double a,double b){
	return a<b?a:b;
}
double max(double a,double b){
	return a>b?a:b;
}
double dis(const Circle &a,const Circle &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
Circle g[30];
int main()
{
	int T,i,n;
	double ans,min_dist,max_dist,dist1,dist2,dist3;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf",&g[i].x,&g[i].y,&g[i].r);
		if(n==1){
			printf("Case #%d: %lf\n",ca,g[0].r);
			continue;
		}
		else if(n==2){
			ans = max(g[0].r,g[1].r);
			printf("Case #%d: %lf\n",ca,ans);
			continue;
		}
		else if(n==3){
			dist1 = max(2*g[0].r, dis(g[1],g[2])+g[1].r+g[2].r);
			dist2 = max(2*g[1].r, dis(g[0],g[2])+g[0].r+g[2].r);
			dist3 = max(2*g[2].r, dis(g[0],g[1])+g[0].r+g[1].r);
			ans = min(dist1,min(dist2,dist3))/2;
			printf("Case #%d: %lf\n",ca,ans);
			continue;
		}
	}
}
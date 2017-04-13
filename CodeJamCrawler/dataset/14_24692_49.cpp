#include<stdio.h>
double ans;
int tc,tcn;
double c,f,x;
int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int i;
	double bans,ans;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%lf%lf%lf",&c,&f,&x);
		bans=0;
		for(i=0;;i++){
			ans=bans+c/(f*i+2);
			if(bans+x/(f*i+2)<ans+x/(f*(i+1)+2))break;
			bans=ans;
		}
		printf("Case #%d: %.7lf\n",tc,bans+x/(f*i+2));
	}
}
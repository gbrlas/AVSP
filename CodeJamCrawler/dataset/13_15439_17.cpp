#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int tqn,tqi,n,i,j,q,zer;
long long b,paid,a[50],can_add,give_up,g[50];
double ret;

int main (int argc, char * const argv[]) {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	for(tqi=1;tqi<=tqn;tqi++){
		scanf("%lld%d",&b,&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			g[i]=0;
		}
		for(i=n+1;i<=37;i++)a[i]=g[i]=0;
		sort(a+1,a+38);
		a[38]=100000000000000LL;
		paid=0;
		ret=0.0;
		for(i=1;i<=37;i++)if(a[i]!=a[i+1]){
			for(j=1;j<=i;j++){
				paid+=a[i]-a[j];
				g[j]+=a[i]-a[j];
				a[j]=a[i];
			}
			if(paid>b)break;
			for(zer=0;zer<i;zer++)if(paid+zer<=b){
				give_up=0;
				for(j=1;j<=zer;j++)give_up+=g[i-j+1];
				can_add=min(a[i+1]-a[i]-1,(b-paid-zer)/i);
				for(j=0;j<=can_add;j++){					
					ret=max(ret,36*((1.0*paid-give_up)/(1.0*(i-zer)))-(paid+zer));
					if(ret>20000){
						n^=1;
						n^=1;
					}
					if(j!=can_add)for(q=1;q<=i;q++){
						++a[q];
						++g[q];
						++paid;
					}
					give_up+=zer;
				}
				if(zer!=i-1)for(q=1;q<=i;q++){
					a[q]-=can_add;
					g[q]-=can_add;
					paid-=can_add;
				}
			}
		}
		printf("Case #%d: %.14lf\n",tqi,ret);
	}
    return 0;
}

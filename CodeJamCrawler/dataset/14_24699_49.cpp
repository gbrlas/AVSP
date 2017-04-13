#include<stdio.h>
#include<algorithm>
int n;
double a[100000];
double b[100000];
int tcn,tc;
int aans,bans;
int solve(){
	int i,j;
	i=j=0;
	while(j!=n){
		if(a[i]<b[j]){
			i++;
			j++;
		}
		else{
			j++;
		}
	}
	return j-i;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i;
	double tmp;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lf",&a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%lf",&b[i]);
		}
		std::sort(a,a+n);
		std::sort(b,b+n);
		bans=solve();
		for(i=0;i<n;i++){
			tmp=a[i];
			a[i]=b[i];
			b[i]=tmp;
		}
		aans=n-solve();
		printf("Case #%d: %d %d\n",tc,aans,bans);
	}
}
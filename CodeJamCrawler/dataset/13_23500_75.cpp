#include<stdio.h>
long long int list[20010000];
int llen;
int tc;
int pal(long long int n){
	int i,j;
	long long int a;
	int b[20];
	a=n;
	for(i=0;a;i++){
		b[i]=a%10;
		a/=10;
	}
	for(j=0;j<i;j++){
		if(b[j]!=b[i-j-1])return 0;
	}
	return 1;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long int i,j,a,b,ans;
	for(i=0;i<10001000;i++){
		if(pal(i)==1&&pal(i*i)==1){
			list[llen]=i*i;
			llen++;
		}
	}
	scanf("%d",&tc);
	int tcn;
	for(tcn=1;tcn<=tc;tcn++){
		scanf("%lld%lld",&a,&b);
		ans=0;
		for(i=0;i<llen;i++){
			if(list[i]>=a&&list[i]<=b)ans++;
		}
		printf("Case #%d: %lld\n",tcn,ans);
	}
}
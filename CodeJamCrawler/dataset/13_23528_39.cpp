#include<stdio.h>
int tc,tcn;
long long int k=1;
long long int f(int n,long long int p){
	if(n==0)return 0;
	if(p==(k<<n))return p-1;
	if(p<=(k<<(n-1)))return 0;
	return f(n-1,p-(k<<(n-1)))*2+2;
}
long long int g(int n,long long int p){
	if(n==0)return 0;
	if(p==(k<<n))return p-1;
	if(p>(k<<(n-1)))return (k<<(n))-2;
	return g(n-1,p)*2;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i;
	int n;
	long long int p;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%lld",&n,&p);
		if((k<<n)==p)printf("Case #%d: %lld %lld\n",tc,p-1,p-1);
		else printf("Case #%d: %lld %lld\n",tc,f(n,p),g(n,p));
	}
}
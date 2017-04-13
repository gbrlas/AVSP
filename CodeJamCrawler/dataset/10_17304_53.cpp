#include<stdio.h>
int gcd(int a,int b){
	int t;
	while(b)t=a%b,a=b,b=t;
	return a;
}
int main(){
	int a[4];
	int c,C,N,i,min,m;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&C);
	for(c=1;c<=C;c++){
		scanf("%d",&N);
		for(i=0,min=0x7fffffff;i<N;i++){
			scanf("%d",&a[i]);
			if(a[i]<min)min=a[i];
		}
		for(i=0;i<N;i++)a[i]-=min;
		m=gcd(a[0],a[1]);
		for(i=2;i<N;i++)m=gcd(m,a[i]);
		min%=m;
		
		printf("Case #%d: %d\n",c,min?m-min:0);
	}
	fflush(stdout);
	return 0;
}

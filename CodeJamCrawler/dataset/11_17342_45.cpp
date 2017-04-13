#include<stdio.h>
int main(){
	int min,sum;
	int i,n;
	int T,t = 0;
	int a,S;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("Snail.out","w",stdout);
	scanf("%d",&T);
	while(++t<=T)
	{
		scanf("%d",&n);
		S = sum = 0;
		min = 1000001;
		while(n--){
			scanf("%d",&a);
			S ^= a;
			sum += a;
			if(a < min)min = a;
		}
		if(S)printf("Case #%d: NO\n",t);
		else printf("Case #%d: %d\n",t,sum-min);
			
	}
	
	return 0;
} 

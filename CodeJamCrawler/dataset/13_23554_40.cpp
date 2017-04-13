#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define maxn 10000100
typedef  int LL;

int vis[maxn];

int judge(LL x) {
	int dit[20];
	int cnt=0;
	do {
		dit[cnt++] = x % 10;
		x /= 10;
	}while(x > 0);
	int i;

	for(i = 0;i <= (cnt-1)/2; i++)
		if(dit[i] != dit[cnt-1-i])
			return 0;
	return 1;
}

int main() {
	

	LL i;
	LL end = 1000;
	LL end2 = 31;
	LL sq;
	memset(vis,0,sizeof(vis));
	vis[1] = 1;
	for(i = 2; i <= end2; i++) {
		sq = i*i;
		if(judge(i) && judge(sq))
			vis[sq] = 1;
	}
	
	int T,t;
	LL a,b;
	LL ans;
	while(scanf("%d",&T) == 1) {
		for(t = 1; t <= T; t++) {
			printf("Case #%d: ",t);
			scanf("%d %d",&a,&b);
			ans = 0;
			for(i = a; i <= b; i++)
				if(vis[i]) {
					ans++;
				}
			printf("%d\n",ans);
		}
	}
	
	
 	return 0;
}




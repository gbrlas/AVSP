#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Plant {
	int x,y,r;
};

Plant p[3];

double Dis(int a, int b) {
	return sqrt((double)(p[a].x-p[b].x)*(p[a].x-p[b].x) + (p[a].y-p[b].y)*(p[a].y-p[b].y));
}

int main() {
	int C,cas=1,i,j,N;
	double ans,tmp;
	
	freopen("testD.in", "r", stdin);
	freopen("testD.out", "w", stdout);
	scanf("%d", &C);
	while(C--) {
		scanf("%d", &N);
		for(i=0; i<N; i++)
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].r);
		if(N == 1)
			printf("Case #%d: %f\n", cas++, (double)p[0].r);
		else if(N == 2)
			printf("Case #%d: %f\n", cas++, (double)p[0].r>?p[1].r);
		else {
			ans = 1000000000.0;
			tmp = 1000000000.0;
			tmp = (Dis(0,1)+p[0].r+p[1].r)/2.0 >? p[0].r >? p[1].r>? p[2].r;
			ans <?= tmp;
			tmp = (Dis(1,2)+p[1].r+p[2].r)/2.0 >? p[0].r >? p[1].r>? p[2].r;
			ans <?= tmp;
			tmp = (Dis(0,2)+p[0].r+p[2].r)/2.0 >? p[0].r >? p[1].r>? p[2].r;
			ans <?= tmp;
			printf("Case #%d: %f\n", cas++, ans);
		}
	}
	return 0;
}
		
			
		
	

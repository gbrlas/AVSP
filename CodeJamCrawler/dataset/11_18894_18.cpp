#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

typedef struct node{
	int start;
	int end;
	double spd;
}node,*NODE;

int comp(const void* a,const void* b){
	NODE x, y;
	x = (NODE)a,y = (NODE)b;
	if (x->spd > y->spd){
		return 1;
	}else if (x->spd < y->spd){
		return -1;
	}else{
		return x->start - y->start;
	}
}

node list[1024];

int main(int argc, char *argv[])
{
	int T = 0, cas = 1;
	
	double X,S,R,t;
	int N;
	int remain = 0;

	scanf("%d", &T);
	while (T--){
		double res = 0;
		scanf("%lf %lf %lf %lf %d", &X, &S, &R, &t, &N);
		remain = X;
		for (int i = 0; i<N; i++){
			scanf("%d %d %lf", &list[i].start, &list[i].end, &list[i].spd);
			remain -= (list[i].end - list[i].start);
		}
		
		qsort(list, N, sizeof(node), comp);
		double usage = remain / R;
		if (usage > t){
			usage = t;
		}
		t -= usage;
		res += usage + (remain - usage * R)/S;

		for (int i = 0; i<N; i++){
			double usage = (list[i].end - list[i].start)/(list[i].spd + R);
			if (usage >= t){
				usage = t;
			}
			t -= usage;
			res += usage + (list[i].end - list[i].start - usage * (list[i].spd+R))/(list[i].spd+S);
		}

		printf("Case #%d: %.7lf\n", cas++, res);
	}
	return 0;
}

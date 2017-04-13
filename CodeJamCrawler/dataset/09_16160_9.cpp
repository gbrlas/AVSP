#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char happy[11][100000],exist[100000];

int Convertb(int a, int num[], int B) {
	int i,len=0;
	
	while(a != 0) {
		num[len++] = a % B;
		a /= B;
	}
	return len;
}

int Square(int a, int B) {
	int i,x=0,num[100],len;
	
	len = Convertb(a, num, B);
	for(i=0; i<len; i++)
		x += num[i] * num[i];
	return x;
}

char Happy(int a, int B) {
//	printf("%d %d\n", a, B);
//	system("PAUSE");
	if(a == 1)
		return 1;
	if(happy[B][a] != -1)
		return happy[B][a];
	if(exist[a] == 1) {
		happy[B][a] = 0;
		return 0;
	}
	exist[a] = 1;
	happy[B][a] = Happy(Square(a,B), B);
	return happy[B][a];
}

int main() {
	int T,B,x,n[9],i,j,cas=1,N;
	
	
	freopen("testA.in", "r", stdin);
	freopen("testA.out", "w", stdout);
	memset(happy, 0xff, sizeof(happy));
	for(B=2; B<=10; B++) {
		for(i=2; i<=100000; i++) {
			memset(exist, 0, sizeof(exist));
			happy[B][i] = Happy(i, B);	
		}
	}
	scanf("%d", &T);
	while(1) {
		printf("Case #%d: ", cas);
		N = 0;
		while(1) {
			scanf("%d", &n[N]);
	//		printf("\n[%d]\n", n[N]);
			N++;
			if(getchar() == '\n')
				break;
		}
		for(i=2; ; i++) {
			for(j=0; j<N; j++)
				if(happy[n[j]][i] == 0)
					break;
			if(j >= N) {
				printf("%d", i);
				break;
			}
		}
		printf("\n");
		if(cas == T)
			break;
		cas++;
	}
	return 0;
}	
	
	

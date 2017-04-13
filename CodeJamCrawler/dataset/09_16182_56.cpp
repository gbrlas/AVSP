#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {
	int T,N,num[30],i,j,cas=1,min,n;
	char tmp;
		
	freopen("testB.in", "r", stdin);
	freopen("testB.out", "w", stdout);
	scanf("%d", &T);
	getchar();
	while(1) {		
		N = 0;
		while((tmp = getchar()) != '\n')
			num[N++] = tmp;
		
		for(i=N-1; i>=0; i--) {
			min = 1000000;
			n = -1;
			for(j=i+1; j<N; j++) {
				if(num[j] > num[i] && num[j] < min) {
					n = j;
					min = num[j];
				}				
			}
			if(n != -1) {
				swap(num[n], num[i]);
				sort(&num[i+1], &num[N]);
				break;
			}
		}
		if(i < 0) {
			min = 10000000;
			for(j=0; j<N; j++) {
				if(num[j] < min && num[j] != '0') {
					n = j;
					min = num[j];
				}
			}
			swap(num[0], num[n]);
			for(j=N-1; j>0; j--)
				num[j+1] = num[j];
			if(N > 1)
				sort(&num[2], &num[N+1]);
			num[1] = '0';
			N++;
		}
		printf("Case #%d: ", cas);
		for(i=0; i<N; i++)
			printf("%c", num[i]);
		printf("\n");
		if(cas == T)
			break;
		cas++;
	}
	return 0;
}

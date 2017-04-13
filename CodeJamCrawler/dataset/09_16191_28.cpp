#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int T,N,cas=1,m[40][40],i,j,one[40],ans;
	
	freopen("testA.in", "r", stdin);
	freopen("testA.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(i=0; i<N; i++) {
			getchar();
			for(j=0; j<N; j++) {
				m[i][j] = getchar();
				m[i][j] -= '0';
			}
		}
		for(i=0; i<N; i++) {
			one[i] = -1;
			for(j=0; j<N; j++)
				if(m[i][j] == 1)
					one[i] = j;
		}
	//	for(i=0; i<N; i++)
		//	printf("%d %d\n", i, one[i]);
		ans = 0;
		for(i=0; i<N; i++) {			
			for(j=i; j<N; j++)
				if(one[j] <= i)
					break;
			for(; j>i; j--) {
				swap(one[j], one[j-1]);
				ans++;
			}
		}
		printf("Case #%d: %d\n", cas++, ans);
	}
	return 0;	
}

#include <stdio.h>
#include <stdlib.h>

int L,D,N,patt[15],seq[5000][15];

int main() {
	int i,j,k,ans;
	char tmp;
	
//	freopen("testA.in", "r", stdin);
//	freopen("testA.out", "w", stdout);
	scanf("%d%d%d", &L, &D, &N);
	for(i=0; i<D; i++) {
		getchar();
		for(j=0; j<L; j++) {
			tmp = getchar();
			seq[i][j] = tmp - 'a';
		}
	}
	for(i=0; i<N; i++) {
		getchar();
		for(j=0; j<L; j++) {
			patt[j] = 0;
			tmp = getchar();
			if(tmp == '(') {
				while(1) {
					tmp = getchar();
					if(tmp == ')')
						break;
					patt[j] |= (1 << (tmp - 'a'));
				}
			}
			else
				patt[j] |= (1 << (tmp - 'a'));
		}
		ans = 0;
		for(j=0; j<D; j++) {
			for(k=0; k<L; k++){
		//		printf("%d %d %d %d\n", j, k, 1<<seq[j][k], patt[k]);
				if(((1 << seq[j][k]) & patt[k]) == 0)					
					break;
				}
			if(k >= L)
				ans++;
		}
		printf("Case #%d: %d\n", i+1, ans);		 
	}
//	system("PAUSE");
	return 0;
}

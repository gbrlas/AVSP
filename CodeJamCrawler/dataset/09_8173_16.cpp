#include <stdio.h>

int main() {
	int T;
	int len[40];
	scanf("%d\n", &T);
	for (int t=0;t<T;t++) {
		int N, swaps=0;
		scanf("%d\n", &N);
		for (int i=0;i<N;i++) {
			len[i] = -1;
			for (int j=0;j<N;j++) {
				char k;
				scanf("%c", &k);
				if (k=='1') len[i] = j;
			}
			scanf("\n");
		}
		for (int i=0;i<N;i++) {
			if (len[i]>i) {
				int j=i+1;
				while (len[j]>i && j<N) j++;
				for (int k=j;k>i;k--) {
					int tmp = len[k];
					len[k] = len[k-1];
					len[k-1] = tmp;
					swaps++;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, swaps);
	}
}


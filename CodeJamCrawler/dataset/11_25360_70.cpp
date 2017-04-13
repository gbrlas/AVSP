#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int N, n, C, D;
char s[110], com[110][110], dom[110][110], ans[110];

int main () {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &C);
		for (int j = 0; j < C; ++j)
			scanf("%s", com[j]);
		scanf("%d", &D);
		for (int j = 0; j < D; ++j)
			scanf("%s", dom[j]);
		scanf("%d", &n);
		scanf("%s", s);
		memset(ans, 0, sizeof ans);
		int length = 0;
		for (int j = 0; j < n; ++j) {
			ans[length++] = s[j];
			bool hancur = true;
			while (length > 1 && hancur) {
				hancur = false;
				for (int k = 0; k < C && !hancur; ++k) {
					if ((ans[length - 1] == com[k][0] && ans[length - 2] == com[k][1]) || (ans[length - 1] == com[k][1] && ans[length - 2] == com[k][0])) {
						hancur = true;
						length--;
						ans[length - 1] = com[k][2];
						ans[length] = 0;
						break;
					}
				}
			}
			if (length > 1) {
				for (int k = 0; k < D; ++k) {
					int ok = 0;
					for (int l = 0; l < length && ok == 0; ++l)
						if (dom[k][0] == ans[l])
							ok++;
							
					for (int l = 0; l < length && ok == 1; ++l)
						if (dom[k][1] == ans[l])
							ok++;
					if (ok >= 2) {
						memset(ans, 0, sizeof ans);
						length = 0;
						break;
					}
				}
			}
		}
		printf("Case #%d: [", i + 1);
		for (int j = 0; j < length; ++j) {
			if (j > 0)
				printf(", ");
			printf("%c", ans[j]);
		}
		puts("]");
	}
}

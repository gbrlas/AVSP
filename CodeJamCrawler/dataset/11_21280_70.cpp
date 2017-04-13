#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define base 64
int T, n, ncmb, nops;
char cmb[30][30];
bool ops[30][30];

int main(){
	int i, j, k, len;
	char s[101];
	freopen("B_s.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d", &T);
	for (k = 1; k <= T; k++){
		memset(cmb, 0, sizeof(cmb));
		memset(ops, 0, sizeof(ops));
		scanf("%d", &ncmb);
		for (i = 1; i <= ncmb; i++){
			scanf("%s", s);
			cmb[s[0] - base][s[1] - base] 
			= cmb[s[1] - base][s[0] - base] = s[2];
		}
		scanf("%d", &nops);
		for (i = 1; i <= nops; i++){
			scanf("%s", s);
			ops[s[0] - base][s[1] - base] 
			= ops[s[1] - base][s[0] - base] = 1;
		}
		scanf("%d", &n);
		getchar();
		len = -1;
		for (i = 0; i < n; i++){
			scanf("%c", &s[++len]);
			if (len > 0){
				if (cmb[s[len] - base][s[len - 1] - base] > 0){
					s[len - 1] = cmb[s[len] - base][s[len - 1] - base];
					len--;
				}
			}
			for (j = len - 1; j >= 0; j--){
				if (ops[s[len] - base][s[j] - base]){
					len = -1;
					break;
				}
			}
		}
		printf("Case #%d: [", k);
		for (i = 0; i <= len; i++){
			printf("%c", s[i]);
			if (i < len) printf(", ");
		}			
		printf("]\n");
	}
 //   system("pause");
    return 0;
}

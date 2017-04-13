#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[1001];
int n;
int f[32770];
int s[32770];
int main(){
	int T;
	int i, j, k, sum, ans;
    freopen("C_s.in","r",stdin);
    freopen("C.out","w",stdout);
	scanf("%d", &T);
    for (k = 1; k <= T; k++){
		printf("Case #%d: ", k);
		scanf("%d", &n);
		for (i = 0, sum = 0; i < n; i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}		
		ans = -1;
		memset(f, 0, sizeof(f));
		memset(s, 0, sizeof(s));

		for (i = 1; i < (1 << n); i++){
			for (j = 0; (1 << j) <= i; j++)
				if (i & (1 << j)) break;
			f[i] = f[i - (1 << j)] ^ a[j];
			s[i] = s[i - (1 << j)] + a[j];
		}

		for (i = 1; i < (1 << n) - 1; i++){
			if (f[i] == f[(1 << n) - 1 - i]){
				ans = ans < s[i] ? s[i] : ans;
			}
		} 
		if (ans < 0) printf("NO\n");
		else printf("%d\n", ans);
	}
//	system("pause");
    return 0;
}

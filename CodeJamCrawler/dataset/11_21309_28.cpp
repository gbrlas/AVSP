#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[101];
int low, high, n;
int main(){
	int i, j, k, T, ans;
	freopen("C_s.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d", &T);
	for (k = 1; k <= T; k++){
		scanf("%d%d%d", &n, &low, &high);
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		ans = 0x7fffffff;
		for (i = low; i <= high; i++){
			for (j = 0; j < n; j++)
				if (a[j] % i != 0 && i % a[j] != 0) break;
			if (j >= n){
				ans = i;
				break;
			}
		}
		printf("Case #%d: ", k);
		if (ans > high) printf("NO\n");
		else printf("%d\n", ans);
	}
//    system("pause");
    return 0;
}

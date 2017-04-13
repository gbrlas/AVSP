#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int imax(int a, int b){
	return a > b ? a : b;
}
int main(){
	int n, T, lo, lb, to, tb, step;
	int i, k;
	char c;
//	freopen("A_l.in", "r", stdin);
//	freopen("A_s.out", "w", stdout);
	scanf("%d", &T);
	for (k = 1; k <= T; k++){
		scanf("%d", &n);
		lo = lb = 1;
		to = tb = step = 0;
		while(n--){
			getchar();
			c = getchar();
			scanf("%d", &i);
			if (c == 'O'){
				to += fabs(lo - i) + 1;
				lo = i;
				to = imax(to, step + 1);
				step = to;
			}else if (c == 'B'){
				tb += fabs(lb - i) + 1;
				lb = i;
				tb = imax(tb, step + 1);
				step = tb;
			}else printf("ERROR!\n");
		}
		printf("Case #%d: %d\n", k, step);
	}
//    system("pause");
    return 0;
}

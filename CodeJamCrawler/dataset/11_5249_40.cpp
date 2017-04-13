#include <stdio.h>

int data[10000];

int main()
{
	int T, ca;
	int n, low, high, ans, ret, i;
	
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	scanf("%d", &T);
	for (ca = 1; ca <= T; ca++) {
		scanf("%d %d %d", &n, &low, &high);
		for (i = 0; i < n; i++) 
			scanf("%d", &data[i]);
		
		ret = -1;
		for (ans = low; ans <= high; ans ++) {
			for (i = 0; i < n; i++) {
				if (ans % data[i] == 0 || data[i] % ans == 0)
					continue;
				else
					break;
				}
				if (i >= n) {
					ret = ans;
					break;
				}			
		}
		
		printf("Case #%d: ", ca);
		if (ret == -1)
			printf("NO\n");
		else
			printf("%d\n", ret);
			
		}
		return 0;
	}
				
				
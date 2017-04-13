#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
	freopen ("A-large.in", "r", stdin);
	freopen ("A-large.out", "w", stdout);
	int t, n, x[50];
	char g[50][50];
	scanf("%d", &t);
	for (int k = 1; k <= t; k++){
		scanf("%d", &n);
		memset (x, -1, sizeof (x));
		for (int i = 0; i < n; i++){
			scanf("%s", g[i]);
			for (int j = n - 1; j >= 0; j--)
				if (g[i][j] == '1'){
					x[i] = j;
					break;
				}
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = i; j < n; j++)
				if (x[j] <= i){
					int tmp = x[j];
					for (int s = j; s > i; s--)
						x[s] = x[s - 1];
					x[i] = tmp;
					ans += j - i;
					break;
				}
		}
		printf("Case #%d: %d\n", k, ans);
	}
}
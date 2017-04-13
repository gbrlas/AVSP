#include <stdio.h>
#include <string.h>

#define MODULUS 10007

int cnt[101][101];

int main()
{
	int n;
	scanf("%d", &n);
	for (int cc = 1; cc<=n; cc++)
	{
		int h,w,r;
		scanf("%d %d %d", &h, &w, &r);
		memset(cnt, 0, sizeof(cnt));
		cnt[1][1] = 1;
		
		for (int i=0; i<r; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			cnt[a][b] = -1;
		}
		for (int i=2; i<=h; i++) for (int j=2; j<=w; j++) if (cnt[i][j] == -1) cnt[i][j] = 0;
		else cnt[i][j] = (cnt[i-1][j-2] + cnt[i-2][j-1]) % MODULUS;
		printf("Case #%d: %d\n", cc, cnt[h][w]);
	}
	return 0;
}

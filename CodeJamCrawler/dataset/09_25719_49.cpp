#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 52;
char buf[MAXN];
int v[MAXN];

int main() {
	//freopen("a-small.in","r",stdin);
	//freopen("a-small.out","w",stdout);
	freopen("a-large.in","r",stdin);
	freopen("a-large.out","w",stdout);
	int T, i, j, j2, n, ca = 0;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (i = 0 ; i < n ; i++) {
			scanf("%s",buf);
			for (j = n - 1 ; j >= 0 ; j--)
				if (buf[j] == '1') break;
			v[i+1] = j + 1;
		}
		int ans = 0;
		for (i = 1 ; i <= n ; i++) {
			//for (j = 1 ; j <= n ; j++)
			//	printf("%d",v[j]);
			//printf("\n");
			if (v[i] <= i) continue;
			for (j = i ; j <= n ; j++)
				if (v[j] <= i) break;
			int tmp = v[j];
			for (j2 = j ; j2 > i ; j2--) {
				v[j2] = v[j2-1];
				++ans;
			}
			v[i] = tmp;

		}
		printf("Case #%d: %d\n",++ca,ans);
	}
	return 0;
}

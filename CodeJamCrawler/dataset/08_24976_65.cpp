#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int a[12], b[12];

int main() {
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	int T, n, i, s, ans, ca = 0;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (i = 0 ; i < n ; i++)
			scanf("%d",&a[i]);
		for (i = 0 ; i < n ; i++)
			scanf("%d",&b[i]);
		sort(b,b+n);
		ans = 1001001000;
		int cnt = 0;
		do {
			++cnt;
			for (i = s = 0 ; i < n ; i++)
				s += a[i] * b[i];
			ans <?= s;
		} while (next_permutation(b,b+n));
		printf("Case #%d: %d\n",++ca,ans);
		//printf("cnt:%d\n",cnt);
	}
	return 0;
}

#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char buf[1024], tmp[1024];
int a[20];

int main() {
	freopen("D-small-attempt1.in","r",stdin);
	freopen("D-small.1.out","w",stdout);
	int T, k, i, j, ca=0;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&k);
		scanf("%s",buf);
		for (i = 0 ; i < k ; i++)
			a[i] = i;
		int ans = 1000000100;
		int cnt;
		int tt = 0;
		do {
			//strcpy(tmp, buf);
			for (i = 0 ; buf[i] ; i += k) {
				for (j = 0 ; j < k ; j++) {
					tmp[i+j] = buf[i+a[j]];
				}
			}
			tmp[i] = 0;
			cnt = 0;
			for (i = 0 ; tmp[i] ; i++) {
				if (i == 0 || tmp[i] != tmp[i-1]) {
					++cnt;
				}
			}
			ans <?= cnt;
			//for (i = 0 ; i < k ; i++)
			//	printf(" %d",a[i]);
		} while (next_permutation(a, a+k));
		printf("Case #%d: %d\n",++ca,ans);
		//printf("tt:%d\n",tt);
	}
	return 0;
}

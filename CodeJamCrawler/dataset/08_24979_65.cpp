#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 1024;
int a[MAXN], b[MAXN];

int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T, n, i, j, ca = 0;
	LL s;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (i = 0 ; i < n ; i++)
			scanf("%d",a+i);
		for (j = 0 ; j < n ; j++)
			scanf("%d",b+j);
		sort(a,a+n);
		sort(b,b+n,greater<int>());
		//for (j = 0 ; j < n ; j++)
		//	printf(" %d",b[j]);
		s = 0;
		for (i = 0 ; i < n ; i++)
			s += (LL)a[i] * (LL)b[i];
		printf("Case #%d: %I64d\n",++ca,(LL)s);
	}
	return 0;
}

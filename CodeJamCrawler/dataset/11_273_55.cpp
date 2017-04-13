#include <iostream>
#include <cstdio>
using namespace std;

int n,ans,m;

int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int t=0,tt; scanf("%d",&tt);
	while (++t<=tt) {
		scanf("%d",&n);
		ans=0;
		for (int i=1; i<=n; i++) {
			scanf("%d",&m);
			if (m!=i) ++ans;
		}
		printf("Case #%d: %d.000000\n",t,ans);
	}
	return 0;
}


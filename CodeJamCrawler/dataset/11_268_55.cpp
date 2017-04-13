#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,sum,minc,can,tmp;
const int inf=0x7fffffff;

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int t=0,tt; scanf("%d",&tt);
	while (++t<=tt) {
		scanf("%d",&n);
		sum=0; can=0; minc=inf;
		for (int i=0; i<n; i++) {
			scanf("%d",&tmp);
			sum+=tmp; can=can^tmp; minc=min(minc,tmp);
		}
		if (can==0) printf("Case #%d: %d\n",t,sum-minc); else printf("Case #%d: NO\n",t);
	}
	return 0;
}


#include<iostream>
#include<algorithm>
using namespace std;
long long v1[1000],v2[1000];
int main()
{
	freopen("d:\\A-large.in","r",stdin);
	freopen("d:\\ou.out","w",stdout);
	int n,t;
	scanf("%d",&t);
	long long s;
	int k=1;
	while(t--){
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)scanf("%lld",&v1[i]);
		for(i=0;i<n;i++)scanf("%lld",&v2[i]);
		sort(v1,v1+n);
		sort(v2,v2+n);
		s=0;
		for(i=0;i<n;i++)s+=v1[i]*v2[n-1-i];
		printf("Case #%d: %lld\n",k++,s);
	}
	return 0;
}
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
#define MAX 810

int t,T;
int v1[MAX],v2[MAX];

int main()
{
	freopen("a-large.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	int i,j,n;
	for (t=1;t<=T;t++)
	{
		long long res=0;
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d",&v1[i]);
		for (i=0;i<n;i++)
			scanf("%d",&v2[i]);
		sort(v1,v1+n);
		sort(v2,v2+n);
		reverse(v2,v2+n);
		for (i=0;i<n;i++)
			res+=((long long)v1[i])*v2[i];
		printf("Case #%d: ",t);
		cout<<res<<endl;
	}

	return 0;
}
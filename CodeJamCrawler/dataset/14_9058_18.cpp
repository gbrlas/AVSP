#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<limits>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define repf(i,a,b) for(int i=(a); i<=(b); ++i)
#define repd(i,a,b) for(int i=(a); i>=(b); --i)
#define ll long long
#define PB(i) push_back(i)
#define MP make_pair
#define N 105
int test,n;
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&test);
	repf(ror,1,test)
	{
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		int sum=0;
		rep(i,a)
			rep(j,b)
			if((i&j)<k)
				sum++;
		printf("Case #%d: ",ror);
		printf("%d\n",sum);
	}
	return 0;
}

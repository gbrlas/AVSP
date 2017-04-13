#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int i,j,n,k,cas,c=0;
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d",&n,&k);
		int tmp=1<<n;
		k%=tmp;
		printf("Case #%d: %s\n",++c,k==tmp-1?"ON":"OFF");
	}
	return 0;
}

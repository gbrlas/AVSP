#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string>


using namespace std;
#define pi acos(-1.0)

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("1.out","w",stdout);
	int cas;
	int cass=1;

	scanf("%d",&cas);
	while(cas--)
	{
		long long l,p,c;
		cin >> l>>p>>c;
		long long sum=0,re=1,res=c;
		while(res*l<p)
		{
			sum++;
			re=re<<1;
			res=1;
			for(long long i=0;i<re;i++)
			res*=c;
		}
		printf("Case #%d: %lld\n",cass++,sum);
	}
}

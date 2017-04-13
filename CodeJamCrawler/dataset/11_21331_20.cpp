#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

int main()
{
	__int64 n;
	int t, pd, pg;
// 	freopen("A-large.in", "r", stdin);
// 	freopen("A-large.out", "w", stdout);
	cin>>t;
	for (int i = 1; i <= t; i++)
	{
		scanf("%I64d",&n);
		cin>>pd>>pg;
		printf("Case #%d: ", i);
		if ((pd < 100 && pg == 100) || (pd > 0 && pg == 0))
		{
			puts("Broken");
			continue;
		}
		if (pd == 100 || pd == 0)
		{
			puts("Possible");
			continue;
		}
		int m = 100;
		if (pd % 2 == 0)
		{
			pd /= 2;
			m /= 2;
		}
		if (pd % 2 == 0)
		{
			pd /= 2;
			m /= 2;
		}
		if (pd % 5 == 0)
		{
			pd /= 5;
			m /= 5;
		}
		if (pd % 5 == 0)
		{
			pd /= 5;
			m /= 5;
		}
		if (n >= m)
		{
			puts("Possible");
		}
		else
		{
			puts("Broken");
		}
	}
	return 0;
}
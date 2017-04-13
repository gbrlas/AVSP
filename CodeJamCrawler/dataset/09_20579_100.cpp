#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

set<char> got;
map<char, int> cimap;

int main()
{
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int tests = 1; tests <= T; ++tests)
	{
		char str[128];
		scanf("%s", str);
		got.clear();
		cimap.clear();
		int len = strlen(str);
		int cnt = 0;
		for(int i = 0; i < len; ++i)
		{
			char ch = str[i];
			if(cimap.find(ch) == cimap.end())
			{
				if(cimap.empty())
					cimap[ch] = 1;
				else
				{
					cimap[ch] = cnt;
					if(cnt == 0)
						cnt = 2;
					else ++cnt;
				}
			}
		}
		int base = cimap.size() == 1 ? 2 : cimap.size();
		long long res = 0;
		// if(len != 1)
		{
			for(int i = 0; i < len; ++i)
			{
				char ch = str[i];
				int dig = cimap[ch];
				res = res * base + dig;
			}
		}
		printf("Case #%d: %lld\n", tests, res);
	}

	return 0;
}
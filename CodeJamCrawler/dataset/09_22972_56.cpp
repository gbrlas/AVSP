#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

char s[10000];

int tt[256];

void donext()
{
	int l = strlen(s);
	bool a0 = true;
	for (int i = 1; i < l; ++i)
		if (s[i-1]<s[i])
			a0 = false;
	if (a0)
	{
		memcpy(s+1, s, l+1);
		++l;
		s[0] = '0';
	}
	memset(tt, 0, sizeof(tt));
	for (int i = l - 1; i > 0; --i)
	{
		++tt[s[i]];
		if (s[i]>s[i-1])
		{
			int j = s[i-1] + 1;
			while (!tt[j])
				++j;
			++tt[s[i-1]];
			--tt[j];
			s[i-1] = j;
			for (int k = 0; k < 256; ++k)
				while (tt[k])
				{
					s[i++] = k;
					--tt[k];
				}
			return ;
		}
	}
}

int main()
{
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		donext();
		printf("Case #%d: %s\n", i+1, s);
	}
	return 0;
}

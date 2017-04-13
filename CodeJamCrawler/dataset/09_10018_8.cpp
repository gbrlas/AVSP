#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef __int64 lld;

int T;
char str[1024];

lld solve()
{
	map <char, int> hash;

	int maxbase = 0;
	int len = strlen(str);

	hash[str[0]] = 1;
	for (int i = 1; i < len; i ++)
	{
		if (hash.find(str[i]) == hash.end())
		{
			if (hash.size() == 1)
				hash[str[i]] = 0;
			else
				hash[str[i]] = hash.size();
		}
	}

	maxbase = hash.size();
	if (maxbase == 1)
	{
		maxbase = 2;
	}

	lld nRet = 0;
	for (int i = 0; i < len; i ++)
	{
		lld d = hash[str[i]];
		nRet = nRet * maxbase + d;
	}
	return nRet;
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	//freopen("A-small-attempt1.out", "w", stdout);
	
	scanf("%d", &T);
	gets(str);
	for (int cas = 1; cas <= T; cas ++)
	{
		gets(str);
		printf("Case #%d: %I64d\n", cas, solve());
	}
	return 0;
}
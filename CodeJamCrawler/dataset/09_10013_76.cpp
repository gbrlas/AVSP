#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include "../SuperTimer.h"
using namespace std;

int T;
char szText[510];
char* szPat = "welcome to code jam";
int ans;
int cnt[510][30];

int dfs(char* pszText, char* pszPat)
{
	if (*pszPat == 0)
		return 1;
	if (*pszText == 0)
		return 0;
	if (cnt[pszText - szText][pszPat - szPat] != 0)
		return cnt[pszText - szText][pszPat - szPat];

	int ret = 0;
	for (; *pszText != 0; pszText ++)
		if (*pszText == *pszPat)
			ret += dfs(pszText+1, pszPat+1);
	ret %= 10000;
	return cnt[pszText - szText][pszPat - szPat] = ret;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	scanf("%d", &T);getchar();
	for (int cas = 1; cas <= T; cas ++)
	{
		gets(szText);
		ans = 0;
		memset(cnt, 0, sizeof(cnt));

		ans = dfs(szText, szPat);

		printf("Case #%d: %04d\n", cas, ans % 10000);
	}
}
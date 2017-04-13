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

int L, D, N;
string sDic[30];
string sPattern;

bool check(char* pszText, char* pszPat)
{
	if (*pszText == 0 && *pszPat == 0)
		return true;
	if (*pszText == 0 || *pszPat == 0)
		return false;

	char ch = *pszText;
	if (*pszPat == '(')
	{
		char* pszEnd = strchr(pszPat, ')');
		for (pszPat ++; pszPat < pszEnd; pszPat ++)
			if (*pszPat == ch)
				break;
		if (pszPat == pszEnd)
			return false;
		return check(pszText+1, pszEnd+1);
	}
	else
	{
		if (*pszPat == ch)
			return check(pszText+1, pszPat+1);
		return false;
	}
	return false;
}

int main()
{
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);

	cin >> L >> D >> N;
	for (int i = 0; i < D; i ++)
		cin >> sDic[i];

	for (int cas = 1; cas <= N; cas ++)
	{
		cin >> sPattern;
		int ans = 0;
		for (int i = 0; i < D; i ++)
			if (check((char*)sDic[i].c_str(), (char*)sPattern.c_str()))
				ans ++;
		printf("Case #%d: %d\n", cas, ans);
	}
}
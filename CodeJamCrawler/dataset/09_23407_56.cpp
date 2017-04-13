#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

string solve(string src)
{
	string res = "";
	src = '0' + src;
	int idx = 0;
	for (int i =0; i < src.length() - 1; ++i)
	{
		if (src[i] < src[i + 1]) idx = i;
	}
	int rdx = idx + 1;
	char minC = src[rdx];
	for (int j = rdx; j < src.length(); ++j)
	{
		if (src[j] > src[idx] && src[j] < minC) {
			minC = src[j];
			rdx = j;
		}
	}
	swap(src[idx], src[rdx]);
	++idx;
	sort(src.begin() + idx, src.end());
	if (src[0] == '0') res = src.substr(1);
	else res = src;
	return res;
}

int main()
{
	freopen("E:\\GCJ\\B-small.in", "r", stdin);
	freopen("E:\\GCJ\\B-small.out", "w", stdout);
	int nCase = 0;
	char buf[32];
	scanf("%d", &nCase);

	for (int cnt = 1; cnt <= nCase; ++cnt)
	{
		scanf("%s", buf);
		printf("Case #%d: %s\n", cnt, solve(string(buf)).c_str());
	}
	return 0;
}


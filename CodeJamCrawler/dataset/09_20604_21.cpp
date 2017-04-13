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

char str[50][100];
int vals[50];

void fix(int a, int b)
{
	int v[50];
	memcpy(v, vals, sizeof(vals));
	v[a] = vals[b];
	for(int i = a + 1; i <= b; ++i)
		v[i] = vals[i - 1];
	memcpy(vals, v, sizeof(vals));
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int tests = 1; tests <= T; ++tests)
	{
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i) scanf("%s", str[i]);
		memset(vals, 0, sizeof(vals));
		for(int i = 0; i < N; ++i)
		{
			int j = N - 1;
			for(; j >= 0; --j)
				if(str[i][j] != '0') break;
			vals[i] = j;
		}
		int res = 0;
		for(int i = 0; i < N; ++i)
		{
			if(vals[i] <= i) continue;
			for(int j = i + 1; j < N; ++j)
				if(vals[j] <= i)
				{
					fix(i, j);
					res += j - i;
					break;
				}
		}
		printf("Case #%d: %d\n", tests, res);
	}

	return 0;
}
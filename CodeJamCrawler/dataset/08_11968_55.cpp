#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAX_N = 100 + 10, MAX_M = 1000 + 100;

int n, m, s[MAX_M], last[MAX_M][MAX_N], f[MAX_M];
char buf[10000];

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		scanf("%d", &n);
		map<string, int> mapping;
		gets(buf);
		for (int i = 0; i < n; ++i)
		{
			gets(buf);
			string name = string(buf);
			mapping[name] = i;
			//printf("%s: %d\n", name.c_str(), i);
		}
		scanf("%d", &m);
		gets(buf);
		for (int i = 0; i < m; ++i)
		{
			gets(buf);
			s[i] = mapping[string(buf)];
		}
		for (int i = m - 1; i >= 0; --i)
			for (int j = 0; j < n; ++j)
				last[i][j] = s[i] == j ? -1 : (i == m - 1 || last[i + 1][j] == -1 ? i : last[i + 1][j]);

		fill(f, f + m, INT_MAX);
		for (int i = 0; i < n; ++i)
			if (last[0][i] != -1)
				f[last[0][i]] = 1;

		for (int i = 0; i < m; ++i)
			if (f[i] < INT_MAX)
				for (int j = 0; j < n; ++j)
					if (last[i + 1][j] != -1)
						for (int k = i + 1; k <= last[i + 1][j]; ++k)
							f[k] <?= f[i] + 1;
//						f[last[i + 1][j]] <?= f[i] + 1;

//		for (int i = 0; i < m; ++i)
//			for (int j = 0; j < n; ++j)
//				printf("last[%d][%d] = %d\n", i, j, last[i][j]);

		printf("Case #%d: %d\n", caseNo + 1, m == 0 ? 0 : (f[m - 1] - 1));
	}
	return 0;
}


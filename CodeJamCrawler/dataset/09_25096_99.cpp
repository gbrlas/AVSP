#include <stdio.h>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <memory.h>
#include <sstream>

using namespace std;




char w[] = "welcome to code jam";
char s[550];
int res[20];
int nres[20];

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);


	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		gets(s);
		memset(res, 0, sizeof(res));
		for (int j = 0; s[j]; ++j)
		{
			for (int k = 0; w[k]; ++k)
				nres[k] = res[k];
			for (int k = 0; w[k]; ++k)
			{
				if (s[j] == w[k])
				{
					if (k == 0)
						nres[k] = (nres[k] + 1) % 10000;
					else
						nres[k] = (nres[k] + res[k - 1]) % 10000;
				}
			}
			memcpy(res, nres, sizeof(res));
		}
		printf("Case #%d: %.4d\n", i + 1, res[18]);
	}


	return 0;
}
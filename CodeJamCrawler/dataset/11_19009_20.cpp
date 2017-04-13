#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <strstream>
using namespace std;

char mat[102][102];
int cnt[102][2];
double owp[102];
double ans[102];

int main ()
{
//	freopen ("A-small-attempt0.in", "r", stdin);
//	freopen ("A-small-attempt0.out", "w", stdout);
	int Test;
	scanf ("%d", &Test);
	for (int Cas = 1; Cas <= Test; Cas ++)
	{
		int n;
		scanf ("%d", &n);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i < n; i ++)
		{
			scanf ("%s", &mat[i]);
			for (int j = 0; j < n; j ++)
			{
				if (mat[i][j] == '1')
					cnt[i][1] ++;
				else if (mat[i][j] == '0')
					cnt[i][0] ++;
			}
		}
		printf ("Case #%d:\n", Cas);
		memset (ans, 0, sizeof (ans));
		for (int i = 0; i < n; i ++)
		{
			ans[i] += 0.25*cnt[i][1]/(cnt[i][0] + cnt[i][1]);
			int cnt1 = 0;
			double tmp = 0;
			for (int j = 0; j < n; j ++)
			{
				if (i != j && mat[j][i] != '.')
				{
					if (mat[j][i] == '1')
					{
						tmp += (cnt[j][1] - 1)*1.0/(cnt[j][0] + cnt[j][1] - 1);
					}
					else
					{
						tmp += cnt[j][1]*1.0/(cnt[j][0] + cnt[j][1] - 1);
					}
					cnt1 ++;
				}
			}
			owp[i] = tmp/cnt1;
			ans[i] += 0.5*tmp/cnt1;
		}
		for (int i = 0; i < n; i ++)
		{
			int cnt1 = 0;
			double tmp = 0;
			for (int j = 0; j < n; j ++)
			{
				if (i != j && mat[j][i] != '.')
				{
					cnt1 ++;
					tmp += owp[j];
				}
			}
			ans[i] += 0.25*tmp/cnt1;
			printf ("%.12f\n", ans[i]);
		}
	}
	return 0;
}


/*
2
4
.11.
0.00
01.1
.10.
*/
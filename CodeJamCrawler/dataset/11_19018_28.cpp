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

char mat[52][52];

int main ()
{
	//freopen ("A-small-attempt0 (1).in", "r", stdin);
	//freopen ("A-small-attempt0 (1).out", "w", stdout);
	int Test, n, m;
	scanf ("%d", &Test);
	for (int Cas = 1; Cas <= Test; Cas ++)
	{
		printf ("Case #%d:\n", Cas);
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i ++)
			scanf ("%s", mat[i]);
		bool flag = true;
		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j < m; j ++)
			{
				if (mat[i][j] == '#')
				{
					mat[i][j] = '\/';
					if (mat[i][j + 1] == '#')
						mat[i][j + 1] = '\\';
					else
					{
						flag = false;
						break;
					}
					if (mat[i + 1][j] == '#')
						mat[i + 1][j] = '\\';
					else
					{
						flag = false;
						break;
					}
					if (mat[i + 1][j + 1] == '#')
						mat[i + 1][j + 1] = '\/';
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
					break;
			}
			if (flag == false)
				break;
		}
		if (flag == false)
			printf ("Impossible\n");
		else
			for (int i = 0; i < n; i ++)
				printf ("%s\n", mat[i]);
	}
	return 0;
}
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
int a[102];

int main ()
{
	int Test, n, l, h;
	scanf ("%d", &Test);
	for (int Cas = 1; Cas <= Test; Cas ++)
	{
		printf ("Case #%d: ", Cas);
		scanf ("%d%d%d", &n, &l, &h);
		for (int i = 0; i < n; i ++)
			scanf ("%d", &a[i]);
		bool flag = false;
		int ans;
		for (int i = l; i <= h; i ++)
		{
			bool flag1 = true;
			for (int j = 0; j < n; j ++)
			{
				if (i % a[j] != 0 && a[j] % i != 0)
				{
					flag1 = false;
					break;
				}
			}
			if (flag1 == true)
			{
				flag = true;
				ans = i;
				break;
			}
		}
		if (flag == false)
		{
			printf ("NO\n");
		}
		else
			printf ("%d\n", ans);
	}
	return 0;
}
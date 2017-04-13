#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
const int MAXN = 100005;



map <char, char> cl;
map <string, char> un;

int main ()
{
	freopen ("B-small-attempt2 (1).in", "r", stdin);
	freopen ("output.out", "w", stdout);
	int Test, N, M, n;
	string tmp, str, ans;
	scanf ("%d", &Test);
	for (int Cas = 1; Cas <= Test; Cas ++)
	{
		cl.clear ();
		un.clear ();
		scanf ("%d", &N);
		ans = "";
		for (int i = 0; i < N; i ++)
		{
			cin >> tmp;
			str = "", str += tmp[0], str += tmp[1];
			un[str] = tmp[2];
			str = "", str += tmp[1], str += tmp[0];
			un[str] = tmp[2];
		}
		scanf ("%d", &M);
		for (int i = 0; i < M; i ++)
		{
			cin >> tmp;
			cl[tmp[0]] = tmp[1];
			cl[tmp[1]] = tmp[0];
		}
		scanf ("%d", &n);
		cin >> str;
		int size = str.size ();
		ans += str[0];
		for (int i = 1; i < size; i ++)
		{
			if (ans.size () == 0)
			{
				ans += str[i];
				continue;
			}
			tmp = "", tmp += ans[ans.size () - 1], tmp += str[i];
			if (un[tmp])
			{
				ans.erase (ans.end () - 1);
				ans += un[tmp];
			}
			else
			{
				int size1 = ans.size ();
				bool flag = true;
				for (int j = 0; j < size1; j ++)
				{
					if (cl[str[i]] == ans[j])
					{
						ans = "";
						flag = false;
						break;
					}
				}
				if (flag)
					ans += str[i];
			}
		}
		printf ("Case #%d: ", Cas);
		size = ans.size ();
		if (size == 0)
			printf ("[]\n");
		else
		{
			printf ("[%c", ans[0]);
			for (int i = 1; i < size; i ++)
				printf (", %c", ans[i]);
			printf ("]\n");
		}
	}
	return 0;
}
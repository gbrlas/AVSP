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



struct node{
	int idx, pos;
} orange[102], blue[102];

int main ()
{
	//freopen ("A-large.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	int Test, N, pos, Cas = 1;
	char op[10];
	scanf ("%d", &Test);
	while (Test --){
		scanf ("%d", &N);
		int os = 0, bs = 0;
		memset (orange, -1, sizeof (orange));
		memset (blue, -1, sizeof (blue));
		for (int i = 0; i < N; i ++)
		{
			scanf ("%s%d", op, &pos);
			if (op[0] == 'O')
			{
				orange[os].pos = pos;
				orange[os ++].idx = i;
			}
			else
			{
				blue[bs].pos = pos;
				blue[bs ++].idx = i;
			}
		}
		int time = 0, oi = 0, bi = 0, k = 0, po = 1, pb = 1, tmp;
		while (k < N)
		{
			if (orange[oi].idx == k)
			{
 				tmp = abs(orange[oi].pos - po) + 1;
				time += tmp;
				po = orange[oi].pos;
				if (blue[bi].pos > pb)
					pb = min (blue[bi].pos, pb + tmp);
				else
					pb = max (blue[bi].pos, pb - tmp);
				++ oi;
			}
			else
			{
				tmp = abs(blue[bi].pos - pb) + 1;
				time += tmp;
				pb = blue[bi].pos;
				if (orange[oi].pos > po)
					po = min (orange[oi].pos, po + tmp);
				else
					po = max (orange[oi].pos, po - tmp);
				++ bi;
			}
			if (oi == os)
			{
				for (int i = bi; i < bs; i ++)
				{
					time += abs(blue[i].pos - pb) + 1;
					pb = blue[i].pos;
				}
				break;
			}
			else if (bi == bs)
			{
				for (int i = oi; i < os; i ++)
				{
					time += abs(orange[i].pos - po) + 1;
					po = orange[i].pos;
				}
				break;
			}
			k ++;
		}
		printf ("Case #%d: %d\n", Cas ++, time);
	}
	return 0;
}

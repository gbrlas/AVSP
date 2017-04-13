#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int SMAX = 110;
const int QMAX = 1100;
int n, s, q;
string com[SMAX];
string query[QMAX];

string find_min(int ss)
{
	map <string, int> hash;
	map <string, int> vis;
	int i, j, flag;
	string ret = "";

	for (i=ss; i<q; i++)
	{
		hash[ query[i] ] ++;
		if ( hash[ query[i] ] == 1)
			vis[ query[i] ] = i;
	}

	flag = -1;
	for (i=0; i<s; i++)
	{
		if (hash[ com[i] ] == 0)
			return com[i];
		else if ( vis[ com[i] ] > flag)
		{
			flag = vis[ com[i] ];
			ret = com[i];
		}
	}
	return ret;
}

int solve()
{
	int i, j, ret = 0;

	if (q == 0)
		return 0;

	for (i=0; i<q; i=j)
	{
		string use = find_min(i);
		ret ++;
		for (j=i; j<q; j++)
		{
			if (query[j] == use)
				break;
		}
	}
	return ret-1;
}

char line[110];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int i, j, cas = 1;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &s);
		getchar();
		for (j=0; j<s; j++)
		{
			gets(line);
			com[j] = line;
		}
		scanf("%d", &q);
		getchar();
		for (j=0; j<q; j++)
		{
			gets(line);
			query[j] = line;
		}
		printf("Case #%d: %d\n", i, solve());
	}
}
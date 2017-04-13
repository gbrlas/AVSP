#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

const int maxl = 10000;
const int maxm = 100 + 10;

string lef[maxl * 4];
double a[maxl * 4];
string f[maxm];
string s;
int n, m;
double p;
stringstream IN;

void build(int k)
{
//	printf("%d\n", k);
	char c;
	IN >> c >> a[k] >> c;
	
	lef[k] = "";
	if (c == ')')
	{
		//printf("%d %s %lf\n", k, lef[k].c_str(), a[k]);
		return;
	}

	IN.putback(c);
	IN >> lef[k];

	//printf("%d %s %lf\n", k, lef[k].c_str(), a[k]);

	build(k * 2 + 1); build(k * 2 + 2);
	IN >> c;
}

void DFS(int k)
{
	p *= a[k];
//	printf("%d %lf\n", k, p);
	if (lef[k] == "") return;
	for (int i = 0; i < m; ++i)
		if (f[i] == lef[k])
		{
			DFS(k * 2 + 1);
			return;
		}
	DFS(k * 2 + 2);
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		s = "";
		int L;
		scanf("%d\n", &L);
		for (int i = 0; i < L; ++i)
		{
			char S[100];
			gets(S);
			s += S;
		}
		
		IN.str(s);
		build(0);

		printf("Case #%d:\n", tst);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			char S[100];
			scanf("%s", S);
			scanf("%d", &m);
			for (int j = 0; j < m; ++j)
			{
				scanf("%s", S);
				f[j] = S;
			}
			p = 1;
			DFS(0);
			printf("%.7lf\n", p);
		}
	}

	return 0;
}

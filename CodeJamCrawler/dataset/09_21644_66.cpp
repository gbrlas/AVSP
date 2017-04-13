#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

void initialize()
{
	freopen("a0.in", "r", stdin);
	freopen("a.out", "w", stdout);
}

const int L = 20;
const int S = 1000;
char str[S];

const int MAX = (int)10e5;
const int CHAR = 26;
int s = 1;
int reb[MAX][CHAR];
bool check[S][CHAR];

const int ROOT = 0;

int l, d, n;

int run(int num, int v)
{
	if (num == l) return 1;
	int s = 0;
	for (int i = 0; i < CHAR; ++i)
	{
		if (!check[num][i]) continue;
		if (reb[v][i] > 0)
			s += run(num + 1, reb[v][i]);
	}
	return s;
}

int main()
{
	initialize();

	scanf("%d%d%d", &l, &d, &n);
	for (int i = 0; i < d; ++i)
	{
		scanf("%s", str);
		int len = strlen(str);
		int v = ROOT;
		for (int i = 0; i < len; ++i)
		{
			if (reb[v][str[i] - 'a'] == 0)
				reb[v][str[i] - 'a'] = s++;
			v = reb[v][str[i] - 'a'];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int i = 0; i < L; ++i)
			for (int j = 0; j < CHAR; ++j)
				check[i][j] = false;

		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0, k = 0; i < len; ++i, ++k)
		{
			if (str[i] == '(')
			{
				while (str[++i] != ')')
					check[k][str[i] - 'a'] = true;
			}
			else
				check[k][str[i] - 'a'] = true;
		}
		int s = run(0, ROOT);
		printf("Case #%d: %d\n", i + 1, s);
	}

	return 0;
}
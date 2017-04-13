#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

int m;
int v[20000];
int oper[20000];
int cnt;
bool changable[20000];
bool leaf[20000];

int _f[20000][2];

int MX = 10000000;

int f(int node, int value)
{
	if (_f[node][value] == -1)
	{
		if (leaf[node]) {
			if (v[node] == value)
				return _f[node][value] = 0;
			else
				return _f[node][value] = MX;
		}
		_f[node][value] = MX;
		int or_min = MX;
		if (value == 0)
			or_min = f(node * 2 + 1, 0) + f(node * 2 + 2, 0);
		else {
			or_min = min(or_min, f(node * 2 + 1, 1) + f(node * 2 + 2, 1));
			or_min = min(or_min, f(node * 2 + 1, 0) + f(node * 2 + 2, 1));
			or_min = min(or_min, f(node * 2 + 1, 1) + f(node * 2 + 2, 0));
		}

		int and_min = MX;
		if (value == 1)
			and_min = f(node * 2 + 1, 1) + f(node * 2 + 2, 1);
		else {
			and_min = min(and_min, f(node * 2 + 1, 0) + f(node * 2 + 2, 0));
			and_min = min(and_min, f(node * 2 + 1, 0) + f(node * 2 + 2, 1));
			and_min = min(and_min, f(node * 2 + 1, 1) + f(node * 2 + 2, 0));
		}

		if (oper[node] == 1)
		{
			_f[node][value] = and_min;
		}
		else 
		{
			_f[node][value] = or_min;
		}
		if (changable[node])
		{
			_f[node][value] = min(_f[node][value], or_min + 1);
			_f[node][value] = min(_f[node][value], and_min + 1);
		}
	}
	return _f[node][value];
}


int main()
{
  freopen("small.in", "rt", stdin);
  //freopen("large.in", "rt", stdin);
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
	cin >> m;
	int r;
	cin >> r;
	for (int i = 0; i < (m - 1) / 2; i++)
	{
		cin >> oper[i];
		cin >> changable[i];
		leaf[i] = false;
	}
	for (int i = (m - 1) / 2; i < m; i++)
	{
		leaf[i] = true;
		cin >> v[i];
	}
	memset(_f, -1, sizeof(_f));

	int res = f(0, r);
	if (res < MX)
	    cout << "Case #" << t + 1 << ": " << res << endl;
	else
		cout << "Case #" << t + 1 << ": " << "IMPOSSIBLE" << endl;

  }

  return 0;
}
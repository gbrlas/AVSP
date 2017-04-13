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


int _f[100][2000];
vector<string> v;
int n, m;

int bc(int a)
{
	int res = 0;
	while (a)
	{
	 res += (a & 1);
	 a >>= 1;
	}
	return res;
}


int f(int row, int mask)
{
	if (_f[row][mask] < 0)
	{
		if (row == n) return _f[row][mask] = 0;
		_f[row][mask] = 0;
		for (int ms = 0; ms < (1 << m); ms++) 
		{
			bool ok = true;
			for (int i = 0; i < m; i++) if (v[row][i] == 'x' && ((1 << i) & ms)) ok = false;
			for (int i = 0; i + 1 < m; i++) if (((1 << i) & ms) && ((1 << (i + 1)) & ms)) ok = false;
			for (int i = 0; i + 1 < m; i++) if (((1 << i) & ms) && ((1 << (i + 1)) & mask)) ok = false;
			for (int i = 0; i + 1 < m; i++) if (((1 << i) & mask) && ((1 << (i + 1)) & ms)) ok = false;
			if (ok)
				_f[row][mask] = max(_f[row][mask], bc(ms) + f(row + 1, ms));
		}
	}
	return _f[row][mask];
}



int main()
{
  freopen("small.in", "rt", stdin);
  //freopen("large.in", "rt", stdin);
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
	cin >> n >> m;
	vector<string> vs(n);
	for (int i = 0; i < n; i++)
		cin >> vs[i];
	v = vs;
	memset(_f, -1, sizeof(_f));

    cout << "Case #" << t + 1 << ": " << f(0, 0) << endl;
  }

  return 0;
}
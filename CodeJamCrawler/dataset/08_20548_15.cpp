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


int _f[200][200];
int w, h;
map<pair<int,int> , int > holes;

int f(int i, int j)
{
	if (_f[i][j] < 0)
	{
		if (i > h) return _f[i][j] = 0;
		if (j > w) return _f[i][j] = 0;
		if (holes.find(make_pair(i, j)) != holes.end()) return _f[i][j] = 0;
		if (i == h && j == w) return _f[i][j] = 1;
		_f[i][j] = (f(i + 1, j + 2) + f(i + 2, j + 1)) % 10007;
	}
	return _f[i][j];
}


int main()
{
  freopen("small.in", "rt", stdin);
  //freopen("large.in", "rt", stdin);
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++)
  {
	int r;
	map<pair<int, int>, int> mm;
	cin >> h >> w >> r;
	for (int i = 0; i < r; i++)
	{
		int a, b;
		cin >> a >> b;
		mm[make_pair(a, b)] = 1;
		holes = mm;
	}
	memset(_f, -1, sizeof(_f));

    cout << "Case #" << t + 1 << ": " << f(1, 1) << endl;
  }

  return 0;
}
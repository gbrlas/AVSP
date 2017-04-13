#include <iostream>
#include <climits>

using	namespace	std;

static const int maxh = 100;
static const int maxw = 100;

static const int dd[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int	h, w;
int	m[maxh][maxw];
char	ans[maxh][maxw];

pair<int, int> choose(int i, int j)
{
	int minimal = INT_MAX;
	for (int d = 0; d < 4; ++d)
	{
		int ii = i + dd[d][0];
		int jj = j + dd[d][1];

		if (ii < 0 || ii >= h)	continue;
		if (jj < 0 || jj >= w)	continue;

		minimal = min(minimal, m[ii][jj]);
	}
	if (minimal >= m[i][j])	return make_pair(-1, -1);

	for (int d = 0; d < 4; ++d)
	{
		int ii = i + dd[d][0];
		int jj = j + dd[d][1];

		if (ii < 0 || ii >= h)	continue;
		if (jj < 0 || jj >= w)	continue;

		if (m[ii][jj] == minimal)
			return make_pair(ii, jj);
	}
}

void fill(int i, int j, char c)
{
	if (ans[i][j])	return;
	ans[i][j] = c;

	pair<int, int> p = choose(i, j);
	if (p != make_pair(-1, -1))	fill(p.first, p.second, c);

	for (int d = 0; d < 4; ++d)
	{
		int ii = i + dd[d][0];
		int jj = j + dd[d][1];

		if (ii < 0 || ii >= h)	continue;
		if (jj < 0 || jj >= w)	continue;
		
		pair<int, int> p = choose(ii, jj);
		if (p == make_pair(i, j))	fill(ii, jj, c);
	}
}

int	main()
{
	int	t;
	cin >> t;
	for (int tt = 0; tt < t; ++tt)
	{
		cout << "Case #" << tt + 1 << ":" << endl;

		cin >> h >> w;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
			{
				cin >> m[i][j];
				ans[i][j] = 0;
			}

		char c = 'a';
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
			{
				if (ans[i][j] == 0)
					fill(i, j, c++);
			}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (j != 0)	cout << ' ';
				cout << ans[i][j];
			}
			cout << endl;
		}
	}

	return	0;
}


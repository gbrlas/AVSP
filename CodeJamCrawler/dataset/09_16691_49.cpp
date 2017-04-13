#include <iostream>

using	namespace	std;

int	n, k;
int	m[200][200];
bool	g[200][200];
bool	useif[200];
int	_link[200];

bool	can(int t)
{
	for (int i = 0; i < n; ++i)
	{
		if (!useif[i] && g[t][i])
		{
			useif[i] = true;
			if (_link[i] == -1 || can(_link[i]))
			{
				_link[i] = t;
				return true;
			}
		}
	}
	return false;
}

void	solve()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			cin >> m[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			g[i][j] = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int u = 0; u < k; ++u)
				if (!(m[i][u] < m[j][u]))
				{
					g[i][j] = false;
					break;
				}

	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cerr << g[i][j] << ' ';
		cerr << endl;
	}
	*/

	int	num = 0;
	for (int i = 0; i < n; ++i)	_link[i] = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			useif[j] = false;
		if (can(i))	++num;
	}
	cout << n - num << endl;
}

int	main()
{
	int	t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return	0;
}


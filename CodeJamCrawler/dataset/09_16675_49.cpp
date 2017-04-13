#include <iostream>
#include <climits>

using	namespace	std;

int	ans;
int	n;
int	m[50][50];
int	p[50], oldp[50];
bool	flag[50];

int	read01()
{
	char	c;
	while (true)
	{
		cin >> c;
		if (c == '0')
			return 0;
		else if (c == '1')
			return 1;
	}
}

bool	check()
{
	for (int i = 0; i < n; ++i)
	{
		int	t = p[i];
		for (int j = i + 1; j < n; ++j)
			if (m[t][j] == 1)
				return false;
	}
	return true;
}

void	dfs(int dep)
{
	if (dep >= n)
	{
		for (int i = 0; i < n; ++i)	oldp[i] = p[i];
		if (check())
		{
			int	t = 0;
			for (int i = n - 1; i >= 0; --i)
			{
				int	pos;
				for (int j = 0; j < n; ++j)
					if (p[j] == i)
					{
						pos = j;
						break;
					}
				for (int j = pos + 1; j <= i; ++j)
				{
					swap(p[j - 1], p[j]);
					++t;
				}
			}
			if (t < ans)	ans = t;
		}
		for (int i = 0; i < n; ++i)	p[i] = oldp[i];
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (flag[i])	continue;
		flag[i] = true;
		p[dep] = i;
		dfs(dep + 1);
		flag[i] = false;
	}
}

void	solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			m[i][j] = read01();

	ans = INT_MAX;
	dfs(0);
	cout << ans << endl;
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


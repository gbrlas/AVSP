#include <iostream>

using	namespace	std;

int	ans;
int	n;
int	m[50][50];
int	p[50];

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

void	change(int a, int b)
{
	for (int i = 0; i < n; ++i)
		swap(m[a][i], m[b][i]);
}

bool	check(int j, int x)
{
	for (int i = x + 1; i < n; ++i)
		if (m[j][i] == 1)	return false;
	return true;
}

void	solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			m[i][j] = read01();
	for (int i = 0; i < n; ++i)	p[i] = i;

	int	ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (check(j, i))
			{
				for (int k = j - 1; k >= i; --k)
				{
					++ans;
					change(k + 1, k);
				}
				break;
			}
		}
	}
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

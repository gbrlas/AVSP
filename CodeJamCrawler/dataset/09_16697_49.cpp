#include <iostream>
#include <cmath>

using	namespace	std;

int	x[50], y[50], r[50];

double	sqr(double x)
{
	return	x * x;
}

double	dist(int a, int b)
{
	return	sqrt(sqr(x[a] - x[b]) + sqr(y[a] - y[b]));
}

void	solve()
{
	int	n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i] >> r[i];

	if (n == 1)
		cout << r[0] << endl;
	else if (n == 2)
		cout << max(r[0], r[1]) << endl;
	else if (n == 3)
	{
		double	ans = 1e9;
		ans = min(ans, max(double(r[0]), (r[1] + r[2] + dist(1, 2)) * 0.5));
		ans = min(ans, max(double(r[1]), (r[0] + r[2] + dist(0, 2)) * 0.5));
		ans = min(ans, max(double(r[2]), (r[0] + r[1] + dist(0, 1)) * 0.5));
		cout << ans << endl;
	}
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


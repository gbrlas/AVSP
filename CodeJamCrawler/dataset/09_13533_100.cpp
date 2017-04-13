#include <iostream>

using namespace std;

int a[103][103];
int b[102];

const int INF = 1000000000;

int main()
{
	freopen("c.in", "rt", stdin);
	freopen("c.out", "wt", stdout);
	int t;
	cin >> t;
	for (int T = 1; T <= t; ++T)
	{
		int n, m;
		cin >> n >> m;
		b[0] = 0;
		b[m+1] = n+1;
		for (int i = 0; i < m; ++i)
			cin >> b[i+1];
		for (int i = 0; i < m+2; ++i)
			a[i][i] = a[i][i+1] = 0;
		for (int d = 2; d <= m+1; ++d)
			for (int i = 0; i + d <= m+1; ++i)
			{
				a[i][i+d] = INF;
				for (int j = i+1; j < i+d; ++j)
					a[i][i+d] = min(a[i][i+d], b[i+d] - b[i] - 2 + a[i][j] + a[j][i+d]);
			}
		cout << "Case #" << T << ": " << a[0][m+1] << '\n';
	}
	return 0;
}

# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>
# include <utility>
# include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int u = 0; u < t; ++u)
	{
		int n, m;
		cin >> n >> m;

		vector< string> a(n);
		
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == '#')
				{
					if (i < n - 1 && j < m - 1 && a[i][j + 1] == '#' && a[i + 1][j] == '#' && a[i + 1][j + 1] == '#') 
					{
						a[i][j] = '/';
						a[i][j + 1] = '\\'; 
						a[i + 1][j] = '\\';
						a[i + 1][j + 1] = '/';
					}
					else
					{
						cout << "Case #" << u + 1 << ": " << endl << "Impossible" << endl;
						goto l;				
					}
				}

		cout << "Case #" << u + 1 << ": " << endl;
		for (int i = 0; i < n; ++i)
			cout << a[i] << endl;

		l: n = 0;
	}
	
	return 0;
}
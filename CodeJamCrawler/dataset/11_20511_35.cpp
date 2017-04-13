# include <stdio.h>
# include <iostream>
# include <vector>
# include <string>
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
		int n;
		cin >> n;
		vector< string > a(n, "");
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		vector< int > win(n);
		vector< int > games(n);
		for (int i = 0; i < n; ++i)
		{
			win[i] = count(a[i].begin(), a[i].end(), '1');
			games[i] = win[i] + count(a[i].begin(), a[i].end(), '0');
		}

		vector< double > owp(n, 0.0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				if (a[i][j] != '.')
					owp[i] += (win[j] - ( (a[j][i] == '1') ? 1 : 0 )) / ((double)games[j] - 1.0);
			owp[i] /= games[i];
		}

		vector< double > oowp(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				if (a[i][j] != '.')
					oowp[i] += owp[j];
			oowp[i] /= games[i];
		}

		cout << "Case #" << u + 1 << ':' << endl;
		for (int i = 0; i < n; ++i)
		{
			double rpi = 0.25 * (win[i] / (double) games[i]) + 0.5 * owp[i] + 0.25 * oowp[i];
			cout << rpi << endl;
		}

	}
	
	return 0;
}
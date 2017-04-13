#include <iostream>
#include <sstream>
#include <list>

using	namespace	std;

static const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

string	m[20];
string	ans[20][20][500];
list<pair<pair<int, int>, int> > queue;

void	solve()
{
	int	w, q;
	{
		string	s;
		getline(cin, s);
		stringstream strin(s);
		strin >> w >> q;
	}

	for (int i = 0; i < w; ++i)
		for (int j = 0; j < w; ++j)
			for (int k = 0; k < 500; ++k)
				ans[i][j][k].clear();
	for (int i = 0; i < w; ++i)
		getline(cin, m[i]);

	queue.clear();
	for (int i = 0; i < w; ++i)
		for (int j = 0; j < w; ++j)
			if (isdigit(m[i][j]))
			{
				ans[i][j][m[i][j] - '0' + 250] = m[i][j];
				queue.push_back(make_pair(make_pair(i, j), m[i][j] - '0' + 250));
			}

	while (!queue.empty())
	{
		pair<pair<int, int>, int> x = queue.front();
		queue.pop_front();
		int i = x.first.first;
		int j = x.first.second;
		int k = x.second - 250;

		for (int dd = 0; dd < 4; ++dd)
		{
			int ii = i + dir[dd][0];
			int jj = j + dir[dd][1];

			if (ii < 0 || ii >= w)	continue;
			if (jj < 0 || jj >= w)	continue;

			for (int dd2 = 0; dd2 < 4; ++dd2)
			{
				int ii2 = ii + dir[dd2][0];
				int jj2 = jj + dir[dd2][1];

				if (ii2 < 0 || ii2 >= w)	continue;
				if (jj2 < 0 || jj2 >= w)	continue;

				int kk = k;
				if (m[ii][jj] == '+')
					kk += m[ii2][jj2] - '0';
				else
					kk -= m[ii2][jj2] - '0';

				if (kk + 250 < 0 || kk + 250 >= 500)	continue;

				string newans = ans[i][j][k + 250] + m[ii][jj] + m[ii2][jj2];
				if (ans[ii2][jj2][kk + 250].empty() ||
					ans[ii2][jj2][kk + 250].size() > newans.size() ||
					(ans[ii2][jj2][kk + 250].size() == newans.size() && ans[ii2][jj2][kk + 250] > newans))
				{
					ans[ii2][jj2][kk + 250] = newans;
					queue.push_back(make_pair(make_pair(ii2, jj2), kk + 250));
				}
			}
		}

	}
			

	string	s;
	getline(cin, s);
	stringstream strin(s);

	for (int i = 0; i < q; ++i)
	{
		int	t;
		strin >> t;

		string x;
		for (int ii = 0; ii < w; ++ii)
			for (int jj = 0; jj < w; ++jj)
			{
				if (ans[ii][jj][t + 250].empty())	continue;
				if (x.empty() || x.size() > ans[ii][jj][t + 250].size() ||
						(x.size() == ans[ii][jj][t + 250].size() && x > ans[ii][jj][t + 250]))
					x = ans[ii][jj][t + 250];
			}

		cout << x << endl;
	}
}

int	main()
{
	int	n;
	string	s;
	getline(cin, s);
	stringstream strin(s);
	strin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Case #" << i + 1 << ":" << endl;
		solve();
	}
	return	0;
}


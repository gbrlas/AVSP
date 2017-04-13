#include <iostream>
#include <string>
#include <sstream>

using	namespace	std;

static const char goal[] = "welcome to code jam";
static const int l = sizeof(goal) - 1;
static const int maxlen = 600;

int f[maxlen][l];

void solve(string s)
{

	if (s[0] == goal[0])
		f[0][0] = 1;
	else
		f[0][0] = 0;
	for (int j = 1; j < l; ++j)	f[0][j] = 0;

	for (int i = 1; i < s.size(); ++i)
		for (int j = 0; j < l; ++j)
		{
			if (s[i] == goal[j])
			{
				if (j == 0)
					f[i][j] = (f[i - 1][j] + 1) % 10000;
				else
					f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % 10000;
			}
			else
				f[i][j] = f[i - 1][j];
		}

	/*
	cerr << "#######################" << endl;
	cerr << s << endl;
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j < l; ++j)
			cerr << f[i][j] << ' ';
		cerr << endl;
	}
	cerr << "#######################" << endl;
	*/

	int ans = f[s.size() - 1][l - 1];
	if (ans / 1000 == 0)	cout << '0';
	if (ans / 100 == 0)	cout << '0';
	if (ans / 10 == 0)	cout << '0';

	cout << f[s.size() - 1][l - 1] << endl;
}

int	main()
{
	string s;
	getline(cin, s);
	stringstream strin(s);
	int	n;
	strin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Case #" << i + 1 << ": ";

		string s;
		getline(cin, s);
		solve(s);
	}
	return	0;
}


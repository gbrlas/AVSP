#include <iostream>
#include <sstream>

using	namespace	std;

int	d[10];

bool	ismax(const string &s)
{
	int	d[10];
	for (int i = 0; i < 10; ++i)	d[i] = 0;

	for (int i = 0; i < static_cast<int>(s.size()); ++i)
		++d[s[i] - '0'];

	for (int i = 1; i < static_cast<int>(s.size()); ++i)
		if (s[i - 1] < s[i])
			return	false;

	return true;
}

void	solve()
{
	string	s;
	getline(cin, s);

	for (int i = 0; i < 10; ++i)	d[i] = 0;
	for (int i = 0; i < static_cast<int>(s.size()); ++i)	++d[s[i] - '0'];

	if (ismax(s))
	{
		for (int i = 1; i < 10; ++i)
			if (d[i])
			{
				cout << i;
				--d[i];
				break;
			}
		cout << '0';
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < d[i]; ++j)
				cout << i;
		cout << endl;
		return;
	}

	for (int k = 0; k < static_cast<int>(s.size()); ++k)
		if (ismax(s.substr(k + 1, s.size())))
		{
			for (int i = (s[k] - '0') + 1; i < 10; ++i)
				if (d[i])
				{
					cout << i;
					--d[i];
					break;
				}
			for (int i = 0; i < 10; ++i)
				for (int j = 0; j < d[i]; ++j)
					cout << i;
			cout << endl;
			return;
		}
		else
		{
			cout << s[k];
			--d[s[k] - '0'];
		}
}

int	main()
{
	string	s;
	int	n;
	getline(cin, s);
	stringstream strin(s);
	strin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return	0;
}


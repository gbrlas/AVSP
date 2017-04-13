#include <iostream>
#include <string>

using	namespace	std;

static const int maxnode = 100000;

int trie[maxnode][26];
int nodes;
int ans;

void insert(int i, string s)
{
	if (s.size() == 0)	return;
	if (trie[i][s[0] - 'a'] == 0)
		trie[i][s[0] - 'a'] = ++nodes;

	insert(trie[i][s[0] - 'a'], s.substr(1, s.size()));
}

void solve(int i, string s)
{
	if (s.size() == 0)
	{
		++ans;
		return;
	}

	if ('a' <= s[0] && s[0] <= 'z')
	{
		if (trie[i][s[0] - 'a'])
			solve(trie[i][s[0] - 'a'], s.substr(1, s.size()));
	}
	else
	{
		s = s.substr(1, s.size());
		int j = 0;
		while (s[j] != ')')	++j;

		for (int k = 0; k < j; ++k)
		{
			if (trie[i][s[k] - 'a'])
				solve(trie[i][s[k] - 'a'], s.substr(j + 1, s.size()));
		}
	}
}

int	main()
{
	int	l, d, n;
	cin >> l >> d >> n;
	for (int i = 0; i < d; ++i)
	{
		string s;
		cin >> s;
		insert(0, s);
	}

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		ans = 0;
		solve(0, s);
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}


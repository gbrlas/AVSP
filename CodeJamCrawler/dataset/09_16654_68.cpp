#include <iostream>
#include <sstream>
#include <cstdio>

using	namespace	std;

string	name;
int	f;
string	ff[1000];

double	calc(double p, string tree)
{
	cerr << p << ' ' << tree << endl;
	while (tree[0] != '(')	tree = tree.substr(1, tree.size());
	tree = tree.substr(1, tree.size());

	stringstream strin(tree);
	double x;
	strin >> x;

	p *= x;

	string feature;
	strin >> feature;

	if (feature == ")")	return p;

	bool flag =false;
	for (int i = 0; i < f; ++i)
		if (ff[i] == feature)
		{
			flag = true;
			break;
		}

	while (tree[0] != '(')	tree = tree.substr(1, tree.size());

	if (flag)	return calc(p, tree);

	int c = 0;
	for (int i = 0; i < static_cast<int>(tree.size()); ++i)
	{
		if (tree[i] == '(')
			++c;
		else if (tree[i] == ')')
			--c;
		if (c == 0)
		{
			tree = tree.substr(i + 1, tree.size());
			break;
		}
	}
	return calc(p, tree);
}

void	solve()
{
	int	l;
	{
		string s;
		getline(cin, s);
		stringstream strin(s);
		strin >> l;
	}

	string tree;
	{
		string s;
		for (int i = 0; i < l; ++i)
		{
			string t;
			getline(cin, t);
			s += ' ' + t;
		}
		for (int i = 0; i < static_cast<int>(s.size()); ++i)
			if (s[i] == '(' || s[i] == ')')
				tree += string(" ") + s[i] + " ";
			else
				tree += s[i];
	}

	int	a;
	{
		string s;
		getline(cin, s);
		stringstream strin(s);
		strin >> a;
	}
	for (int i = 0; i < a; ++i)
	{
		string s;
		getline(cin, s);
		stringstream strin(s);

		strin >> name >> f;
		for (int j = 0; j < f; ++j)
			strin >> ff[j];

		printf("%.7f\n", calc(1, tree));
	}
}

int	main()
{
	string s;
	int n;
	getline(cin, s);
	stringstream strin(s);
	strin >> n;
	for (int i = 0; i < n; ++i)
	{
		printf("Case #%d:\n", i + 1);
		solve();
	}
	return	0;
}


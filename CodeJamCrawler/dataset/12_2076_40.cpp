#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector <char> a(26);
	a['a' - 'a'] = 'y';
	a['b' - 'a'] = 'h';
	a['c' - 'a'] = 'e';
	a['d' - 'a'] = 's';
	a['e' - 'a'] = 'o';
	a['f' - 'a'] = 'c';
	a['g' - 'a'] = 'v';
	a['h' - 'a'] = 'x';
	a['i' - 'a'] = 'd';
	a['j' - 'a'] = 'u';
	a['k' - 'a'] = 'i';
	a['l' - 'a'] = 'g';
	a['m' - 'a'] = 'l';
	a['n' - 'a'] = 'b';
	a['o' - 'a'] = 'k';
	a['p' - 'a'] = 'r';
	a['q' - 'a'] = 'z';
	a['r' - 'a'] = 't';
	a['s' - 'a'] = 'n';
	a['t' - 'a'] = 'w';
	a['u' - 'a'] = 'j';
	a['v' - 'a'] = 'p';
	a['w' - 'a'] = 'f';
	a['x' - 'a'] = 'm';
	a['y' - 'a'] = 'a';
	a['z' - 'a'] = 'q';
	int t;
	cin >> t;
	getchar();
	for (int it = 1; it <= t; ++it)
	{
		string s;
		getline(cin, s);
		printf("Case #%d: ", it);
		for (int i = 0; i < s.length(); ++i)
			cout << ((s[i] == ' ') ? ' ' : a[s[i] - 'a']);
		cout << endl;
	}
	return 0;
}
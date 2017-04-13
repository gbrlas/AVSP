#include <iostream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

string b = "welcome to code jam";
string s;
int d[512][32];

int Find(int i, int j)
{
	if(j >= b.size())
		return 1;
	if(i >= s.size())
		return 0;
	if(d[i][j] == -1)
	{
		d[i][j] = Find(i + 1, j);
		if(s[i] == b[j])
			d[i][j] += Find(i + 1, j + 1);
		d[i][j] %= 10000;
	}
	return d[i][j];
}

string ToStr(int v)
{
	ostringstream os;
	os << v / 1000 << (v / 100) % 10 << (v / 10) % 10 << v % 10;
	return os.str();
}

int main()
{
#ifndef DEBUG
	freopen("C-small.in", "rt", stdin);
	freopen("C-small.out", "wt", stdout);
#endif
	int n;
	cin >> n;
	getline(cin, s);
	for(int t = 1; t <= n; t++)
	{
		getline(cin, s);
		for(int i = 0; i < s.size(); i++)
			fill(d[i], d[i] + 32, -1);
		cout << "Case #" << t << ": " << ToStr(Find(0, 0)) << endl;
	}
	return 0;
}
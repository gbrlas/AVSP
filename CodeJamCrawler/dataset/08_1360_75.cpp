#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> name;

int a[100][1001];

int min(int a, int b) { return a < b ? a : b; }

int main()
{
	int n;
	cin >> n;
	for (int c = 1; c <= n; c++)
	{
		string st;
		int id = 0;
		int s, q;

		cin >> s;
		getline(cin, st);
		for (int i = 0; i < s; i++)
		{
			getline(cin, st);
			name[st] = id++;
		}
		for (int k = 0; k < s; k++) a[k][0] = 0;

		cin >> q;
		getline(cin, st);
		for (int i = 1; i <= q; i++)
		{
			getline(cin, st);
			id = name[st];
			for (int j = 0; j < s; j++)
			{
				int m = q;
				if (j != id) for (int k = 0; k < s; k++) m = min(m, a[k][i-1] + (j != k));
				a[j][i] = m;
			}
		}
		int m = q;
		for (int k = 0; k < s; k++) m = min(m, a[k][q]);
		printf("Case #%d: %d\n", c, m);
	}
	return 0;
}

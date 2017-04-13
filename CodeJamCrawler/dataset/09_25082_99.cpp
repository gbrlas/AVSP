#include <stdio.h>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <memory.h>
#include <sstream>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int l, d, n;

	scanf("%d %d %d", &l, &d, &n);
	vector<string> words;
	words.resize(d);
	for (int i = 0; i < d; ++i)
		cin >> words[i];

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		
		vector<int> word;
		for (int j = 0; j < s.size(); ++j)
		{
			int x = 0;
			if (s[j] == '(')
			{
				++j;
				while (s[j] != ')')
				{
					x |= 1 << (s[j] - 'a');
					++j;
				}
			}
			else
				x = 1 << (s[j] - 'a');
			word.push_back(x);
		}
		int res = 0;
		for (int j = 0; j < d; ++j)
		{
			bool ok = true;
			for (int k = 0; k < l; ++k)
			{
				if (((1 << (words[j][k] - 'a')) & word[k]) == 0)
				{
					ok = false;
					break;
				}
			}
			if (ok)
				++res;
		}
		printf("Case #%d: %d\n", i + 1, res);
	}

	return 0;
}
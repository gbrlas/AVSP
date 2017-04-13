# include <iostream>
# include <stdio.h>
# include <vector>
# include <string>
# include <string.h>

using namespace std;

const int NMAX = 128;

char combine[NMAX][NMAX];
bool opposite[NMAX][NMAX];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	cin >> test;

	for (int u = 0; u < test; ++u)
	{
		vector<char> spell;
		memset(combine, 0, sizeof(char) * NMAX * NMAX);
		memset(opposite, 0, sizeof(bool) * NMAX * NMAX);
		int c, d, n;
		cin >> c;
		for (int i = 0; i < c; ++i)
		{
			char c1, c2, c3;
			cin >> c1 >> c2 >> c3 ;
			combine[c1][c2] = c3;
			combine[c2][c1] = c3;
		}
		cin >> d;
		for (int i = 0; i < d; ++i)
		{
			char c1, c2;
			cin >> c1 >> c2 ;
			opposite[c1][c2] = true;
			opposite[c2][c1] = true;
		}
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			char c1;
			cin >> c1;
			if (spell.empty())
				spell.push_back(c1);
			else if (combine[c1][spell.back()] != 0)
				spell.back() = combine[c1][spell.back()];
			else 
			{
				for (int j = 0; j < spell.size(); ++j)
				{
					if (opposite[c1][spell[j]])
					{
						spell.clear();
						break;
					}
				}
				if (!spell.empty())
					spell.push_back(c1);
			}
		}
		
		cout << "Case #" << u + 1 << ": " << '[' ;
		if (!spell.empty())
		{
			for (int i = 0; i < spell.size() - 1; ++i)
				cout << spell[i] << ", " ;
			cout << spell.back();
		}
		cout << ']' << endl;
	}

	return 0;
}
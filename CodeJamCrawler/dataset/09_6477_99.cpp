#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int l,d,n;
	cin >> l >> d >> n;

	string word[6000];
	for (int i = 0; i<d; ++i)
	{
		cin >> word[i];
	}

	for (int t = 0; t<n; ++t)
	{
		string pattern;
		cin >> pattern;

		int matching[20]['z'+1];
		for (int i = 0; i<l; ++i)
			for (char c = 'a'; c<='z'; ++c)
				matching[i][c] = 0;

		int c = 0, i = 0;
		while (c<=pattern.length())
		{
			if (pattern[c] == '(')
			{
				++c;
				for (; pattern[c] != ')'; ++c)
					matching[i][pattern[c]] = 1;
			}
			else
			{
				matching[i][pattern[c]] = 1;				
			}
			++i; ++c;
		}

		/*for (int i = 0; i<l; ++i)
		{
			cout << "(";
			for (char c = 'a'; c<='z'; ++c)
				if (matching[i][c] == 1)
					cout << c;
			cout << ")";
		}
		cout << endl;
		cout << pattern << endl;*/

		int count = 0;
		for (int j = 0; j<d; ++j)
		{
			bool correct = true;
			for (int i = 0; (i<l)&&correct; ++i)
				if (matching[i][word[j][i]] == 0)
					correct = false;
			if (correct) ++count;
		}

		cout << "Case #" << t+1 << ": " << count << endl;
	}
}

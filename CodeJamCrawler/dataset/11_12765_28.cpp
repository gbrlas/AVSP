#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int r[t], c[t];
	string *s[t];
	
	for (int i = 0; i < t; i++)
	{
		cin >> r[i] >> c[i];
		s[i] = new string[r[i]];
		for (int j = 0; j < r[i]; j++)
			cin >> s[i][j];
	}
	
	for (int i = 0; i < t; i++)
	{
		bool possible = true;
		for(int j = 0; j < r[i]; j++)
		{
			for(int k = 0; k < c[i]; k++)
			{
				if (s[i][j][k] == '#')
				{
					s[i][j][k] = '/';
					
					if (j == r[i]-1 || s[i][j+1][k] != '#')
						possible = false;
					else
						s[i][j+1][k] = '\\';
					
					if (!possible)
						break;
					
					if (k == c[i]-1)
						possible = false;
					else
					{
						if (s[i][j][k+1] != '#')
							possible = false;
						else
							s[i][j][k+1] = '\\';
						
						if (s[i][j+1][k+1] != '#')
							possible = false;
						else
							s[i][j+1][k+1] = '/';
					}
				}
			}
			if (!possible)
				break;
		}
		cout << "Case #" << i+1 << ":\n";
		if (!possible)
			cout << "Impossible\n";
		else
		{
			for (int j = 0; j < r[i]; j++)
				cout << s[i][j] << "\n";
		}
	}
	
}


#include <iostream>

using namespace std;

int t;
string s[4], h = "XO";

bool hW(int ind)
{
	int x , y;
	for (int i = 0; i < 4; i++)
	{
		x = y = 0;
		for (int j = 0; j < 4; j++)
		{
			if (s[i][j] == h[ind] || s[i][j] == 'T')
				x++;
			if (s[j][i] == h[ind] || s[j][i] == 'T')
				y++;
		}
		if (x == 4 || y == 4)
			return true;
	}
	x = y = 0;
	for (int i = 0; i < 4; i++)
	{
		if (s[i][i] == h[ind] || s[i][i] == 'T')
			x++;
		if (s[i][3 - i] == h[ind] || s[i][3 - i] == 'T')
			y++;
	}
	if (x == 4 || y == 4)
		return true;
	return false;
}

bool isC()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (s[i][j] == '.')
				return false;
	return true;
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		for (int j = 0; j < 4; j++)
			cin >> s[j];
		if (hW(0))
			cout << "X won" << endl;
		else if (hW(1))
			cout << "O won" << endl;
		else if (isC())
			cout << "Draw" << endl;
		else
			cout << "Game has not completed" << endl;
	}
	return 0;
}
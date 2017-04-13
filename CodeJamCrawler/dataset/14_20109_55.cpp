#include <iostream>
using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);  
	freopen("A-small-attempt0.out", "w", stdout);  
	int T = 0, caseNum = 0;
	int a[4][4] = {0}, b[4][4] = {0};
	cin >> T;
	while (T--)
	{
		++caseNum;
		int repeatTime = 0, temp = 0, firstRow = 0, secondRow = 0;
		cin >> firstRow;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin >> a[i][j];
			}
		}
		cin >> secondRow;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin >> b[i][j];
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (a[firstRow - 1][i] == b[secondRow - 1][j])
				{
					temp = a[firstRow - 1][i];
					++repeatTime;
				}
			}
		}
		if (repeatTime == 1)
		{
			cout << "Case #" << caseNum << ": " << temp << endl;
		}
		else if (repeatTime > 1)
		{
			cout << "Case #" << caseNum << ": Bad magician!" << endl;
		}
		else
		{
			cout << "Case #" << caseNum << ": Volunteer cheated!" << endl;
		}
	}
	return 0;
}
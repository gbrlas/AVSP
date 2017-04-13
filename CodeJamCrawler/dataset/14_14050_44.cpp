#include <iostream>

using namespace std;

int main()
{
	int T;
	int a[4][4];
	int selRow1[4];
	int selRow2[4];
	cin >> T;

	for(int i = 0; i < T; ++i)
	{
		int ans1;
		cin >> ans1;

		for(int j = 0; j < 4; ++j)
		{
			for(int k = 0; k < 4; ++k)
			{
				cin >> a[j][k];
				if(j == ans1 -1)
					selRow1[k] = a[j][k];
			}
		}
		int ans2;
		cin >> ans2;

		for(int j = 0; j < 4; ++j)
		{
			for(int k = 0; k < 4; ++k)
			{
				cin >> a[j][k];
				if(j == ans2 -1)
					selRow2[k] = a[j][k];
			}
		}

		int count = 0;
		int finalans = 0;
		for(int j = 0; j < 4; ++j)
		{
			for(int k = 0; k < 4; ++k)
			{
				if(selRow1[j] == selRow2[k])
				{
					++count;
					finalans = selRow2[k];
				}
			}
		}

		if(count == 1)
			cout << "Case #" << i + 1 << ": " << finalans << endl;
		else if(count > 1)
			cout << "Case #" << i + 1 << ": " << "Bad magician!" << endl;
		else 
			cout << "Case #" << i + 1 << ": " << "Volunteer cheated!" << endl;

	}

	return 0;
}
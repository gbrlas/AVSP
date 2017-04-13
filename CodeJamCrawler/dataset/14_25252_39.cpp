#include <iostream>
#include <cstring>

using namespace std;

int c[17];

int main()
{
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	for (int k = 1; k <= t; ++k)
	{
		memset(c, 0, sizeof(c));
		int r;
		for (int l = 0; l < 2; ++l)
		{
			cin >> r; r--;
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
				{
					int curr;
					cin >> curr;
					if (i == r)
						c[curr]++;
				}
		}
		int count = 0;
		int res;
		for (int i = 1; i <= 16; ++i)
		{
			if (c[i] == 2)
			{
				count++;
				res = i;
			}
		}
		cout << "Case #" << k << ": ";
		if (count > 1)
			cout << "Bad magician!";
		else if (count == 0)
			cout << "Volunteer cheated!";
		else
			cout << res;
		cout << "\n";
	}
	return 0;
}

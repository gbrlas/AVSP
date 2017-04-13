#include <iostream>
using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out", "w", stdout);
	int cas, T;
	cin >> T;
	for(cas = 1; cas <= T; cas++)
	{
		int first, second, i, j, temp, flag[17];
		memset(flag, 0, sizeof(flag));
		cin >> first;
		for(i = 1; i <= 4; i++)
		{
			for(j = 1; j <= 4; j++)
			{
				cin >> temp;
				if(i == first)
					flag[temp]++;
			}
		}
		cin >> second;
		for(i = 1; i <= 4; i++)
		{
			for(j = 1; j <= 4; j++)
			{
				cin >> temp;
				if(i == second)
					flag[temp]++;
			}
		}
		int count = 0, result;
		for(i = 1; i <= 16; i++)
		{
			if(flag[i] == 2)
			{
				count++;
				result = i;
			}
		}
		cout << "Case #" << cas << ": ";
		if(count == 0)
			cout << "Volunteer cheated!" << endl;
		else if(count == 1)
			cout << result << endl;
		else
			cout << "Bad magician!" << endl;
	}
}
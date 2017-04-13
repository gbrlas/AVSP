#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int n[t], l[t], h[t];
	int *f[t];

	for (int i = 0; i < t; i++)
	{
		cin >> n[i] >> l[i]>>h[i];
		f[i] = new int[n[i]];
		
		for (int j = 0; j < n[i]; j++)
			cin >> f[i][j];
	}
	
	for (int i = 0; i < t; i++)
	{
		bool printed = false;
		for (int j = l[i]; j <= h[i]; j++)
		{
			bool p = true;
			for (int k = 0; k < n[i]; k++)
			{
				if (!(((float)f[i][k])/j == f[i][k]/j || (j/(float)f[i][k]) == j/f[i][k]))
				{
					p = false;
					break;
				}
			}
			if (p)
			{
				cout << "Case #" << i+1 << ": " << j << endl;
				printed = true;
				break;
			}
		}
		if (!printed)
			cout << "Case #" << i+1 << ": NO" << endl;
	}
}


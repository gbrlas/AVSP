# include <iostream>
# include <stdio.h>
# include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;	
	cin >> test;

	for (int u = 0; u < test; ++u)
	{
		int n, min = 1e7, sum = 0, xor = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int candy;
			cin >> candy;
			sum += candy;
			min = (candy < min) ? candy : min ;
			xor ^= candy;
		}
		
		cout << "Case #" << u + 1 << ": ";
		if (xor != 0)
			cout << "NO" << endl;
		else
			cout << sum - min << endl;
	}

	return 0;
}
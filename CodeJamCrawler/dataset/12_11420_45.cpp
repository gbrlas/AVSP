#include <iostream>

using namespace std;

int mod[] = {0, 10, 100, 1000};

int digits(int k) //assume k <= 1000
{
	if (k >= 1000)
		return 4;
	else if (k >= 100)
		return 3;
	else if (k >= 10)
		return 2;
	else 
		return 1;
}

int main()
{
	int t;
	cin >> t;
	for (int ca = 1; ca <= t; ca++)
	{
		int a, b, ans = 0;
		cin >> a >> b;
		for (int i = a; i <= b; i++)
		{
			for (int j = i+1; j <= b; j++)
			{
				int d = digits(j);
				for (int k = 1; k <= d-1; k++)
				{
					int low = i % mod[k];
					int high = i / mod[k];
					if (low * mod[d-k] + high == j)
					{
						ans++;
						break;
					}
				}
			}
		}
		cout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}
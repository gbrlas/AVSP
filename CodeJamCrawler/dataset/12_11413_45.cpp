#include <iostream>

using namespace std;



int main()
{
	int T, ans, x, y, z;
	int n, s, p, sum, m1, m2;
	cin >> T;
	for (int ca = 1; ca <= T; ca++)
	{
		ans = x = y = z = 0;
		cin >> n >> s >> p;
		for (int i = 1; i <= n; i++)
		{
			cin >> sum;
			m1 = m2 = 0;
			if (sum >= 2)
			{
				if ((sum+4) % 3 == 0)
					m2 = (sum+4) / 3;
				else if ((sum+3) % 3 == 0)
					m2 = (sum+3) / 3;
				else if ((sum+2) % 3 == 0)
					m2 = (sum+2) / 3;
			}
			if ((sum+2) % 3 == 0)
				m1 = (sum+2) / 3;
			else if ((sum+1) % 3 == 0)
				m1 = (sum+1) / 3;
			else if (sum % 3 == 0)
				m1 = sum / 3;
			
			if (m1 >= p && m2 >= p)
				y++;
			else if (m1 >= p)
				x++;
			else if (m2 >= p)
				z++;
			
		}
		if (s <= z)
			ans = x + y + s;
		else if (s <= y+z)
			ans = x + y + z;
		else if (s <= n-x)
			ans = x + y + z;
		else
			ans = x + y + z - s;
		cout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}
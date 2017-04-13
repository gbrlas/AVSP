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
		int timer = 0;

		int x = 1, y = 1, n, idle_x = 0, idle_y = 0, action_x = 0, action_y = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			char c;
			int p;
			cin >> c >> p;
			if (c == 'O')
			{
				int d = abs(p - x);
				d = (idle_x > d) ? 0 : d - idle_x;
				idle_x = 0;
				timer += d + 1;
				idle_y = timer - action_y;
				action_x = timer;
				x = p;

			}
			else
			{
				int d = abs(p - y);
				d = (idle_y > d) ? 0 : d - idle_y;
				idle_y = 0;
				timer += d + 1;
				idle_x = timer - action_x;
				action_y = timer;
				y = p;
			}
		}
		
		cout << "Case #" << u + 1 << ": " << timer << endl;
	}

	return 0;
}
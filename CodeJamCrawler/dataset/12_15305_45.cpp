#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	freopen("B-small-in.txt", "r", stdin);
	freopen("B-small-out.txt", "w", stdout);
	int T, N, S, p;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> S >> p;
		int ans = 0, t[N], t_p[N], t_ps[N], l_s = S;
		for (int j = 0; j < N; j++)
		{
			cin >> t[j];
			t_p[j] = (t[j] + 2) / 3;
			if (t[j] >= 2 && t[j] <= 28) t_ps[j] = (t[j] + 4) / 3;
			else t_ps[j] = 0;
		}
		for (int j = 0; j < N; j++)
		{
			if (t_p[j] >= p)
			{
			    ans++;
			}
			else if (l_s > 0 && t_ps[j] >= p)
			{
				l_s--;
				ans++;
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << endl; 
	}
	return 0;
}
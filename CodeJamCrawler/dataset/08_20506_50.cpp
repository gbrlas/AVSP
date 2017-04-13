#include <cstdio>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int cnt[2000][200];


int main()
{
	freopen("A-large.in", "rt", stdin);
	int n, m, q;
	cin >> n;
	string items[200];
	string queries[2000];
	char tmp[300000];
	for (int t = 0; t < n; t++)
	{
		cin >> m;
		cin.getline(tmp, 300000);
		for (int i = 0; i < m; i++) 
		{
			cin.getline(tmp, 300000);
			items[i] = string(tmp);
		}
		cin >> q;
		cin.getline(tmp, 300000);
		if (q == 0) 
		{
				cout << "Case #" << t + 1 << ": " << 0 << endl;
				continue;
		}
		for (int i = 0; i < q; i++) {
			cin.getline(tmp, 300000);
			queries[i] = string(tmp);
		}
		for (int i = 0; i < m; i++)
			if (items[i] == queries[q - 1])
				cnt[q - 1][i] = 5000;
			else
				cnt[q - 1][i] = 0;
		for (int i = q - 2; i >= 0; i--)
			for (int j = 0; j < m; j++) {
				cnt[i][j] = 5000;
				if (items[j] != queries[i])
				{
					for (int k = 0; k < m; k++) if (k != j)
						cnt[i][j] = min(cnt[i][j], 1 + cnt[i + 1][k]);
					else
						cnt[i][j] = min(cnt[i][j], cnt[i + 1][k]);
				}
			}
		
		int res = 5000;
		for (int i = 0; i < m; i++)
			res = min(res, cnt[0][i]);
		cout << "Case #" << t + 1 << ": " << res << endl;
	}
}
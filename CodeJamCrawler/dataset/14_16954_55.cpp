#include <iostream>
#include <cstdio>

using namespace std;

void doit(int x)
{
	int r1,r2;
	int a1[5][5],a2[5][5];
	cin >> r1;
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			cin >> a1[i][j];
	cin >> r2;
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			cin >> a2[i][j];
	int b1[5],b2[5];
	for (int i = 1; i <= 4; ++i)
	{
		b1[i] = a1[r1][i];
		b2[i] = a2[r2][i];
	}

	int cnt = 0, ans;

	for (int i = 1; i <= 4; ++i)
	{
		int temp = b1[i];
		for (int j = 1; j <= 4; ++j)
			if (b2[j] == temp)
			{
				++cnt;
				ans = temp;
			}
	}
	if (cnt == 1)
		cout << "Case #" << x << ": " << ans << endl;
	if (cnt != 1 && cnt != 0)
		cout << "Case #" << x << ": Bad magician!" << endl;
	if (cnt == 0)
		cout << "Case #" << x << ": Volunteer cheated!" << endl;;
	return;
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		doit(i);
	}
}
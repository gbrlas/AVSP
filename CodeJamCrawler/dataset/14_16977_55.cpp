#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void doit(int x)
{
	double a[1005],b[1005];
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);

	int pointer1 = 1;
	int pointer2 = 1;
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n && pointer2 <= n; ++i)
	{
		for (;pointer2 <= n;)
			if (a[i] < b[pointer2])
			{
				++ans2;
				++pointer2;
				break;
			}
			else
				++pointer2;
	}
	for (int i = 1; i <= n && pointer1 <= n; ++i)
	{
		for (;pointer1 <= n;)
		{
			if (b[i] < a[pointer1])
			{
				++ans1;
				++pointer1;
				break;
			}
			else
				++pointer1;
		}
	}
	cout << "Case #" << x << ": " << ans1 << " " << n - ans2 <<endl;
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
	return 0;
}
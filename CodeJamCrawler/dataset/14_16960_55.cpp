#include <iostream>
#include <cstdio>
using namespace std;

double doit()
{
	double c,f,x;
	cin >> c >> f >> x;
	double rate = 2;
	double ans = 0;
	for (;;)
	{
		double time1 = x / rate;
		double time2 = x / (f+rate) + c / rate;
		if (time1 <= time2)
			return ans + time1;
		else
		{
			ans += c / rate;
			rate += f;
		}
	}
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		double ans = doit();
		cout << "Case #" << i << ": ";
		printf("%.7f\n",ans);
	}
	return 0;
}
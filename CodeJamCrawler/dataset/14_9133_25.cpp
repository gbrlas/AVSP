#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void test(int t)
{
	double c, f, x;
	cin >> c >> f >> x;
	double gen = 2;
	bool done = false;
	double time_res = 0;
	while(!done)
	{
		double time1 = c/gen + x / (gen + f);
		double time2 = x / gen;
		if (time2 < time1)
		{
			done = true;
			time_res += time2;
		}
		else
		{
			time_res += c/gen;
			gen += f;
		}
	}
	cout << "Case #" << t << ": " << fixed << setprecision(7) << showpoint << time_res << endl;
}

int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) test(i);
}
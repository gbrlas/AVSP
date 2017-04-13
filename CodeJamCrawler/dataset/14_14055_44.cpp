#include <iostream>
#include <cstdio>

using namespace std;

double getTime(double currRate, double c, double f, double x)
{
	double tim = 0, final = 0;
	tim = c / currRate;
	if(tim + x / (currRate + f) < x / currRate)
	{
		final = tim + getTime(currRate + f, c, f, x);
	}
	else
		final = x / currRate;

	return final;
}

int main()
{
	int T;
	cin >> T;

	double c, f, x, myTime;

	for(int i = 0; i < T; ++i)
	{
		cin >> c;
		cin >> f;
		cin >> x;

		if(x < c || f == 0)
		{
			myTime = x / 2;
		}
		else
		{
			myTime = getTime(2.0, c, f, x);
		}

		printf("Case #%d: %0.7f\n", i+1, myTime);
	}

}
// CodeJam2014.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>
using namespace std;

int T;
double C, F, X;



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%lf%lf%lf", &C, &F, &X);

		double time = 0, speed = 2;

		while (true)
		{
			double buy_t;
			double not_t;
			buy_t = time + C / speed + X / (speed + F);
			not_t = time + X / speed;
			if (buy_t < not_t)
			{
				time = time + C / speed;
				speed += F;
			}
			else
			{
				time = not_t;
				break;
			}
		}
		printf("Case #%d: %.7lf\n", i + 1, time);
	}
}
#include <iostream>
using namespace std;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("out2", "w", stdout);
	int cas, T;
	cin >> T;
	for(cas = 1; cas <= T; cas++)
	{
		double C, F, X, protime, totaltime, temp, speed;
		cin >> C >> F >> X;
		int num = 0;
		speed = 2, totaltime = X, protime = 0;
		while(1)
		{
			temp = protime + X / speed;
			if(temp < totaltime)
				totaltime = temp;
			else
				break;

			protime += C / speed;
			speed += F;
			num++;
		}
		cout << "Case #" << cas << ": ";
		printf("%.7lf\n", totaltime);
	}
	return 0;
}
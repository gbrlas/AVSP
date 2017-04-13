#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const double pi = 3.141592653589;

bool buy (double c, double f, double x, double& cur_spd, double& time)
{
	if (x/cur_spd > c/cur_spd + x/(cur_spd + f))
	{
		time += c/cur_spd;
		cur_spd += f;
		return true;
	} 
	else
	{
		time += x/cur_spd;
		return false;
	}
}

void answer (double c, double f, double x)
{
	double time = 0;
	double cur_spd = 2;
	bool flag = true;
	while (flag)
		flag = buy(c, f, x, cur_spd, time);
	cout << setprecision(10) <<time << endl;
	return;
}

int main()
{
	int T; cin >> T;
	double c, f, x;
	for (int i=0; i<T; ++i)
	{
		cin >> c >> f >> x;
		cout << "Case #" << i+1 << ": ";
		answer(c, f , x);
	}
	return 0;
}

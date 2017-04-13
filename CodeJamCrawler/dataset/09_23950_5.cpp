#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

double max(double a, double b)
{
	return a > b ? a : b;
}

int main()
{
	ifstream in("D.in");
	ofstream out("D.out");

	int tests;
	in >> tests;
	for (int i=1; i<=tests; i++)
	{
		int flowers;
		in >> flowers;

		int tx, ty, tr;
		vector<int> posx, posy, rad;
		while (flowers--)
		{
			in >> tx >> ty >> tr;
			posx.push_back(tx);
			posy.push_back(ty);
			rad.push_back(tr);
		}

		switch (rad.size())
		{
		case 1:
			out << "Case #" << i << ": " << rad[0] << endl;
			break;

		case 2:
			out << "Case #" << i << ": " << max(rad[0], rad[1]) << endl;
			break;

		case 3:
			double sol1 = max(rad[0], ((rad[1] + rad[2] + sqrt((double)(posx[1] - posx[2]) * (posx[1] - posx[2]) + (posy[1] - posy[2]) * (posy[1] - posy[2]))) / 2.0));
			double sol2 = max(rad[1], ((rad[0] + rad[2] + sqrt((double)(posx[0] - posx[2]) * (posx[0] - posx[2]) + (posy[0] - posy[2]) * (posy[0] - posy[2]))) / 2.0));
			double sol3 = max(rad[2], ((rad[1] + rad[0] + sqrt((double)(posx[1] - posx[0]) * (posx[1] - posx[0]) + (posy[1] - posy[0]) * (posy[1] - posy[0]))) / 2.0));
			out << "Case #" << i << ": " << min(min(sol1, sol2), sol3) << endl;
			break;
		}
	}

	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

#define PI 3.14159265358979

int main()
{
	ifstream ifs;
	ofstream ofs;
	string buf;
	int n = 0;
//	ifs.open("C-example.in", ios::in);
//	ifs.open("C-small-attempt0.in", ios::in);
	ifs.open("C-large.in", ios::in);
//	ofs.open("C-example.out", ios::out);
//	ofs.open("C-small-attempt0.out", ios::out);
	ofs.open("C-large.out", ios::out);
	getline(ifs, buf);
	n = atoi(buf.c_str());
	for(int i = 0; i < n; i++)
	{
		double f, R, t, r, g;
		getline(ifs, buf);
		sscanf(buf.c_str(), "%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
		int j = 0;
		double d = r + f;
		double s = 0.0;
		if(g <= 2 * f)
		{
			ofs << "Case #" << i + 1 << ": 1.000000" << endl;
			continue;
		}
		while((d / sqrt(2)) < (R - t - f))
		{
			d += g + 2 * r;
			j++;
			for(int k = 0; k < j; k++)
			{
				double ts = 0.0;
				if((r + f + (j - k - 1) * (g + 2 * r)) * (r + f + (j - k - 1) * (g + 2 * r)) + (r + f + k * (g + 2 * r)) * (r + f + k * (g + 2 * r)) > (R - t - f) * (R - t - f)) continue;
				if((r + g - f + (j - k - 1) * (g + 2 * r)) * (r + g - f + (j - k - 1) * (g + 2 * r)) + (r + g - f + k * (g + 2 * r)) * (r + g - f + k * (g + 2 * r)) < (R - t - f) * (R - t - f))
				{
					s += (g - 2 * f) * (g - 2 * f);
					continue;
				}
				int f1 = 0, f2 = 0;
				if((r + f + (j - k - 1) * (g + 2 * r)) * (r + f + (j - k - 1) * (g + 2 * r)) + (r + g - f + k * (g + 2 * r)) * (r + g - f + k * (g + 2 * r)) < (R - t - f) * (R - t - f)) f1 = 1;
				if((r + g - f + (j - k - 1) * (g + 2 * r)) * (r + g - f + (j - k - 1) * (g + 2 * r)) + (r + f + k * (g + 2 * r)) * (r + f + k * (g + 2 * r)) < (R - t - f) * (R - t - f)) f2 = 1;
				if(f1 == 1 && f2 == 1)
				{
					double t1 = acos((r + g - f + (j - k - 1) * (g + 2 * r)) / (R - t - f));
					double t2 = acos((r + g - f + k * (g + 2 * r)) / (R - t - f));
					double t0 = PI * 0.5 - t1 - t2;
					double tr1 = (R - t - f) * (r + g - f + (j - k - 1) * (g + 2 * r)) * sin(t1) * 0.5;
					double tr2 = (R - t - f) * (r + g - f + k * (g + 2 * r)) * sin(t2) * 0.5;
					double lft = (R - t - f) * cos(t1) * (R - t - f) * cos(t2) - tr1 - tr2 - (R - t - f) * (R - t - f) * t0 * 0.5;
					ts = (g - 2 * f) * (g - 2 * f) - lft;
				}
				else if(f1 == 1 && f2 == 0)
				{
					double t1 = asin((r + f + k * (g + 2 * r)) / (R - t - f));
					double t2 = acos((r + g - f + k * (g + 2 * r)) / (R - t - f));
					double t0 = PI * 0.5 - t1 - t2;
					double lft = (R - t - f) * cos(t1) * (r + g - f + k * (g + 2 * r)) - (R - t - f) * sin(t1) * (R - t - f) * cos(t1) * 0.5 - (R - t - f) * sin(t2) * (R - t - f) * cos(t2) * 0.5 - t0 * (R - t - f) * (R - t - f) * 0.5;
					double lb = (r + g - f + (j - k - 1) * (g + 2 * r) - cos(t1) * (R - t - f)) * (g - 2 * f);
					ts = (g - 2 * f) * (g - 2 * f) - lft - lb;
				}
				else if(f1 == 0 && f2 == 1)
				{
					double t1 = asin((r + f + (j - k - 1) * (g + 2 * r)) / (R - t - f));
					double t2 = acos((r + g - f + (j - k - 1) * (g + 2 * r)) / (R - t - f));
					double t0 = PI * 0.5 - t1 - t2;
					double lft = (R - t - f) * cos(t1) * (r + g - f + (j - k - 1) * (g + 2 * r)) - (R - t - f) * sin(t1) * (R - t - f) * cos(t1) * 0.5 - (R - t - f) * sin(t2) * (R - t - f) * cos(t2) * 0.5 - t0 * (R - t - f) * (R - t - f) * 0.5;
					double lb = (r + g - f + k * (g + 2 * r) - cos(t1) * (R - t - f)) * (g - 2 * f);
					ts = (g - 2 * f) * (g - 2 * f) - lft - lb;
				}
				else if(f1 == 0 && f2 == 0)
				{
					double t1 = asin((r + f + (j - k - 1) * (g + 2 * r)) / (R - t - f));
					double t2 = asin((r + f + k * (g + 2 * r)) / (R - t - f));
					double t0 = PI * 0.5 - t1 - t2;
					double tr1 = ((R - t - f) * cos(t1) - (R - t - f) * sin(t2)) * (R - t - f) * sin(t1) * 0.5;
					double tr2 = ((R - t - f) * cos(t2) - (R - t - f) * sin(t1)) * (R - t - f) * sin(t2) * 0.5;
					ts = (R - t - f) * (R - t - f) * t0 * 0.5 - tr1 - tr2;
				}
				s += ts;
			}
		}
		char bf[128];
		sprintf(bf, "%.6lf", 1 - (s * 4) / (R * R * PI));
		ofs << "Case #" << i + 1 << ": " << bf << endl;
	}
	return 0;
}

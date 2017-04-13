/*
	雛形(GCJ仕様)
 */

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
static const double EPS = 1e-9;
typedef long long ll;

//small only
int main()
{
	string filename, infile, outfile;
	cin >> filename;
	infile = filename + ".in";
	outfile = filename + ".out";
	ifstream ifs;
	ofstream ofs;
	ifs.open(infile.c_str(), ios::in);
	ofs.open(outfile.c_str(), ios::out);
	int Casenum;
	ifs >> Casenum;
	for(int Casecount = 0; Casecount < Casenum; Casecount++)
	{
		int n;
		double ans;
		ifs >> n;
		double x[50];
		double y[50];
		double r[50];
		for(int i = 0; i < n; i++)
			ifs >> x[i] >> y[i] >> r[i];
		if(n == 1) ans = r[0];
		else if(n == 2) ans = max(r[0], r[1]);
		else if(n == 3)
		{
			double ans1 = max(r[2], (sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1])) + r[0] + r[1]) / 2);
			double ans2 = max(r[0], (sqrt((x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2])) + r[1] + r[2]) / 2);
			double ans3 = max(r[1], (sqrt((x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0])) + r[2] + r[0]) / 2);
			ans = min(min(ans1, ans2), ans3);
		}
		char buf[50] = {0};
		sprintf(buf, "%.8lf", ans);
		ofs << "Case #" << (Casecount + 1) << ": " << buf << endl;
		cout << "Case #" << (Casecount + 1) << " done." << endl;
	}
}

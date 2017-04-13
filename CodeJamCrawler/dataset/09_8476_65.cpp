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
		int n = 0;
		double mx = 0, my = 0, mz = 0;
		double mvx = 0, mvy = 0, mvz = 0;
		ifs >> n;
		for(int i = 0; i < n; i++)
		{
			double x, y, z;
			double vx, vy, vz;
			ifs >> x >> y >> z >> vx >> vy >> vz;
			mx += x;
			my += y;
			mz += z;
			mvx += vx;
			mvy += vy;
			mvz += vz;
		}
		mx = mx / n;
		my = my / n;
		mz = mz / n;
		mvx = mvx / n;
		mvy = mvy / n;
		mvz = mvz / n;
		double t;
		if((mvx * mvx + mvy * mvy + mvz * mvz) <= EPS) t = 0;
		else t = -(mx * mvx + my * mvy + mz * mvz) / (mvx * mvx + mvy * mvy + mvz * mvz);
		if(t < 0) t = 0;
		double mdx, mdy, mdz;
		mdx = mx + t * mvx;
		mdy = my + t * mvy;
		mdz = mz + t * mvz;
		double d = sqrt(mdx * mdx + mdy * mdy + mdz * mdz);
		char buf[100];
		sprintf(buf, "%.8lf %.8lf", d, t);
		ofs << "Case #" << (Casecount + 1) << ": " << buf << endl;
		cout << "Case #" << (Casecount + 1) << " done." << endl;
	}
}

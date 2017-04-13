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
		int n;
		int lastone[50] = {0};
		ifs >> n;
		for(int i = 0; i < n; i++)
		{
			char c;
			int r = 0;
			for(int j = 0; j < n; j++)
			{
				ifs >> c;
				if(c == '1') r = j;
			}
			lastone[i] = r;
		}
		int cur = 0;
		int ans = 0;
		for(int rcnt = 0; rcnt < n; rcnt++)
		{
			if(lastone[rcnt] <= rcnt)
				continue;
			for(int i = rcnt + 1; i < n; i++)
			{
				if(lastone[i] <= rcnt)
				{
					int t = lastone[i];
					for(int k = i; k > rcnt; k--)
						lastone[k] = lastone[k - 1];
					lastone[rcnt] = t;
					ans += (i - rcnt);
					break;
				}
			}
		}
		ofs << "Case #" << (Casecount + 1) << ": " << ans << endl;
		cout << "Case #" << (Casecount + 1) << " done." << endl;
	}
}

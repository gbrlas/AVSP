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

int p, q;
int chain[101];
int qlist[101];

int solve(int n)
{
	if(n == q) return 0;
	int minans = 10000000;
	int ans = 0;
	for(int i = 0; i < q; i++)
	{
		ans = 0;
		if(chain[qlist[i]] == 0) continue;
		chain[qlist[i]] = 0;
		for(int j = qlist[i] + 1; chain[j] != 0 && j <= p; j++)
			ans++;
		for(int j = qlist[i] - 1; chain[j] != 0 && j >= 1; j--)
			ans++;
		ans += solve(n + 1);
		chain[qlist[i]] = 1;
		if(ans < minans)
			minans = ans;
	}
	return minans;
}

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
		ifs >> p >> q;
		memset(qlist, 0, sizeof(qlist));
		memset(chain, 1, sizeof(chain));
		for(int i = 0; i < q; i++) ifs >> qlist[i];
		int wlist[102];
		int w = 1;
		for(int i = 0; i < q; i++)
		{
			wlist[i] = qlist[i] - w;
			w = qlist[i] + 1;
		}
		wlist[q] = p - w + 1;
		int qq = q;
		int ans = 0;
		for(int i = 0; i < q; i++)
		{
			int ming = p;
			int minj = -1;
			for(int j = 0; j < qq; j++)
			{
				int paircost = wlist[j] + wlist[j + 1];
				if(paircost < ming)
				{
					ming = paircost;
					minj = j;
				}
			}
			ans += ming;
			wlist[minj] = ming + 1;
			for(int j = minj + 1; j < qq; j++)
				wlist[j] = wlist[j + 1];
			qq--;
		}
		ofs << "Case #" << (Casecount + 1) << ": " << solve(0) << endl;
		cout << "Case #" << (Casecount + 1) << " done." << endl;
	}
}

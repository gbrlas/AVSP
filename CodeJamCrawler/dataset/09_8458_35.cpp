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
		string str;
		ifs >> str;
		vector<char> neko;
		for(int i = 0; i < str.length(); i++)
			neko.push_back(str[i]);
		str = "";
		if(next_permutation(neko.begin(), neko.end()))
		{
			for(int i = 0; i < neko.size(); i++)
				str += neko[i];
		}
		else
		{
			vector<char>::iterator it = neko.begin();
			while(*it == '0') it++;
			str += *it;
			str += '0';
			neko.erase(it);
			for(int i = 0; i < neko.size(); i++)
				str += neko[i];
		}
		
		ofs << "Case #" << (Casecount + 1) << ": ";
		int i = 0;
		while(str[i] == '0') i++;
		for(; i < str.length(); i++)
			ofs << str[i];
		ofs << endl;
		cout << "Case #" << (Casecount + 1) << " done." << endl;
	}
}


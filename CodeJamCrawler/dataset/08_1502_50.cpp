#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

typedef signed long long i64;  typedef unsigned long long u64;

typedef vector<int> VI;
typedef vector<string> VS;

#define forn(i,n) for(int i=0;i<n;i++)
#define fors(i,s) forn(i,s.length())
#define forv(i,v) forn(i,v.size())

#define pb push_back
#define all(v) v.begin(), v.end()

template<class T> T str2t(string s, T dummy)
{
	stringstream ss; T res;
	ss << s, ss >> res;
	return res;
}

template<class T> string t2str(T ind)
{
	stringstream ss; string res;
	ss << ind, ss >> res;
	return res;
}

void ASSERT(int condition, const string& message) {
	if (!condition) {
		cerr << message;
		exit(37);
	}
};

int time2int(const string& s) {
	int h = (s[0] - '0') * 10 + (s[1] - '0');
	int m = (s[3] - '0') * 10 + (s[4] - '0');
	return h * 60 +m;
}

int main(void)
{
	ifstream inf ("B-large.in");
	ofstream ouf ("output.txt");

	int t;
	inf >> t; 
	forn(tt, t) {
		int T, na, nb;
		inf >> T >> na >> nb;
		vector<vector<int> > fa(24*60, VI()),fb(24*60, VI());
		forn(i, na) {
			string st,fn;
			inf >> st >> fn;
			fa[time2int(st)].pb(time2int(fn));
		}
		forn(i, nb) {
			string st,fn;
			inf >> st >> fn;
			fb[time2int(st)].pb(time2int(fn));
		}
		int ansa = 0, ansb = 0;
		int cra = 0, crb = 0;
		vector<int> adda(24*60 + 60, 0), addb(24*60+ 60, 0);
		for(int i=0; i<24*60; i++) {
			cra += adda[i];
			crb += addb[i];
			if (cra < fa[i].size()) {
				ansa += fa[i].size() - cra;
				cra = fa[i].size();
			}
			forv(j, fa[i]) {
				cra--;
				addb[fa[i][j]+T]++;
			}
			if (crb < fb[i].size()) {
				ansb += fb[i].size() - crb;
				crb = fb[i].size();
			}
			forv(j, fb[i]) {
				crb--;
				adda[fb[i][j]+T]++;
			}
		}
		ouf << "Case #" << (tt + 1) << ": " << ansa << " " << ansb << endl;
	}

	ouf.close();

    return 0;
}


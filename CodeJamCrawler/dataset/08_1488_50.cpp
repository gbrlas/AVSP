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

int main(void)
{
	ifstream inf ("A-small-attempt0.in");
	ofstream ouf ("output.txt");

	int t;
	inf >> t;

	forn(tt, t) {
		int n,m;
		inf >> n;
		string s;
		getline(inf, s);
		forn(i, n) getline(inf, s);
		inf >> m;
		getline(inf, s);
		set<string> cr;
		int ans = 0;
		forn(i,m) {
			getline(inf, s);
			cr.insert(s);
			if (cr.size() == n) {
				ans++;
				cr.clear();
				cr.insert(s);
			}
		}
		ouf << "Case #" << tt+1 << ": " << ans << endl;
	}

	ouf.close();

    return 0;
}


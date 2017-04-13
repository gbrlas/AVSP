#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair
#define FS first
#define SC second
#define SZ size() 


using namespace std;

const string pattern = "welcome to code jam";
string where;

const int MAX_PATTERN = 50;
const int MAX_WHERE = 500;

const int MOD = 10000;

int table[MAX_PATTERN][MAX_WHERE];

int count(int P, int W)
{
	int &result = table[P][W];

	if (result != -1)
		return result;

	if (P >= pattern.size())
		return result = 1;

	result = 0;

	for(int w = W; w < where.size(); ++w)
	{
		if (where[w] == pattern[P])
		{
			result += count(P+1, w+1);
			result %=MOD;
		}
	}

	return result%=MOD;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int N;
	string str;
	getline(cin, str);
	stringstream ss;
	ss << str;
	ss >> N;

	REP(n,N)
	{
		getline(cin, where);
		
		memset(table, -1, sizeof(table));
		int result = count(0,0);
		printf("Case #%d: %04d\n", n+1, result);
	}

}
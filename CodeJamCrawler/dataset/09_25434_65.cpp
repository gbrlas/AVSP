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


#define MAX_SIZE 100

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
		string str;
		getline(cin, str);

		VI digs;
		digs.push_back(1);
		digs.push_back(0);
		FOR(i, 2, MAX_SIZE)
			digs.push_back(i);

		map<char,int> m;

		VI res;
		REP(i, str.size())
		{
			if (m.count(str[i])==0)
			{
				int sz = m.size();
				m[str[i]] = digs[sz];
			}

			res.push_back(m[str[i]]);
		}

		long long base = max<long long>(2LL,m.size());

		long long p = 1;
		reverse(ALL(res));

		
		long long result = 0;

		REP(i, res.size())
		{
			result += p*res[i];
			p *= base;
		}


			cout << "Case #" << (n+1) << ": " << result << "\n";

		

	}




}
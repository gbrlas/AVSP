#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define SIZE(v) ((int)(v).size())

#define FOR(i,a,b) for (int i=(a),_n=(b); i < _n; i++) 
#define FORE(i,a,b) for (int i=(a),_n=(b); i <= _n; i++) 

#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)

#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))

#define FORI(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

#define CLEAR(x) memset(x,0,sizeof(x)); 

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

typedef long long LL; 
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI; 
typedef vector<string> VS;
typedef pair <int, int> pii; 

#define D(X) {cerr << #X << " = '" << (X) << "'" << endl;}

const double pi=acos(-1.0);

int main()
{
	while(1)
	{
		int a, b;
		int n = scanf("Out[%d]= %d\n",&a,&b);
		if(n != 2)break;
		printf("Case #%d: %03d\n",a,b);
	}
	return 0;
}


/*


cat in.txt | tr -d '\r' | sed "s/^/Mod[Floor[(3 + Sqrt[5])\^/" | sed "s/$/], 1000 ]/" > in2.txt

math < in2.txt | grep Out | b.exe

*/

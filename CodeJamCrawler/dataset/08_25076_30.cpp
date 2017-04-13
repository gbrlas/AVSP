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
	int N;cin >> N;
	cin.ignore(100,'\n');
	
	for(int cs=1;cs<=N;cs++)
	{
		int n; cin >> n;
		VI v1(n);
		VI v2(n);
		
		REP(i,n)cin >> v1[i];
		REP(i,n)cin >> v2[i];
		
		SORT(v1);
		SORT(v2);
		
		long long s1 = 0;
		REP(i,n)
		{
			s1 += v1[i] * v2[n-i-1];
		}
		cout << "Case #" << cs << ": " << (s1) << endl;
	}
	return 0;
}

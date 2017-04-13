//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> pii;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define fi first
#define se second

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int T, n, p, q;
double a[1010], b[1010];
set<double> s;

int main(){
    scanf("%d", &T);

    for(int t = 1; t <= T; ++t){
	p = q = 0;
	scanf("%d", &n);
	printf("Case #%d: ", t);

	rep(i, n) scanf("%lf", &a[i]);
	rep(i, n){
	    scanf("%lf", &b[i]);
	    s.insert(b[i]);
	}

	sort(a, a + n);
	sort(b, b + n);

	/*
	puts("");
	rep(i, n) printf("%lf ", a[i]);

	puts("");
	rep(i, n) printf("%lf ", b[i]);
	puts("");
	*/

	rep(i, n){
	    if(a[i] > *s.begin()){
		++p;
		s.erase(s.begin());
	    }else{
		set<double>::iterator it = s.end();
		--it;
		s.erase(it);
	    }
	}

	rep(i, n) s.insert(b[i]);
	
	rep(i, n){
	    set<double>::iterator it = s.lower_bound(a[i]);
	    if(it == s.end()){
		++q;
		s.erase(s.begin());
	    }else{
		s.erase(it++);
	    }
	}

	printf("%d %d\n", p, q);
    }

    return 0;
}

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

int TC;
int n;
ll p, q, r, s, sum;
ll a[1000010];
ll ls[1000010];
ll rs[1000010];

bool ok(ll x){
    int a = upper_bound(ls, ls + n + 1, x) - ls;
    int b = upper_bound(rs, rs + n + 1, x) - rs;
    
    if(a != 0) --a;
    if(b != 0) --b;
    if(a + b >= n) return true;
    return sum - ls[a] - rs[b] <= x;
}

int main(){
    cin >> TC;

    for(int num = 1; num <= TC; ++num){
	cout << "Case #" << num << ": ";
	cin >> n >> p >> q >> r >> s;
	sum = 0;

	rep(i, n){
	    a[i] = (i * p + q) % r + s;
	    sum += a[i];
	    ls[i+1] = ls[i] + a[i];
	}

	for(int i = n - 1; i >= 0; --i) rs[n - i] = rs[n - i - 1] + a[i];

	
	ll lb = 0, ub = sum;
	while(ub - lb > 1){
	    ll mid = (ub + lb) / 2;
	    if(ok(mid)) ub = mid;
	    else lb = mid;
	}

	printf("%.10lf\n", (double)(sum - ub) / sum);
    }

    return 0;
}

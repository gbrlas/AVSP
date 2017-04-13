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

int n;
int TC;
ll ret;
int a[1010];
vector<int> v;
vector<int> vec[1010];

struct BIT{
    vector<int> bit;

    void init(){
	bit.resize(n + 1);

	for(int i = 1; i <= n; ++i)
	    bit[i] = i & -i;
	
    }

    void add(int pos, int x){
	while(pos <= n){
	    bit[pos] += x;
	    pos += pos & -pos;
	}
    }

    int sum(int pos){
	int s = 0;

	while(pos){
	    s += bit[pos];
	    pos -= pos & -pos;
	}
	return s;
    }
}T;

int main(){
    scanf("%d", &TC);

    for(int num = 1; num <= TC; ++num){
	v.clear();
	ret = 0;
	printf("Case #%d: ", num);
	scanf("%d", &n);
	v.resize(n);
	T.init();

	rep(i, n) vec[i].clear();

	rep(i, n){
	    scanf("%d", &a[i]);
	    v[i] = a[i];
	}
	sort(v.begin(), v.end());

	rep(i, n) vec[lower_bound(v.begin(), v.end(), a[i]) - v.begin()].pb(i + 1);

	rep(i, v.size()){
	    rep(j, vec[i].size()) T.add(vec[i][j], -1);

	    int z = T.sum(n);

	    rep(j, vec[i].size()){
		int x = T.sum(vec[i][j]);
		ret += min(x, z - x);
	    }
	}
	printf("%lld\n", ret);
    }

    return 0;
}

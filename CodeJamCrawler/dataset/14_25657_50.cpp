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

const ll MOD = 1000000007LL;
int TC;
int n, m;
int ma;
int ret;
int ru, now;
int as[1010];
string s[1010];
vector<int> v[8];

struct Trie{
    Trie *next[26];
    Trie() { fill(next, next + 26, (Trie*)0); }
};

Trie *find(string t, Trie *r) {
    rep(i, t.size()){
	int c = t[i] - 'A';
	if (!r->next[c]){
	    ++now;
	    r->next[c] = new Trie;
	}
	r = r->next[c];
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> TC;

    for(int num = 1; num <= TC; ++num){
	cout << "Case #" << num << ": ";
	ma = ret = 0; ru = 1;
	cin >> m >> n;
	rep(i, m) cin >> s[i];
	rep(i, m) ru *= n;

	rep(i, ru){
	    int bi = i;
	    rep(j, n) v[j].clear();

	    rep(j, m){
		as[j] = bi % n;
		v[as[j]].pb(j);
		bi /= n;
	    }

	    bool f = false;
	    rep(j, n){
		if(v[j].empty()){
		    f = true;
		    break;
		}
	    }
	    if(f) continue;

	    now = 0;
	    rep(j, n){
		Trie *r = new Trie;
		rep(k, v[j].size()){
		    find(s[v[j][k]], r);
		}
	    }
	    if(now > ma){
		ma = now;
		ret = 1;
	    }else if(ma == now) ++ret;
	}
	cout << ma + n << " " << ret << "\n";
    }

    return 0;
}

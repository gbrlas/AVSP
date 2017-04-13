#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int,int> point;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//for debug
template<class T> ostream &operator<<(ostream &os, vector<T> v){if(v.empty()){ os << "[]"; return os;} os << "["; for(int i = 0; i < v.size() - 1; i++) os << v[i] << ", "; os << v[v.size() - 1] << "]"; return os; }
template<class T> ostream &operator<<(ostream &os, list<T> l){if(l.empty()){os << "[]"; return os;} os << "["; while(l.size() != 1){ os << l.front() << ", "; l.pop_front(); } os << l.front(); os << "]"; return os; }
template<class T> ostream &operator<<(ostream &os, set<T> s){if(s.empty()){ os << "[]"; return os;} os << "["; while(s.size() != 1){ T o = *s.begin();os << o << ", "; s.erase(o); } os << *s.begin(); os << "]"; return os; }



int earn[1000];
int next[1000];

ll solve(int r, int k, vector<int>g){
	int n = g.size();
	for(int i = 0; i < n; i++){
		int p = i;
		int num = 0;
		for(int j = n; j--;){
			if(num + g[p] <= k){
				num += g[p];
				p = (p + 1) % n;
			}

		}
		earn[i] = num;
		next[i] = p;
	}
	int pos = 0;
	ll ans = 0;
	for(int i = 0; i < r; i++){
		//cout << pos << endl;
		ans += earn[pos];
		pos = next[pos];
	}

	return ans;
}

int main(){
	int cases;
	ifstream in;

	//string ifile = "C-test.in";
	string ifile = "C-small-attempt0.in";
	//string ifile = "C-large.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	in >> cases;
	for(int c = 0; c < cases; c++){
		int r, k, n;
		in >> r >> k >> n;
		vector<int> g(n);
		for(int i = 0; i < n; i++)
			in >> g[i];

		memset(earn,0,sizeof(earn));
		memset(next,0,sizeof(next));
		ll ans = solve(r,k,g);
		cout << "Case #" << (c + 1) << ": " << ans << endl;
		fout << "Case #" << (c + 1) << ": " << ans << endl;
	}

}

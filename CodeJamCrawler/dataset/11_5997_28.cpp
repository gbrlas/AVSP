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

#define EPS 1e-9

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

double fact(ll x){
	if(x == 1)
		return 1;
	if(x == 0)
		return 0;
	else
		return x * (x - 1);
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
		int N, L, H;
		in >> N >> L >> H;
		vector<int> array(N);
		for(int i = 0; i < N; i++){
			in >> array[i];
		}
		int ans = 0;
		for(int t = L; t <= H; t++){
			bool flag = true;
			for(int i = 0; i < N; i++){
				if(array[i] % t == 0 || t % array[i] == 0)
					continue;
				flag = false;
				break;
			}
			if(flag){
				ans = t;
				break;
			}
		}

		if(ans){
			cout << "Case #" << (c + 1) << ": " << ans << endl;
			fout << "Case #" << (c + 1) << ": " << ans << endl;
		} else{
			cout << "Case #" << (c + 1) << ": " << "NO" << endl;
			fout << "Case #" << (c + 1) << ": " << "NO" << endl;
		}
	}

}

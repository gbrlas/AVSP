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


int solve(vector<string> E, vector<string> C){
	int ans = 0;
	set<string> S;
	for(int i = 0; i < E.size();i++){
		for(int j = 1; j < E[i].length();j++){
			if(E[i][j] == '/'){
				S.insert(E[i].substr(0,j));
			}
		}
		S.insert(E[i]);
	}
	int before = S.size();
	for(int i = 0; i < C.size();i++){
		for(int j = 1; j < C[i].length();j++){
			if(C[i][j] == '/'){
				S.insert(C[i].substr(0,j));
			}
		}
		S.insert(C[i]);
	}

	return S.size() - before;
}

int main(){
	int cases;
	ifstream in;

	//string ifile = "A-test.in";
	//string ifile = "A-small-attempt0.in";
	string ifile = "A-large.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	string line;
	getline(in,line);
	cases = toInt(line);
	for(int c = 0; c < cases; c++){
		getline(in,line);
		istringstream ss(line);
		int n, m;
		ss >> n >> m;
		vector<string> E(n);
		vector<string> C(m);
		for(int i = 0; i < n; i++){
			getline(in,line);
			E[i] = line;
		}
		for(int i = 0; i < m; i++){
			getline(in,line);
			C[i] = line;
		}
		sort(E.begin(),E.end());
		sort(C.begin(),C.end());

		int ans = solve(E,C);

		cout << "Case #" << (c + 1) << ": " << ans << endl;
		fout << "Case #" << (c + 1) << ": " << ans << endl;
	}

}

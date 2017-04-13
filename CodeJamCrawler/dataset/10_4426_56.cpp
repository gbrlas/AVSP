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


string solve(int K, int B, int T, vector<int> x, vector<int> v){
	int ans = 0;
	int n = x.size();
	//何匹追い越さないとだめか
	vector<int> pass;
	for(int i = 0; i < n;i++){
		if(B - x[i] > v[i] * T)
			continue;
		int p = 0;
		for(int j = i+1;j < n; j++){
			if(v[i] > v[j] && (x[j] - x[i]) < (v[i] - v[j]) * T){
				if(B - x[j] > v[j] * T)
					p++;
			}

		}
		pass.push_back(p);
	}
	if(pass.size() < K)
		return "IMPOSSIBLE";
	sort(pass.begin(),pass.end());
	for(int i = 0; i < K; i++){
		ans += pass[i];
	}
	return toString(ans);
}

int main(){
	int cases;
	ifstream in;

	//string ifile = "B-test.in";
	//string ifile = "B-small-attempt0.in";
	//string ifile = "B-small-attempt1.in";
	//string ifile = "B-small-attempt2.in";
	string ifile = "B-small-attempt3.in";
	//string ifile = "B-large.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	in >> cases;
	for(int c = 0; c < cases; c++){
		int N,K,B,T;
		in >> N >> K >> B >> T;
		vector<int> x(N);
		vector<int> v(N);
		for(int i = 0; i < N; i++)
			in >> x[i];
		for(int i = 0; i < N; i++)
			in >> v[i];

		string ans = solve(K,B,T,x,v);
		cout << "Case #" << (c + 1) << ": " << ans << endl;
		fout << "Case #" << (c + 1) << ": " << ans << endl;
	}

}

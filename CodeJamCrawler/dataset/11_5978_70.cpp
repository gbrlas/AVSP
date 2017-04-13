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
		int N;
		in >> N;
		vector<int> C(N);
		for(int i = 0; i < N; i++)
			in >> C[i];

		sort(C.begin(),C.end());
		int val = 0;

		for(int j = 1; j < N; j++){
			int sum1 = 0, oddsum1 = 0;
			int sum2 = 0, oddsum2 = 0;
			for(int k = 0; k < j; k++){
				sum1 += C[k];
				oddsum1 ^= C[k];
			}
			for(int k = j; k < N; k++){
				sum2 += C[k];
				oddsum2 ^= C[k];
			}
			if(oddsum1 == oddsum2){
				val = max(val,max(sum1,sum2));
			}
		}
		string ans = (val != 0) ? toString(val) : "NO";
		cout << "Case #" << (c + 1) << ": " << ans << endl;
		fout << "Case #" << (c + 1) << ": " << ans << endl;
	}

}

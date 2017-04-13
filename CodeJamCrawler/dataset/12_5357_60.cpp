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

	//string ifile = "B-test.in";
	//string ifile = "B-small-attempt0.in";
	string ifile = "B-large.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	in >> cases;
	for(int c = 0; c < cases; c++){
		int result = 0;
		int N, S, P;
		in >> N >> S >> P;
		vector<int> scores(N);
		for(int i = 0; i < N; i++){
			in >> scores[i];
		}
		for(int i = 0; i < N; i++){
			int k = scores[i] / 3;
			int m = scores[i] % 3;
			switch(m){
			case 0:
				if(k >= P){
					result++;
				}else if (k + 1 == P && S > 0 && k > 0){
					S--;
					result++;
				}
				break;
			case 1:
				if(k + 1 >= P){
					result++;
				}
				break;
			case 2:
				if(k + 1 >= P){
					result++;
				}else if(k + 2 == P && S > 0){
					S--;
					result++;
				}
			break;
			}
		}
		cout << "Case #" << (c + 1) << ": " << result << endl;
		fout << "Case #" << (c + 1) << ": " << result << endl;
	}

}

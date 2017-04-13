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

	//string ifile = "A-test.in";
	//string ifile = "A-small-attempt0.in";
	string ifile = "A-large.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	in >> cases;

	for(int c = 0; c < cases; c++){
		int n, m;
		in >> n >> m;
		vector<string> tile(n);
		for(int i = 0; i < n; i++){
			in >> tile[i];
		}

		string ans = "Impossible";
		for(int i = 0; i < n-1; i++){
			for(int j = 0; j < m-1; j++){
				if(tile[i][j] == '#' && tile[i+1][j] == '#' && tile[i+1][j] == '#' && tile[i+1][j+1] == '#'){
					tile[i][j] = '/';
					tile[i+1][j] = '\\';
					tile[i][j+1] = '\\';
					tile[i+1][j+1] = '/';
				}
			}
		}
		bool flag = true;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				if(tile[i][j] == '#')
					flag = false;
			}

		cout << "Case #" << (c + 1) << ": " << endl;
		if(flag){
			for(int i = 0; i < n; i++)
				cout << tile[i] << endl;
		}else{
			cout << "Impossible" << endl;
		}

		fout << "Case #" << (c + 1) << ": " << endl;
		if(flag){
			for(int i = 0; i < n; i++)
				fout << tile[i] << endl;
		}else{
			fout << "Impossible" << endl;
		}

	}

}

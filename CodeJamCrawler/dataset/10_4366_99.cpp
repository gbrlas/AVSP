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




bool solve(int n, int k){
	unsigned int bits[30] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912};
	/*
	unsigned int state = 0;
	for(int i = 0; i < k; i++){
		int p;
		for(p = 0;(state & bits[p]) && p < 30;){
			p++;
		}
		unsigned int x = (1 << (p + 1)) - 1;
		state = state ^ x;
		//for(int i = 0;i < n; i++){
			//cout << ((state & bits[i]) ? 1 : 0);
		//}
		//cout << endl;
	}
	int p;
	for(p = 0;state & bits[p];){
		p++;
	}
	return (p == n);
	*/
	int x = k % (1 << n);
	int p;
	for(p = 0;x & bits[p];p++)
		;
	return (p == n);
}

int main(){
	int cases;
	ifstream in;

	//string ifile = "A-small-test.in";
	string ifile = "A-small-attempt5.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	in >> cases;
	for(int c = 0; c < cases; c++){
		int n, k;
		in >> n >> k;
		bool ans = solve(n,k);
		cout << "Case #" << (c + 1) << ": " << (ans ? "ON" : "OFF") << endl;
		fout << "Case #" << (c + 1) << ": " << (ans ? "ON" : "OFF") << endl;
	}

}

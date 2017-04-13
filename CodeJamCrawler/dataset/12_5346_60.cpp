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

	//string ifile = "A-test.in";
	string ifile = "A-small-attempt1.in";
	//string ifile = "A-large.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	string coded = "";
	coded += "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	coded += "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	coded += "de kr kd eoya kw aej tysr re ujdr lkgc jv";

	string plain = "";
	plain += "our language is impossible to understand";
	plain += "there are twenty six factorial possibilities";
	plain += "so it is okay if you want to just give up";

	map<char,char> dec;

	for(unsigned int i = 0; i < plain.length(); i++){
		dec[coded[i]] = plain[i];
	}

	dec['q'] = 'z';
	dec['z'] = 'q';

	/*
	for(char c = 'a'; c <= 'z'; c++){
		cout << c << " : " << dec[c] << endl;
	}
	*/

	in >> cases;
	string line;
	getline(in,line);
	for(int c = 0; c < cases; c++){
		string result = "";
		getline(in,line);
		for(unsigned int j = 0; j < line.length(); j ++){
			result += dec[line[j]];
		}
		cout << "Case #" << (c + 1) << ": " << result << endl;
		fout << "Case #" << (c + 1) << ": " << result << endl;
	}

}

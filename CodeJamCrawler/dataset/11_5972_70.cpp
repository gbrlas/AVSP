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
		int C, D, N;
		in >> C;
		vector<string> trans(C);
		for(int i = 0; i < C; i++)
			in >> trans[i];

		in >> D;
		vector<string> vanish(D);
		for(int i = 0; i < D; i++)
			in >> vanish[i];

		in >> N;
		string spell;
		in >> spell;

		vector<char> result;
		for(int i = 0; i < N; i++){
			bool flag = false;
			bool flag2 = false;
			char last_char = result.empty()? ' ' : result.back();
			for(int j = 0; j < C; j++){
				if((last_char == trans[j][0] && spell[i] == trans[j][1]) || (last_char == trans[j][1] && spell[i] == trans[j][0])){
					result.pop_back();
					result.push_back(trans[j][2]);
					flag = true;
					break;
				}
			}
			if(flag)
				continue;

			for(int k = 0; k < D; k++){
				char target;
				if(vanish[k][0] == spell[i])
					target = vanish[k][1];
				else if(vanish[k][1] == spell[i])
					target = vanish[k][0];
				else
					continue;
				//要素を探す為
				vector<char> cp(result.size());
				copy(result.begin(),result.end(),cp.begin());
				sort(cp.begin(),cp.end());
				if(binary_search(cp.begin(),cp.end(),target)){
					result.clear();
					flag2 = true;
					break;
				}
			}
			if(!flag2)
				result.push_back(spell[i]);
		}

		cout << "Case #" << (c + 1) << ": " << result << endl;
		fout << "Case #" << (c + 1) << ": " << result << endl;
	}

}

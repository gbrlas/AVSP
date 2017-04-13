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


int solve(int D, int I, int M, vector<int> pixcels){
	int ans = 0;
	cout << pixcels << endl;
	return ans;
}

int main(){
	int cases;
	ifstream in;

	//string ifile = "A-test.in";
	string ifile = "A-small-attempt0.in";
	//string ifile = "A-large.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	in >> cases;
	for(int c = 0; c < cases; c++){
		int n;
		in >> n;

		vector<char> r(n);
		vector<int> p(n);

		for(int i = 0; i < n; i++)
			in >> r[i] >> p[i];

		queue<int> o_list, b_list;

		for(int i = 0; i < n; i++){
			if(r[i] == 'O')
				o_list.push(p[i]);
			else
				b_list.push(p[i]);
		}


		int time = 0;
		int ox = 1, bx = 1;

		for(int i = 0; i < n; i++){
			int passed = 0;

			int o_dist = o_list.empty() ? 0 : o_list.front() - ox;
			int b_dist = b_list.empty() ? 0 : b_list.front() - bx;

			if(r[i] == 'O'){
				passed += abs(o_dist) + 1;
				ox = o_list.front();
				o_list.pop();
				int b_move = min(passed, abs(b_dist));
				if(b_dist > 0)
					bx += b_move;
				else
					bx -= b_move;
			}else{
				passed += abs(b_dist) + 1;
				bx = b_list.front();
				b_list.pop();
				int o_move = min(passed, abs(o_dist));
				if(o_dist > 0)
					ox += o_move;
				else
					ox -= o_move;
			}
			time += passed;
		}

		cout << "Case #" << (c + 1) << ": " << time << endl;
		fout << "Case #" << (c + 1) << ": " << time << endl;
	}

}

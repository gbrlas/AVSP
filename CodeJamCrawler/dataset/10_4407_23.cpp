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


string solve(vector<string> stage,int K){
	bool red,blue;
	red = blue = false;
	int N = stage.size();
	for(int i = 0; i < N; i++){
		for(int loop = 0; loop < N; loop++){
			for(int j = N-1; j > 0; j--)
				if(stage[i][j] == '.')
					swap(stage[i][j],stage[i][j-1]);
		}
		//cout << stage[i] << endl;
	}
	string bs(K,'B');
	string rs(K,'R');
	//横のラインをチェック
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= N - K;j++){
			string cand = stage[i].substr(j,K);
			if(cand == bs) blue = true;
			if(cand == rs) red = true;
		}
	}
	//縦のラインをチェック
	for(int j = 0; j < N; j++){
		string cand = "";
		for(int i = 0; i < N; i++){
			cand += stage[i][j];
		}
		for(int i = 0; i <= N-K;i++){
			string cand2 = cand.substr(i,K);
			if(cand2 == bs) blue = true;
			if(cand2 == rs) red = true;
		}
	}
	//右上がりのラインをチェック
	for(int i = 0; i < 2 * N -1; i++){
		string cand = "";
		for(int y = i, x = 0; y >= 0 && x >= 0; y--,x++){
			if(y < N && x < N)
				cand += stage[y][x];
		}
		if(cand.length() < K)
			continue;
		for(int t = 0; t <= cand.length()-K;t++){
			string cand2 = cand.substr(t,K);
			if(cand2 == bs) blue = true;
			if(cand2 == rs) red = true;
		}
	}

	//右下がりのラインをチェック
	for(int i = -N+1; i < N; i++){
		string cand = "";
		for(int y = i, x = 0; y < N && x < N; y++,x++){
			if(y >= 0 && y < N && x < N)
				cand += stage[y][x];
		}
		if(cand.length() < K)
			continue;
		for(int t = 0; t <= cand.length()-K;t++){
			string cand2 = cand.substr(t,K);
			if(cand2 == bs) blue = true;
			if(cand2 == rs) red = true;
		}
	}

	if(red && blue)
		return "Both";
	else if(red)
		return "Red";
	else if(blue)
		return "Blue";
	else
		return "Neither";
}

int main(){
	int cases;
	ifstream in;

	//string ifile = "A-test.in";
	string ifile = "A-small-attempt0.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	in >> cases;
	for(int c = 0; c < cases; c++){
		int N,K;
		in >> N >> K;
		vector<string> stage(N);
		for(int i = 0; i < N; i++)
			in >> stage[i];

		string ans = solve(stage,K);
		cout << "Case #" << (c + 1) << ": " << ans << endl;
		fout << "Case #" << (c + 1) << ": " << ans << endl;
	}

}

/*
 * Main.cpp
 *
 *  Created on: 2011/05/07
 *      Author: yakumo
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
const double EPS = 1e-10;
#define SORT(c) sort((c).begin(),(c).end())

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

bool isClear(vector<char> ans, bool cl[26][26]){
	REP(i,ans.size()-1)
		if(cl[ ans[ans.size()-1] - 'A' ][ans[i] - 'A'])
			return true;
	return false;
}

void makeClear(int a,int b,bool cl[26][26]){
	cl[a][b] = true;
	cl[b][a] = true;
}

void makeComb(int a,int b,char c,char comb[26][26]){
	comb[a][b] = c;
	comb[b][a] = c;
}

int main(){
	ofstream ofs("out.txt");
	ifstream ifs("B-large.in");

	string str;
	ifs >> str;
	int t = toInt(str);

	char comb[26][26];
	bool cl[26][26];


	REP(k,t){
		REP(i,26){
			REP(j,26){
				comb[i][j] = 0;
				cl[i][j] = false;
			}
		}

		ifs >> str;
		int c = toInt(str);
		REP(i,c){
			ifs >> str;
			makeComb(str[0]-'A',str[1]-'A',str[2],comb);
		}

		ifs >> str;
		int d = toInt(str);
		REP(i,d){
			ifs >> str;
			makeClear(str[0]-'A',str[1]-'A',cl);
		}
		string invoke;
		ifs >> invoke;
		ifs >> invoke;

		vector<char> ans;

		FOR(i,0,invoke.length()){
			if(ans.size() == 0){
				ans.push_back(invoke[i]);
				continue;
			}
			char change = comb[ans[ans.size()-1]-'A'][invoke[i]-'A'];
			if(change != 0)
				ans[ans.size()-1] = change;
			else
				ans.push_back(invoke[i]);

			if(1 < ans.size())
				if(isClear(ans,cl))
					ans.clear();
		}

		ofs << "Case #" << (k+1) << ": [";
		if(!ans.empty()){
			REP(i,ans.size()-1){
				ofs << ans[i] << ", ";
			}
			if(ans.size() != 0)
				ofs << ans[ans.size()-1];
		}
		ofs << "]" << endl;

	}
	ofs.close();

	return 0;
}

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

void draw(int x,int y,vector<vector<char> > &mp){
	int w = x+1;
	int h = y+1;

	if(mp.size() <= w)
		return;
	if(mp[x].size() <= h)
		return;
	if(mp[x][y] != '#')
		return;
	if(mp[x][h] != '#')
		return;
	if(mp[w][y] != '#')
		return;
	if(mp[w][h] != '#')
		return;

	mp[x][y] = '/';
	mp[x][h] = '\\';
	mp[w][y] = '\\';
	mp[w][h] = '/';
}

int main(){
	ofstream ofs("out.txt");
	ifstream ifs("A-large.in");

	string str;
	ifs >> str;
	int t = toInt(str);

	REP(k,t){
		ifs >> str;
		int r = toInt(str);
		ifs >> str;
		int c = toInt(str);

		vector<vector<char> > mp;
		REP(i,r){
			ifs >> str;
			vector<char> line;
			REP(j,c)
				line.push_back(str[j]);
			mp.push_back(line);
		}

		REP(i,r)
			REP(j,c)
				if(mp[i][j] == '#')
					draw(i,j,mp);

		bool flag = true;
		REP(i,r)
			REP(j,c)
				if(mp[i][j] == '#')
					flag = false;

		if(flag){
			printf("Case #%d:\n",(k+1));
			REP(i,r){
				REP(j,c){
					char x = mp[i][j];
					cout << x;
				}
				cout << endl;
			}
		}else{
			printf("Case #%d:\nImpossible\n",(k+1));
		}
	}
	ofs.close();

	return 0;
}

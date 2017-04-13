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
	ifstream ifs("A-large.in");

	string str;
	ifs >> str;
	int t = toInt(str);

	REP(k,t){
		ifs >> str;
		int n = toInt(str);

		vector<vector<int> > sh;
		REP(i,n){
			vector<int> s(n);
			sh.push_back(s);
		}

		REP(i,n){
			ifs >> str;
			REP(j,n){
				if(str[j] == '.')
					sh[i][j] = -1;
				else if(str[j] == '1')
					sh[i][j] = 1;
				else
					sh[i][j] = 0;
			}
		}


		VVI wp;
		REP(i,n){
			int win=0;
			int bat=0;
			REP(j,n){
				if(sh[i][j] == 0){
					bat++;
				}else if(sh[i][j] == 1){
					bat++;
					win++;
				}
			}

			VI temp;
			temp.push_back(win);
			temp.push_back(bat);
			wp.push_back(temp);
		}

		vector<double> owp;
		REP(i,n){
			double x = 0.0;
			int count = 0;
			REP(j,n){
				if(sh[i][j] != -1){
					count++;
					if(sh[i][j] == 1){
						x += (double)(wp[j][0]) / (double)(wp[j][1] -1);
					}else{
						x += (double)(wp[j][0]-1) / (double)(wp[j][1] -1);
					}
				}
			}
			x /= (double)count;
			owp.push_back(x);
		}

		vector<double> oowp;
		REP(i,n){
			double x = 0.0;
			int count = 0;
			REP(j,n){
				if(sh[i][j] != -1){
					count++;
					x += owp[j];
				}
			}
			x /= (double)count;
			oowp.push_back(x);
		}

		ofs << "Case #" << (k+1) << ":" << endl;

		REP(i,n){
			double rpi = 0.25 * ((double)wp[i][0] / (double)wp[i][1])
					+ 0.50 * owp[i] + 0.25 * oowp[i];

			ofs << rpi << endl;
		}

	}
	ofs.close();

	return 0;
}

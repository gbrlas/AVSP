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

class Point{
public:
	double x;
	bool f;
	Point(int p){
		x = p;
		f = false;
	}
};

bool check(vector<Point> p, int d){
	REP(i,p.size()-1)
		if(p[i+1].x < p[i].x + d)
			return false;

	return true;
}
int main(){
	ofstream ofs("out.txt");
	ifstream ifs("B-small-attempt0.in");

	string str;
	ifs >> str;
	int t = toInt(str);

	REP(k,t){
		ifs >> str;
		int c = toInt(str);

		ifs >> str;
		int d = toInt(str);

		vector<Point> points;
		REP(i,c){
			ifs >> str;
			int p = toInt(str);

			ifs >> str;
			int v = toInt(str);

			REP(j,v){
				points.push_back(Point(p));
			}
		}

		points.push_back(Point(points[points.size()-1].x + d+d));

		double time = 0.0;

		while(!check(points,d)){
			time += 0.5;

			REP(i,points.size())
				points[i].f = false;

			points[0].f = true;
			points[0].x -= 0.5;
			FOR(i,1,points.size()-1){
				if(points[i].f)continue;
				if(points[i-1].x + (double)d +0.5 <= points[i].x){
					points[i].x -= 0.5;
					points[i].f = true;
				}else{
					if(points[i].x + (double)d + 0.5 <= points[i+1].x){
						points[i].x += 0.5;
						points[i].f = true;
						if(!points[i-1].f){
							i-=2;
						}
					}
				}
			}
			points[points.size()-1].x += 0.5;
		}
		//ofs << "Case #" << (k+1) << ": ";
		//ofs << (double)(time*1.0) << endl;
		printf("Case #%d: %f\n",(k+1),time);
	}
	ofs.close();

	return 0;
}

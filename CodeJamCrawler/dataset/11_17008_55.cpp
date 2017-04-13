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

class Pair{
public:
	char name;
	int button;
	Pair(char n,int b){
		name = n;
		button = b;
	}
};

class robot{
public:
	int now;
	int next;
	int point;
	robot(int n,int nex,int p){
		now = n;
		next = nex;
		point = p;
	}
};

void moveRobot(robot* r,int temp){
	if(abs(r->now-r->next) <= temp)
		r->now = r->next;
	else if(r->now < r->next)
		r->now += temp;
	else
		r->now -= temp;
}

void move(robot* b,robot* o,int temp){
	moveRobot(b,temp);
	moveRobot(o,temp);
}

int main(){
	ofstream ofs("out.txt");
	ifstream ifs("A-large.in");

	string str;
	//cin >> str;
	ifs >> str;
	int t = toInt(str);

	REP(k,t){
		vector<Pair> route;
		VI orange;
		VI blue;

		//cin >> str;
		ifs >> str;
		int n = toInt(str);

		REP(i,n){
			char name;
			ifs >> name;
			ifs >> str;
			//cin >> name;
			//cin >> str;
			int button = toInt(str);
			route.push_back(Pair(name,button));

			if(name == 'B')
				blue.push_back(button);
			else
				orange.push_back(button);
		}

		if(!blue.empty()){
			blue.push_back(blue[blue.size()-1]);
		}else{
			blue.push_back(1);
			blue.push_back(1);
		}

		if(!orange.empty()){
			orange.push_back(orange[orange.size()-1]);
		}else{
			orange.push_back(1);
			orange.push_back(1);
		}

		int time = 0;

		robot b = robot(1,blue[0],1);
		robot o = robot(1,orange[0],1);

		REP(i,route.size()){
			Pair p = route[i];
			int temp = 0;
			if(p.name == 'B'){
				temp = abs(b.now-b.next)+1;
				move(&b,&o,temp);
				b.next = blue[b.point++];
			}else{
				temp = abs(o.now-o.next)+1;
				move(&b,&o,temp);
				o.next = orange[o.point++];
			}
			time += temp;
		}

		ofs << "Case #" << (k+1) << ": " << time << endl;
	}
	ofs.close();

	return 0;
}

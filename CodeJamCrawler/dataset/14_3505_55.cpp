/*
 * CookieClicker.h
 *
 *  Created on: Apr 12, 2014
 *      Author: dev
 */

#ifndef COOKIECLICKER_H_
#define COOKIECLICKER_H_

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <ctime>
#include <string>
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

using namespace std;

#define FOR(i,s,e) for(int i=int(s); i<int(e); i++)
#define EACH(it,c) for(__typeof__((c).begin()) it=(c).begin(); (it)!=(c).end(); (it)++)
#define CONTAINS(x,c) (find((c).begin(),(c).end(),(x))!=(c).end())
#define ZC(x) memset((x),0,sizeof((x)))
#define P(x) cout << (x) << endl

inline string toString(double x) {
    ostringstream so;
    so.setf(ios_base::fixed, ios_base::floatfield);
    so.precision(7);
    so << x;
    return so.str();
}

struct Case {
	double C;
	double F;
	double X;
};

class CookieClicker {

public:
	Case readCase( ifstream& ifs ) {
		string line;
		Case c;
		if (getline(ifs, line)) { 
			istringstream si(line);
			si >> c.C >> c.F >> c.X;
		}
		return c;
	}
	
	string solve( Case c ) {
		if (c.X <= 2.0) return toString(c.X / 2.0);
		
//		int maxFirm = (int)ceil((c.X - 2.0)/c.F);
		int maxFirm = 2000;
		vector<double> times;
		
		for(int firm = 0; firm <= maxFirm; firm++) {
			double time = 0.0;
			
			for(int i = 0; i <= firm; i++) {
				if (i!=firm) time+=c.C/(2.0+i*c.F);
				if (i==firm) time+=c.X/(2.0+i*c.F);
			}
			times.push_back(time);
			if (times.size()>1 && *(times.end()-1)<time) break;
		}
		return toString(*min_element(times.begin(), times.end()));
	}
};

#endif /* COOKIECLICKER_H_ */

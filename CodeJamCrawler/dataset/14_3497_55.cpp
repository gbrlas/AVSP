/*
 * MagickTrick.h
 *
 *  Created on: Apr 12, 2014
 *      Author: dev
 */

#ifndef MAGICKTRICK_H_
#define MAGICKTRICK_H_

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
template<class T>
inline string toString(T x) {
    ostringstream so;
    so << x;
    return so.str();
}

struct Case {
	int firstAns;
	int secondAns;
	vector<vector<int> > firstCards;
	vector<vector<int> > secondCards;
};


class MagickTrick {
public:
	Case readCase( ifstream& ifs ) {
		string line;
		Case c;
		if (getline(ifs, line)) { 
			istringstream si(line);
			si >> c.firstAns;
		}
		for (int i = 0; i < 4; i++) {
			if (getline(ifs, line)) {
				vector<int> row(4);
				istringstream si(line);
				si >> row[0] >> row[1] >> row[2] >> row[3];
				c.firstCards.push_back(row);
			}
		}
		if (getline(ifs, line)) { 
			istringstream si(line);
			si >> c.secondAns;
		}
		for (int i = 0; i < 4; i++) {
			if (getline(ifs, line)) {
				vector<int> row(4);
				istringstream si(line);
				si >> row[0] >> row[1] >> row[2] >> row[3];
				c.secondCards.push_back(row);
			}
		}
		return c;
	}
	
	string solve( Case c ) {
		vector<int> first  = c.firstCards[c.firstAns-1];
		vector<int> second = c.secondCards[c.secondAns-1];
		
		vector<int> cards;
		EACH(s, second) if (CONTAINS(*s, first)) cards.push_back(*s);
		
		if (cards.size()==1) return toString(cards[0]);
		else if (cards.size()>1) return "Bad magician!";
		else return "Volunteer cheated!";
	}
};
#endif /* MAGICKTRICK_H_ */

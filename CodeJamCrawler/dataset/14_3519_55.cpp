/*
 * DeceitfulWar.h
 *
 *  Created on: Apr 13, 2014
 *      Author: dev
 */

#ifndef DECEITFULWAR_H_
#define DECEITFULWAR_H_
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
#include <cfloat>

using namespace std;

#define FOR(i,s,e) for(int i=int(s); i<int(e); i++)
#define EACH(it,c) for(__typeof__((c).begin()) it=(c).begin(); (it)!=(c).end(); (it)++)
#define CONTAINS(x,c) (find((c).begin(),(c).end(),(x))!=(c).end())
#define P(x) cout << (x) << endl
inline double toDouble(const string& s) {
    double v;
    istringstream si(s);
    si >> v;
    return v;
}
inline vector<double> split(const string& s, const string& delim) {
    vector<double> v;
    size_t start = 0, end = 0;
    while ((end = s.find(delim, start)) != string::npos) {
        v.push_back(toDouble(s.substr(start, end - start)));
        start = end + delim.length();
    }
    v.push_back(toDouble(s.substr(start)));
    //EACH(d,v) P(*d);
    return v;
}
 

struct Case {
	int N;
	vector<double> naomi;
	vector<double> ken;
};

class DeceitfulWar {
public:
	Case readCase( ifstream& ifs ) {
		string line;
		Case c;
		if (getline(ifs, line)) { 
			istringstream si(line);
			si >> c.N;
		}
		if (getline(ifs, line)) { 
			c.naomi = split(line, " ");
		}
		if (getline(ifs, line)) { 
			c.ken = split(line, " ");
		}
		return c;
	}
	string solve( Case c ) {
		ostringstream os;
		os << dwar(c.N, c.naomi, c.ken) << " " << war(c.N, c.naomi, c.ken);
		return os.str();
	}
	
	int war( int N, vector<double> naomi, vector<double> ken ) {
		int score=0;
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		
		for (int i=0; i < N; i++) {
			vector<double>::iterator it;
			it = max_element(naomi.begin(), naomi.end());
			double choice_n = *it;
			naomi.erase( it );
			
			it = max_element(ken.begin(), ken.end());
			double choice_k = *it;
			//cout << "choice_n:" << choice_n << " choice_k:" << choice_k << endl;
			if (choice_k < choice_n) {
				it = min_element(ken.begin(), ken.end());
				ken.erase( it );
				score++;
			} else {
				EACH(k,ken) {
					if (choice_n <= *k) { // TODO there's no case of equal?
						it = k;
						break;
					}
				}
				ken.erase( it );
			}
		}
		return score;
	}
	int dwar( int N, vector<double> naomi, vector<double> ken ) {
		int score=0;
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		
		for (int i=0; i < N; i++) {
			vector<double>::iterator it;
			it = min_element(naomi.begin(), naomi.end());
			double choice_n = *it;
			naomi.erase( it );
			
			if (choice_n < *min_element(ken.begin(), ken.end())) {
				it = max_element(ken.begin(), ken.end());
			} else {
				it = min_element(ken.begin(), ken.end());
			}
			double choice_k = *it;
			//cout << "choice_n:" << choice_n << " choice_k:" << choice_k << endl;
			ken.erase( it );
			if (choice_k < choice_n) score++;
		}
		return score;
	}
};

#endif /* DECEITFULWAR_H_ */

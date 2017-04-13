#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i, s, e) for(int i = (s); i < (e); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SQR(x) ((x)*(x))
#define CLR(x) memset(x, 0, sizeof(x))
typedef long long int64;

template<class T>
inline void PrintResult(int caseNum, T res){
	cout <<"Case #" << caseNum << ": " << res << endl;
}

set<pair<int, int> > bacs;

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int caseNum;
	cin >> caseNum;
	
	REP(cs, caseNum){
		bacs.clear();
		int R;
		cin >> R;
		REP(i, R){
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for(int x = x1; x <= x2; ++x) for(int y = y1; y <= y2; ++y) bacs.insert(make_pair(x, y));
		}
		int res = 0;
		while(bacs.size()){
			set<pair<int, int> > tmp;
			set<pair<int, int> >::iterator iter;
			for(iter = bacs.begin(); iter != bacs.end(); ++iter){
				int x = iter->first, y = iter->second;
				bool have = false;
				if(bacs.count(make_pair(x - 1, y))) have = true;
				else if(bacs.count(make_pair(x, y - 1))) have = true;
				if(have) tmp.insert(make_pair(x, y));
				if(bacs.count(make_pair(x + 1, y - 1))) tmp.insert(make_pair(x + 1, y));
			}
			bacs = tmp;
			res++;
		}
		PrintResult(cs + 1, res);
		cerr << cs + 1 << endl;
	}
	return 0;
}
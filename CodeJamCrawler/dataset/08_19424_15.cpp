#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cmath>
#include <deque>
 
using namespace std;
 
#define LET(x,a) typeof(a) x(a)
#define FOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(x,v) FOR(x,(v).begin(),(v).end())
#define sz size()
#define pb push_back
typedef pair<int,int> PII;
#define DBG(x) cout<< #x << " --> "<< x << "\t"
#define DBE(x) cout<< #x << " --> "<< x << "\n" 

int T, n, t;
int main() {
	cin >> T;
	vector<int> v1, v2;
	int k = 1;
	while(T--) {
		cin >> n;
		v1.clear(); v2.clear();
		REP(i, n) {
			cin >> t; v1.pb(t);
		}
		REP(i, n) {
			cin >> t; v2.pb(t);
		}// end of input
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());		
		int ret = 0;
		for(int i = n-1; i>=0; i--) {
			ret += v1[i]*v2[n-i-1];		
		}	
		cout << "Case #" << k << ": " << ret << endl;
		k++;
	}
	
	return 0;
}

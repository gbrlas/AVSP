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

int n, s, q, a[1001];
map<string, int> M;
int main () {
	cin >> n;
	string tmp;
	int K = 0;
	while(n--) {
		K++;
		memset(a, 0, sizeof(a));
		M.clear();
		int cnt = 0;
		cin >> s;
		REP(i, s) {
			getline(cin, tmp);
			if(tmp.sz == 0) getline(cin, tmp);
			M[tmp] = cnt++;
		}
		cin >> q;
		int chk = 0, switches = 0;
		REP(i, q) {
			getline(cin, tmp);
			if(tmp.sz == 0) getline(cin, tmp);
	//		DBG(tmp); DBE(M[tmp]);
			if(a[M[tmp]] == 0) {a[M[tmp]]++; chk++;}
			if(chk == s) {switches++; chk = 1; memset(a, 0, sizeof(a)); a[M[tmp]] = 1;}
		}
		cout << "Case #" << K << ": " << switches << endl;		
	}
	return 0;
}


/*
	a b  
  a b a  
*/

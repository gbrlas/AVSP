#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

char t[1024];

void Solve(){
	int n, m;
	scanf("%d%d\n", &n, &m);
	set <string> S;
	REP (i, n) {
		gets(t);
		string s = t + 1;
		s += "/";
		REP (j, sz(s))
			if (s[j] == '/')
				S.insert(s.substr(0, j));
	}
	int res = 0;
	REP (i, m) {
		gets(t);
		string s = t + 1;
		s += "/";
		REP (j, sz(s))
			if (s[j] == '/') {
				string w = s.substr(0, j);
				if (S.count(w) == 0)
					++res, S.insert(w);
			}
	}
	cout << res << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}

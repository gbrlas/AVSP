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

void Solve(){
	int n, o = 1, b = 1, ro = 0, rb = 0;
	for (cin >> n; n > 0; --n) {
		char c;
		int x;
		cin >> c >> x;
		if (c == 'O') {
			ro += abs(x - o) + 1;
			ro = max(ro, rb + 1);
			o = x;
		}
		if (c == 'B') {
			rb += abs(x - b) + 1;
			rb = max(rb, ro + 1);
			b = x;
		}
	}
	printf("%d\n", max(ro, rb));
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}

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
	map<string, char> F;
	map<char, string> A;
	string s, res;
	int n;
	for (cin >> n; n > 0; --n) {
		cin >> s;
		F[s.substr(0, 2)] = s[2];
		swap(s[0], s[1]);
		F[s.substr(0, 2)] = s[2];
	}
	for (cin >> n; n > 0; --n) {
		cin >> s;
		A[s[0]] += s[1];
		A[s[1]] += s[0];
	}
	cin >> n >> s;
	for (char c : s) {
		if (sz(res)) {
			if (char z = F[string(1, res.back()) + c]) {
				res.back() = z;
				continue;
			}
			for (char z : A[c]) {
				if (res.find(z) != string::npos) {
					res.clear();
					break;
				}
			}
			if (sz(res) == 0) continue;
		}
		res += c;
	}
	cout << '[';
	REP (i, sz(res)) {
		if (i) cout << ", ";
		cout << res[i];
	}
	cout << ']' << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}

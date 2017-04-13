#include <iostream> 
#include <string> 
#include <vector> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <string> 
#include <stack> 
#include <cmath> 
#include <cassert> 
#include <queue> 
#include <deque> 

using namespace std; 

#define mp make_pair 
#define pb push_back 
#define all(a) a.begin(), a.end() 
#define sz(a) int(a.size()) 
#define forn(i,n) for (int i = 0; i < n; i++) 

typedef long long ll; 
typedef long double ld; 
typedef pair<int, int> pii; 

int sti (string s) {
	int ans = 0;
	for (int i = 0; i < sz(s); i++)
		ans = ans * 10 + s[i] - '0';
	return ans;
}

string its (int x) {
	string s = "";
	while (x > 0) {
		s.pb(x % 10 + '0');
		x /= 10;
	}
	reverse(all(s));
	return s;
}

void solve() {
	int te;
	scanf ("%d", &te);
	forn (i, te) {
		int a, b;
		cin >> a >> b;

		set<pair<int, int>> ans;
		for (int j = a; j <= b; j++) {
			string t = its(j), e;

			forn (k, sz(t) - 1) {
				e = t[sz(t) - 1] + t.substr(0, sz(t) - 1);

				int x = sti(e);
				if (x >= a && x <= b && x != j) {
					ans.insert(mp(min(x, j), max(x, j)));
				}
				t = e;
			}				
		}

		cout << "Case #" << i + 1 << ": " << sz(ans) << endl;
	}
} 

int main() { 
#ifndef ONLINE_JUDGE 
       // freopen("input.txt", "r", stdin); 
       // freopen("output.txt", "w", stdout); 
#endif 
        solve(); 
        return 0; 
}
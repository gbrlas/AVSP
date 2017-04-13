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

		int st = 1, t = 1;
		while (a >= st)
			st *= 10, t++;
		st /= 10, t--;

		ll ans = 0;

		vector<int> tmp;
		for (int j = a; j <= b; j++) {
			if (j == st * 10)
				st *= 10, t++;

			tmp.clear();
			int x = j;
			forn (k, t) {
				x = (x % 10) * st + x / 10;
				if (x >= a && x <= b && x != j) {
					tmp.pb(x);
				}
			}

			sort(all(tmp));
			tmp.erase(unique(all(tmp)), tmp.end());
			ans += sz(tmp);
		}

		ans /= 2;

		cout << "Case #" << i + 1 << ": " << ans << endl;
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
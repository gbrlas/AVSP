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

bool valid (int x, int y, int z) {
	if (abs(x - y) > 2 || abs(x - z) > 2 || abs(y - z) > 2)
		return false;
	return true;
}

bool sup (int x, int y, int z) {
	if (abs(x - y) == 2 || abs(x - z) == 2 || abs(y - z) == 2)
		return true;
	return false; 
}

int a[109], b[109], d[109];

void solve() {
	int t;
	scanf ("%d\n", &t);
	forn (i, t) {
		int n, s, p;
		cin >> n >> s >> p;

		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(d, 0, sizeof d);

		forn (j, n) {
			int x;
			cin >> x;

			forn (k, 11)
				forn (l, 11)
					forn (c, 11)
						if (valid(k, l, c) && k + l + c == x) {
							if (sup(k, l, c)) {
								if (max(max(k, l), c) >= p)
									a[j] = 1;
								else
									b[j] = 1;
							} else {
								if (max(max(k, l), c) >= p)
									d[j] = 1;
							}
						}
		}

		int ans = 0;

		for (int j = 0; j < n && s > 0; j++)
			if (a[j] == 1 && d[j] == 0) {
				ans++, s--;
				b[j] = 0;
				a[j] = 0;
				d[j] = 0;
			}


		for (int j = 0; j < n && s > 0; j++)
			if (a[j] == 1) {
				ans++, s--;
				b[j] = 0;
				d[j] = 0;
			}

		for (int j = 0; j < n && s > 0; j++)
			if (b[j] == 1 && d[j] == 0) {
				b[j] = 0;
				s--;
			}

		for (int j = 0; j < n && s > 0; j++)
			if (b[j] == 1) {
				b[j] = 0;
				d[j] = 0;
				s--;
			}

		for (int j = 0; j < n; j++)
			if (d[j] == 1)
				ans++;

		cout << "Case #" << i + 1 << ": " << ans << endl;
		//cout << s << endl;
	}
} 

int main() { 
#ifndef ONLINE_JUDGE 
        //freopen("input.txt", "r", stdin); 
       // freopen("output.txt", "w", stdout); 
#endif 
        solve(); 
        return 0; 
}
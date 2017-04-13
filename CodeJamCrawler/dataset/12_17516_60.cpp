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

char d[26] = {'y', 'h', 'e', 's', 'o',
'c', 'v', 'x', 'd', 'u', 'i',
'g', 'l', 'b', 'k', 'r',
'z', 't', 'n', 'w', 'j',
'p', 'f', 'm', 'a', 'q'};

void solve() {
	int t;
	scanf ("%d\n", &t);
	forn (i, t) {
		string s;
		getline(cin, s);

		forn (j, sz(s))
			if (s[j] != ' ')
				s[j] = d[s[j] - 'a'];
		
		cout << s << endl;
	}
} 

int main() { 
#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
        //freopen("output.txt", "w", stdout); 
#endif 
        solve(); 
        return 0; 
}
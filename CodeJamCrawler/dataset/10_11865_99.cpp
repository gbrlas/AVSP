#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>


using namespace std;


#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define debug(x) cout << '>' << #x << ':' << x << endl;

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)


typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;






int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		
		bool ok = true;
		for (int x = 0; x < n; ++x) {
			if (! (k & (1 << x)) ) {
				ok = false;
				break;
			}
		}
		
		cout << "Case #" << i + 1 << ": ";
		if (ok) cout << "ON" << endl;
		else cout << "OFF" << endl;

	}


    return 0;
}


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
		int64 r, k, n;
		cin >> k >> r >> n;	
		
		vector <int64> g(n);
		
		int64 people;
		for (int j = 0; j < n; ++j) {
			cin >> g[j];
			people += g[j];
		}
		
		g.insert( g.end(), all(g) );

		vector <int> next(n);
		vector <int64> profit(n);

		for (int j = 0; j < n; ++j) {
			int64 cur = r;
			int64 cost = 0;
			

			cost += (cur / people) * people;
			cur = cur % people;
		
			int ind = j;
			while (g[ind] <= cur) {
				cur -= g[ind];
				cost += g[ind];
				++ind;
				
				if (ind >= j + n) break;
			}
			
			next[j] = ind % n;
			profit[j] = cost;

		}

		vector <bool> was(n, false);


		int cur = 0;
		int last = 0;

		while (true) {
			was[cur] = true;
			int go = next[cur];
			if (was[go]) {
				last = go;	
				break;
			}
			cur = go;
		}


		int64 res = 0;
		cur = 0;
		while (k > 0) {
			if (cur == last) {
				int64 cost = profit[cur];
				int go = next[cur];
				
				int nt = 1;
				while ( go != cur ) {
					++nt;
					cost += profit[go];
					go = next[go];
				
				}
				
				res += (k / nt) * cost;
				k = k % nt;
				
			}

			if (k > 0) {
				--k;
				res += profit[cur];
				cur = next[cur];
			}

		
		}

		cout << "Case #" << i + 1 << ": " << res << endl;


	}



    return 0;
}


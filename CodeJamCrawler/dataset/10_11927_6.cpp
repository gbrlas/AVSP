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

	int C;
	cin >> C;


	for (int c = 0; c < C; ++c) {
		int r;
		cin >> r;
		
		int x0, x1, y0, y1;
		
		int nx = 101;
		int ny = 101;


		vector < vector <bool> > f(nx, vector <bool> (ny, false) );

		for (int i = 0; i < r; ++i) {
			cin >> x0 >> y0 >> x1 >> y1;
			for (int x = x0; x <= x1; ++x) {
				for(int y = y0; y <= y1; ++y) {
					f[x][y] = true;
				}
			}
		}

		int t = 0;
		while (true) {
			//cout << "t = " << t << endl;
			/*	
			for (int i = 0; i < sz(f); ++i) {
				for(int j = 0; j < sz(f[i]); ++j) {
					cout << (int) f[i][j];
				}
				cout << endl;
			}
			*/

			vector < vector < bool > > new_f(nx, vector <bool> (ny, false));
			bool empty = true;
			for (int x = 1; x < nx; ++x) {
				for (int y = 1; y < ny; ++y) {
					if (f[x][y]) {
						empty = false;
						if ( f[x][y-1] || f[x-1][y]) new_f[x][y] = true;
					} else {
						if (f[x][y-1] && f[x-1][y] ) new_f[x][y] = true;

					}
				}
			}
			
			if (empty) break;
			++t;
			f = new_f;
		}
		
		cout << "Case #" << c + 1 << ": " << t << endl;
	
	}



    return 0;
}


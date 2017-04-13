// I love natalia

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back

#define DEBUG(x) cout << #x << ": " << (x) << endl;

char A[100][100];

bool check(int i, int j) {
	return (A[i  ][j  ] == '#' && 
		    A[i+1][j  ] == '#' &&
			A[i  ][j+1] == '#' && 
			A[i+1][j+1] == '#');
}

void doMagic(int i, int j) {
	A[i  ][j  ] = '/' ;
	A[i+1][j  ] = '\\';
	A[i  ][j+1] = '\\';
	A[i+1][j+1] = '/' ;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen( "input.txt", "rt", stdin );
	freopen("output.txt", "wt", stdout);
#endif

	int    T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int    R,   C;
		cin >> R >> C;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> A[i][j];
			}
		}

		bool fl = false;
		while ( true ) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (A[i][j] == '#') {
						if (check(i, j)) {
							doMagic(i, j);
						}
						else {
							goto loopexit;
						}
					}
				}
			}

			fl = true;
			break;
		}

loopexit:
		cout << "Case #" << t << ":" << endl;

		if ( fl ) {
			for (int i= 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					cout << A[i][j];
				}

				cout << endl;
			}
		}
		else {
			cout << "Impossible" << endl;
		}
	}

exit:
	return ( 0 );
}

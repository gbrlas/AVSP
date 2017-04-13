#include <iostream>
#include <cmath>

using namespace std;


int main() {
	int T, m, n, i, j, lmax, cmax;
	bool possible;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> m >> n;
		int A[m][n][2];
		for(i = 0; i < m; i++) {
			for(j = 0; j < n; j++) {
				cin >> A[i][j][0];
				A[i][j][1] = 0;
			}
		}
		// lines
		for(i = 0; i < m; i++) {
			lmax = A[i][0][0];
			for(j = 1; j < n; j++) {
				if(lmax < A[i][j][0]) lmax = A[i][j][0];
			}
			for(j = 0; j < n; j++) {
				if(lmax == A[i][j][0]) A[i][j][1] = 1;
			}
		}
		// columns
		for(j = 0; j < n; j++) {
			cmax = A[0][j][0];
			for(i = 0; i < m; i++) {
				if(cmax < A[i][j][0]) cmax = A[i][j][0];
			}
			for(i = 0; i < m; i++) {
				if(cmax == A[i][j][0]) A[i][j][1] = 1;
			}
		}
		
		possible = true;
		for(i = 0; i < m; i++)
			for(j = 0; j < n; j++)
				if(A[i][j][1] == 0) possible = false;

		cout << "Case #" << t << ": ";
		if(possible) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

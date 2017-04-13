// I love natalia

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen( "input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int    T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int pB = 1;
		int pO = 1;

		int    N;
		cin >> N;

		int res = 0;
		int   d = 0;
		char Rpred = ' ';

		for (int n = 0; n < N; n++) {
			char   R;
			int         P;
			cin >> R >> P;

			if ( R == 'B' ) {
				if ( R != Rpred ) {
					d = max( abs(pB-P)-d+1, 1);
					res += d;
				}
				else {
					d += abs(pB-P)+1;
					res += abs(pB-P)+1;
				}

				pB = P;
			}

			if ( R == 'O' ) {
				if ( R != Rpred ) {
					d = max( abs(pO-P)-d+1, 1);
					res += d;
				}
				else {
					d += abs(pO-P)+1;
					res += abs(pO-P)+1;
				}

				pO = P;
			}

			Rpred = R;
		}

		cout << "Case #" << t << ": " << res << endl;
	}

	return 0;
}
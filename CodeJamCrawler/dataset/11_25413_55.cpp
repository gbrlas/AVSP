// I love natalia

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen( "input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int    T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int    N;
		cin >> N;

		int res = 0;

		int PB = 1;
		int PO = 1;

		int   d =  0 ;
		char RP = '#';

		for (int n = 0; n < N; n++) {
			char   R;
			int         P;
			cin >> R >> P;

			int tmp;

			if ( R == 'B' ) {
				tmp = abs(PB-P)+1;

				if ( R != RP )
					res += d = max(tmp-d, 1);
				else {
					  d += tmp;
					res += tmp;
				}

				PB = P;
			}

			if ( R == 'O' ) {
				tmp = abs(PO-P)+1;

				if ( R != RP )
					res += d = max(tmp-d, 1);
				else {
					  d += tmp;
					res += tmp;
				}

				PO = P;
			}

			RP = R;
		}

		cout << "Case #" << t << ": " << res << endl;
	}

	return 0;
}

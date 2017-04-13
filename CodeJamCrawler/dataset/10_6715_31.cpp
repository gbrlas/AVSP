#include <iostream>

using namespace std;

int MSIZE = 101;

int main () {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int R;
		cin >> R;
		
		int A[150][150][2];
		for (int i = 0; i < MSIZE; ++i)
			for (int j = 0; j < MSIZE; ++j) {			
				A[i][j][0] = 0;
				A[i][j][1] = 0;
			}
		for (int p = 0; p < R; ++p) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for (int i = x1; i <= x2; ++i)
				for (int j = y1; j <= y2; ++j)
					A[i][j][0] = 1;
		}

		bool ok = true;
		int ans = 0;
		int cur = 1;
		int prev = 0;
		while (true) {
			ok = false;
			for (int i = 0; i < MSIZE; ++i)
				for (int j = 0; j < MSIZE; ++j) {
					bool up = false, left = false;
					if ((i > 0) && (A[i-1][j][prev] == 1))
						up = true;
					if ((j > 0) && (A[i][j-1][prev] == 1))
						left = true;
					if (A[i][j][prev] == 1) {
						if ((!up) && (!left))
							A[i][j][cur] = 0;
						else {
							A[i][j][cur] = 1;
							ok = true;
						}
					} else {
						if (up && left) {
							A[i][j][cur] = 1;
							ok = true;
						}
						else
							A[i][j][cur] = 0;
					}
				}

			/*for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j)
					cout << A[i][j][cur];
				cout << endl;
			}
			cout << endl;*/
				
			cur = (cur + 1)%2;
			prev = (prev + 1)%2;
			if (!ok)
				break;
			++ans;
		}
		cout << "Case #" << t+1 << ": " << ans+1 << endl;
	}
}

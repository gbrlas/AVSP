#include<iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int r1, r2;
		int m1[4][4], m2[4][4];
		cin >> r1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> m1[i][j];
			}
		}
		cin >> r2;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> m2[i][j];
			}
		}
		int c[16];
		for (int i = 0; i < 16; i++) {
			c[i] = 0;
		}
		for (int i = 0; i < 4; i++) {
			c[m1[r1 - 1][i] - 1]++;
		}
		for (int i = 0; i < 4; i++) {
			c[m2[r2 - 1][i] - 1]++;
		}
		int cr = 0;
		int lr = 0;
		for (int i = 0; i < 16; i++) {
			if (c[i] == 2) {
				cr++;
				lr = i + 1;
			}
		}
		cout << "Case #" << t << ": ";
		if (cr == 0) {
			cout << "Volunteer cheated!";
		} else if (cr == 1) {
			cout << lr;
		} else {
			cout << "Bad magician!";
		}
		cout << endl;
	}
}

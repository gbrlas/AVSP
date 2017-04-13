#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ifstream in("A-small-attempt1.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf()); 

	int cases;
	cin >> cases;
	int arrangement[4][4];
	int FirstRow[4];
	int SecondRow[4];
	int count = 0;
	int ans = -1;
	int caseNo = 0;

	for (int i = 0; i < cases; i++) {
		caseNo++;
		int row1;
		cin >> row1;

		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < 4; j++) {
				cin >> arrangement[k][j];
				if (k == row1-1) {
					FirstRow[j] = arrangement[k][j];
				}
			}
		}

		int row2;
		cin >> row2;

		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < 4; j++) {
				cin >> arrangement[k][j];
				if (k == row2-1) {
					SecondRow[j] = arrangement[k][j];
				}
			}
		}

		for (int k = 0; k < 4; k++) {
			for (int kk = 0; kk < 4; kk++) {
				if (FirstRow[kk] == SecondRow[k]) {
					ans = SecondRow[k];
					count++;
				}
			}
		}

		if (count == 1) {
			cout << "Case #" << caseNo << ": " << ans;
		} else if (count > 1) {
			cout << "Case #" << caseNo << ": " << "Bad magician!";
		} else if (count == 0) {
			cout << "Case #" << caseNo << ": " << "Volunteer cheated!";
		}

		count = 0;
		cout << endl;
	}

	return 0;
}
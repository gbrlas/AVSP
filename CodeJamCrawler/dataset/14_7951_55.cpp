#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream read("Input.txt");
	ofstream write("Output.txt");
	int t;
	read >> t;
	int ctr1 = 1;
	while (t--) {
		int r1, r2, e,e1;
		read >> r1;
		int f = 0;
		int ctr = 0;
		int a[4][4];
		int b[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				read >> a[i][j];
			}
		}
		read >> r2;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				read >> b[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			f = 0;
			for (int j = 0; j < 4; j++) {
				if (a[r1-1][i] == b[r2-1][j]) {
					ctr++;
					e = a[r1-1][i];
					f = 1;
					break;
				}
			}
		}
		write << "Case #" << ctr1 << ": ";
		if (ctr == 1)
			write << e << endl;
		else if (ctr == 0)
			write << "Volunteer cheated!" << endl;
		else
			write << "Bad magician!" << endl;
		ctr1++;
	}
	return 0;
}
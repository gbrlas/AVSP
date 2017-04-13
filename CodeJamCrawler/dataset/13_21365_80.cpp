#include <iostream>
#include <string>
#include <cassert>
using namespace std;
int main() {
	int r;
	cin >> r;
	for (int k = 1; k <= r; k++) {
		string game[4];
		int cols[4][4], rows[4][4], diag[2][4];
		for (int i = 0; i < 4; i++) {
			cin >> game[i];
			for (int j = 0; j < 4; j++) {
				cols[i][j] = 0;
				rows[i][j] = 0;
			}
			diag[0][i] = 0;
			diag[1][i] = 0;
		}
		for (int i = 0; i < 4; i++) {
			cerr << game[i] << "\t";
			for (int j = 0; j < 4; j++) {
				int l;
				if (game[i][j]=='X') l=0; else
				if (game[i][j]=='O') l=1; else
				if (game[i][j]=='T') l=2; else
				if (game[i][j]=='.') l=3; else
				assert(false);
				cerr << "XOT."[l];
				cols[j][l]++;
				rows[i][l]++;
				if (i==j) diag[0][l]++;
				if (i+j==3) diag[1][l]++;
			}
			cerr << endl;
		}
		bool xwin=false,owin=false,filled=true;
		for (int i = 0; i < 4; i++) {
			if (rows[i][3]>0) filled=false;
			if (rows[i][0]+rows[i][2]==4) xwin=true;
			if (rows[i][1]+rows[i][2]==4) owin=true;
			if (cols[i][0]+cols[i][2]==4) xwin=true;
			if (cols[i][1]+cols[i][2]==4) owin=true;
		}
		if (diag[0][0]+diag[0][2]==4) xwin=true;
		if (diag[0][1]+diag[0][2]==4) owin=true;
		if (diag[1][0]+diag[1][2]==4) xwin=true;
		if (diag[1][1]+diag[1][2]==4) owin=true;
		if (xwin && !owin) {
			cout << "Case #" << k << ": X won" << endl;
		} else if (owin && !xwin) {
			cout << "Case #" << k << ": O won" << endl;	
		} else if ((owin && xwin) || filled) {
			cout << "Case #" << k << ": Draw" << endl;
		} else {
			cout << "Case #" << k << ": Game has not completed" << endl;		
		}
	}
	return 0;
}

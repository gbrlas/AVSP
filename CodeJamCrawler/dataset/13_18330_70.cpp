#include <iostream>
#include <cstdio>
using namespace std;

string board[4];

int main()
{
	int t;
	int x, o, e;
//	freopen("small.in","r",stdin);
//	freopen("small.out","w",stdout);
	cin >> t;
	for(int k = 0; k < t; k++) {
		cin >> board[0] >> board[1] >> board[2] >> board[3];
		e = 0;
		for(int i = 0; i < 4; i++) {
			x = 0;
			o = 0;
			for(int j = 0; j < 4; j++) {
				switch(board[i][j]) {
					case 'X': x++; break;
					case 'O': o++; break;
					case 'T': x++, o++; break;
					case '.': e++; break;
				}
			}
			if(x == 4) {
				cout << "Case #" << k + 1 << ": X won" << endl;
				break;
			} else if(o == 4) {
				cout << "Case #" << k + 1 << ": O won" << endl;
				break;
			}
			x = 0;
			o = 0;
			for(int j = 0; j < 4; j++) {
				switch(board[j][i]) {
					case 'X': x++; break;
					case 'O': o++; break;
					case 'T': x++, o++; break;
					case '.': e++; break;
				}
			}
			if(x == 4) {
				cout << "Case #" << k + 1 << ": X won" << endl;
				break;
			} else if(o == 4) {
				cout << "Case #" << k + 1 << ": O won" << endl;
				break;
			}
		}
		if(x!=4&&o!=4) {
			x = 0; o = 0;
			for(int i = 0; i < 4; i++) {
				switch(board[i][i]) {
					case 'X': x++; break;
					case 'O': o++; break;
					case 'T': x++, o++; break;
				}
			}
			if(x == 4) {
				cout << "Case #" << k + 1 << ": X won" << endl;
			} else if(o == 4) {
				cout << "Case #" << k + 1 << ": O won" << endl;
			} else {
				x = 0; o = 0;
				for(int i = 0; i < 4; i++) {
					switch(board[i][3 - i]) {
						case 'X': x++; break;
						case 'O': o++; break;
						case 'T': x++, o++; break;
					}
				}
				if(x == 4) {
					cout << "Case #" << k + 1 << ": X won" << endl;
				} else if(o == 4) {
					cout << "Case #" << k + 1 << ": O won" << endl;
				} else if(e == 0) {
					cout << "Case #" << k + 1 << ": Draw" << endl;
				} else {
					cout << "Case #" << k + 1 << ": Game has not completed" << endl;
				}
			}
		}
	}
	return 0;
}




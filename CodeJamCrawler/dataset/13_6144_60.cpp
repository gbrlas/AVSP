#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

	ifstream in("A-small-attempt0.in");
	ofstream out("A-small-attempt0.out");
	int t = 0;
	in >> t;
	cout << t << endl;
	vector<vector<char> > board(4, vector<char>(4, '.'));
	for (int i = 1; i <= t; i++) {
		int res = 3;
		for (int ii = 0; ii < 4; ii++) {
			for (int jj = 0; jj < 4; jj++) {
				in >> board[ii][jj];
				cout << board[ii][jj] << " ";
				if ('.' == board[ii][jj]) {
					res = 4;
				}
			}
			cout << endl;
		}
		cout << endl;

		for (int ii = 0; ii < 4; ii++) {
			int cnt = 1;
			char c = 0;
			for (int jj = 0; jj < 4; jj++) {
				if ('.' == board[ii][jj]) {
					break;	
				}
				if (jj > 0 && (board[ii][jj] == board[ii][jj-1] || 'T' == board[ii][jj])) {
					cnt++;
					if (board[ii][jj] != 'T') {
						c = board[ii][jj];
					}
				}
			}
			if (cnt == 4) {
				if ('X' == c) {
					res = 1;
				}else if ('O' == c) {
					res = 2;	
				}
				break;
			}
		}
		if (4 == res || 3 == res) {
			for (int ii = 0; ii < 4; ii++) {
				int cnt = 1;
				char c = 0;
				for (int jj = 0; jj < 4; jj++) {
					if ('.' == board[jj][ii]) {
						break;	
					}
					if (jj > 0 && (board[jj][ii] == board[jj-1][ii] || 'T' == board[jj][ii])) {
						cnt++;
						if (board[jj][ii] != 'T') {
							c = board[jj][ii];
						}
					}
				}
				if (cnt == 4) {
					if ('X' == c) {
						res = 1;
					}else if ('O' == c) {
						res = 2;	
					}
					break;
				}
			}	
		}
		if (4 == res || 3 == res) {
			int cnt = 1;
			char c = 0;
			for (int ii = 0; ii < 4; ii++) {
				if ('.' == board[ii][ii]) {
					break;	
				}
				if (ii > 0 && (board[ii][ii] == board[ii-1][ii-1] || 'T' == board[ii][ii])) {
					cnt++;
					if (board[ii][ii] != 'T') {
						c = board[ii][ii];
					}
				}
			}
			if (cnt == 4) {
				if ('X' == c) {
					res = 1;
				}else if ('O' == c) {
					res = 2;	
				}
			}
			
			if (cnt < 4) {
				cnt = 1;
				c = 0;
				for (int ii = 0; ii < 4; ii++) {
					if ('.' == board[ii][3-ii]) {
						break;	
					}
					if (ii > 0 && (board[ii][3-ii] == board[ii-1][3-ii+1] || 'T' == board[ii][3-ii])) {
						cnt++;
						if (board[ii][3-ii] != 'T') {
							c = board[ii][3-ii];
						}
					}
				}
				if (cnt == 4) {
					if ('X' == c) {
						res = 1;
					}else if ('O' == c) {
						res = 2;	
					}
				}			
			}					
		}
		out << "Case #" << i << ": ";
		cout << "Case #" << i << ": ";
		switch (res) {
			case 1: 
				out << "X won" << endl;
				cout << "X won" << endl;
				break;
			case 2:
				out << "O won" << endl;
				cout << "O won" << endl;
				break;
			case 3:
				out << "Draw" << endl;
				cout << "Draw" << endl;
				break;
			case 4:
				out << "Game has not completed" << endl;
				cout << "Game has not completed" << endl;
				break;
			default:
				break;
		}
	}
	
	in.close();
	out.close();	
	
	return 0;	
}

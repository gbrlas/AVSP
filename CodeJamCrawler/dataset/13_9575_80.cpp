// g++ -std=c++0x tictactoe.cpp

#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

typedef vector <char> vc;
typedef vector <vc> vvc;

bool swin(const vvc& b, char c) {
	vector <vector <bool>> abst(4, vector <bool> (4));
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			abst[i][j] = (b[i][j] == c || b[i][j] == 'T');
		}
	}

	bool diag1 = true, diag2 = true;
	for (size_t i = 0; i < 4; i++) {
		diag1 = diag1 && abst[i][i];
		diag2 = diag2 && abst[i][4 - i - 1];
	}

	vector <bool> lines(4);
	for (size_t i = 0; i < 4; i++) {
		lines[i] = accumulate(abst[i].begin(), abst[i].end(), true, logical_and <bool> ());
	}
	return accumulate(lines.begin(), lines.end(), false, logical_or <bool> ()) || diag1 || diag2;
}

string dw() {
	vvc b(4, vc(4)), bp(4, vc(4));
	bool done = true;

	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			cin >> b[i][j];
			bp[j][i] = b[i][j];
			if (b[i][j] == '.') {
				done = false;
			}
		}
	}

	if (swin(b, 'X') || swin(bp, 'X')) {
		return "X won";
	} else if (swin(b, 'O') || swin(bp, 'O')) {
		return "O won";
	} else if (done) {
		return "Draw";
	} else {
		return "Game has not completed";
	}
}

int main() {
	size_t T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		cout << "Case #" << (t + 1) << ": " << dw() << endl;
	}
	return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct TestCase {
	int board[4][4];
};

std::vector<TestCase> load(const std::string& file) {
	std::ifstream ip(file);
	std::vector<TestCase> res;
	int cases;
	ip >> cases;
	for (int t = 0; t < cases; t++) {
		TestCase cs;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				char c;
				ip >> c;
				switch (c) {
				case '.': c = 0; break;
				case 'X': c = 1; break;
				case 'O': c = 2; break;
				case 'T': c = 3; break;
				}
				cs.board[i][j] = (int)c;
			}
		}

		res.push_back(cs);
		std::string skip;
		std::getline(ip, skip);
	}
	ip.close();
	return res;
}

bool solveFor(TestCase& cs, int player) {
	for (int i = 0; i < 4; i++) {
		int sumRow = 0, sumCol = 0;
		for (int j = 0; j < 4; j++) {
			sumRow += ((cs.board[i][j] & player) != 0);
			sumCol += ((cs.board[j][i] & player) != 0);
		}
		if (sumRow == 4 || sumCol == 4)
			return true;
	}

	int sumMain = 0, sumOth = 0;
	for (int i = 0; i < 4; i++) {
		sumMain += ((cs.board[i][i] & player) != 0);
		sumOth += ((cs.board[i][3 - i] & player) != 0);
	}
	return (sumMain == 4) || (sumOth == 4);
}

bool hasEmpty(TestCase& cs) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (cs.board[i][j] == 0)
				return true;
		}
	}
	return false;
}

std::string solve(TestCase& cs) {
	if (solveFor(cs, 1))
		return "X won";
	if (solveFor(cs, 2))
		return "O won";
	if (hasEmpty(cs))
		return "Game has not completed";
	return "Draw";
}

int main() {
	auto data = load("A-small-attempt0.in");
	std::ofstream op("A-small-attempt0.out");
	int i = 1;
	for (auto it = data.begin(); it != data.end(); ++it, ++i) {
		op << "Case #" << i << ": " << solve(*it) << std::endl;
	}
	op.close();
}
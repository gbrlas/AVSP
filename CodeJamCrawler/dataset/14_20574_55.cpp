#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

struct TestCase {
	int board1[4][4];
	int board2[4][4];
	int row1, row2;
};

std::vector<TestCase> load(const std::string& s) {
	std::ifstream fs(s);
	if (!fs.is_open())
		std::cout << "Not found" << std::endl;

	int n;
	std::vector<TestCase> res;
	fs >> n;
	for (int i = 0; i < n; i++) {
		TestCase tc;
		fs >> tc.row1;
		--tc.row1;
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				fs >> tc.board1[y][x];
		fs >> tc.row2;
		--tc.row2;
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				fs >> tc.board2[y][x];
		res.push_back(tc);
	}
	fs.close();
	return res;
}

std::string solve(TestCase& tc) {
	int *r1 = tc.board1[tc.row1];
	std::vector<int> found;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (r1[i] == tc.board2[tc.row2][j])
				found.push_back(r1[i]);
		}
	}
	if (found.empty())
		return "Volunteer cheated!";
	if (found.size() > 1)
		return "Bad magician!";
	return std::to_string(found[0]);
}

int main(int argc, const char *argv[]) {
	std::ofstream fs("A-small-attempt0.out");
	int i = 1;
	for (auto tc : load("A-small-attempt0.in")) {
		fs << "Case #" << i << ": " << solve(tc) << std::endl;
		i++;
	}
	fs.close();
	return 0;
}

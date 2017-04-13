#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct TestCase {
	int w, h;
	int lawn[100][100];
};

std::vector<TestCase> load(const std::string& file) {
	std::ifstream ip(file);
	std::vector<TestCase> res;
	int cases;
	ip >> cases;
	for (int t = 0; t < cases; t++) {
		TestCase cs;
		ip >> cs.h >> cs.w;
		for (int y = 0; y < cs.h; y++) {
			for (int x = 0; x < cs.w; x++) {
				ip >> cs.lawn[y][x];
			}
		}

		res.push_back(cs);
	}
	ip.close();
	return res;
}

struct CaseInfo {
	std::vector<int> rowMax, colMax;
	TestCase& cs;

	CaseInfo(TestCase& _cs) : cs(_cs) {
		findRow(); findCol();
	}

	void findRow() {
		for (int y = 0; y < cs.h; y++) {
			int mx = cs.lawn[y][0];
			for (int x = 0; x < cs.w; x++) {
				mx = std::max(mx, cs.lawn[y][x]);
			}
			rowMax.push_back(mx);
		}
	}

	void findCol() {
		for (int x = 0; x < cs.w; x++) {
			int mx = cs.lawn[0][x];
			for (int y = 0; y < cs.h; y++) {
				mx = std::max(mx, cs.lawn[y][x]);
			}
			colMax.push_back(mx);
		}
	}
};

bool solve(TestCase& cs) {
	CaseInfo info(cs);
	for (int y = 0; y < cs.h; y++) {
		for (int x = 0; x < cs.w; x++) {
			if (cs.lawn[y][x] < info.rowMax[y] && cs.lawn[y][x] < info.colMax[x])
				return false;
		}
	}
	return true;
}

int main() {
	auto data = load("B-large.in");
	std::ofstream op("B-large.out");
	int i = 1;
	for (auto it = data.begin(); it != data.end(); ++it, ++i) {
		op << "Case #" << i << ": " << (solve(*it) ? "YES" : "NO") << std::endl;
	}
	op.close();
}
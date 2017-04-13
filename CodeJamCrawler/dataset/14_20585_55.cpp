#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct TestCase {
	int n;
	set<double> ken, naomi;
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
		fs >> tc.n;
		for (int i = 0; i < tc.n; i++) {
			double w;
			fs >> w;
			tc.naomi.insert(w);
		}

		for (int i = 0; i < tc.n; i++) {
			double w;
			fs >> w;
			tc.ken.insert(w);
		}

		res.push_back(tc);
	}
	fs.close();
	return res;
}

std::string solve(TestCase& tc) {
	double eps = 1e-6;

	std::set<double> kenCopy = tc.ken;
	int pointsWar = 0;
	for (auto nw : tc.naomi) {
		auto kit = kenCopy.upper_bound(nw);
		if (kit == kenCopy.end()) {
			kenCopy.erase(kenCopy.begin());
			++pointsWar;
		} else {
			kenCopy.erase(kit);
		}
	}

	set<double> naomi = tc.naomi;
	set<double> ken = tc.ken;
	int pointsDec = 0;
	while (!naomi.empty()) {
		double nw = *naomi.rbegin();
		double kw = *ken.rbegin();
		if (nw > kw) {
			++ pointsDec;
			naomi.erase(--naomi.end());
			ken.erase(--ken.end());
		} else {
			naomi.erase(naomi.begin());
			ken.erase(--ken.end());
		}
	}

	return std::to_string(pointsDec) + " " + std::to_string(pointsWar);
}

int main(int argc, const char *argv[]) {
	std::ofstream fs("D-small-attempt0.out");
	fs.precision(8);
	fs << std::fixed;
	int i = 1;
	for (auto tc : load("D-small-attempt0.in")) {
		fs << "Case #" << i << ": " << solve(tc) << std::endl;
		i++;
	}
	fs.close();
	return 0;
}

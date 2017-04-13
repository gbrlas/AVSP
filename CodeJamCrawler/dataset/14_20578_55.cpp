#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

struct TestCase {
	double cost;
	double farmRate;
	double target;
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
		fs >> tc.cost;
		fs >> tc.farmRate;
		fs >> tc.target;
		res.push_back(tc);
	}
	fs.close();
	return res;
}

std::string solve(TestCase& tc) {
	double rate = 2;
	double target = tc.target;
	double start = 0;
	double total = 0;
	while (true) {
		double nextTimeNormal = target / rate;
		double timeToFarm = (tc.cost - start) / rate;
		double timeFromFarm = (target - (timeToFarm * rate - tc.cost)) / (rate + tc.farmRate);
		double nextTimeFarm = timeToFarm + timeFromFarm;
		if (nextTimeNormal <= nextTimeFarm) {
			total += nextTimeNormal;
			break;
		} else {
			total += timeToFarm;
			start = (timeToFarm * rate - tc.cost);
			rate += tc.farmRate;
		}
	}
	return std::to_string(total);
}

int main(int argc, const char *argv[]) {
	std::ofstream fs("B-small-attempt0.out");
	int i = 1;
	for (auto tc : load("B-small-attempt0.in")) {
		fs << "Case #" << i << ": " << solve(tc) << std::endl;
		i++;
	}
	fs.close();
	return 0;
}

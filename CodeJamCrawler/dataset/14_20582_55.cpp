#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

struct TestCase {
	long double cost;
	long double farmRate;
	long double target;
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

void solve(TestCase& tc, std::ostream& os) {
	long double rate = 2;
	long double target = tc.target;
	long double start = 0;
	long double total = 0;
	while (true) {
		long double nextTimeNormal = target / rate;
		long double timeToFarm = (tc.cost - start) / rate;
		long double timeFromFarm = (target - (timeToFarm * rate - tc.cost)) / (rate + tc.farmRate);
		long double nextTimeFarm = timeToFarm + timeFromFarm;
		if (nextTimeNormal <= nextTimeFarm) {
			total += nextTimeNormal;
			break;
		} else {
			total += timeToFarm;
			start = (timeToFarm * rate - tc.cost);
			rate += tc.farmRate;
		}
	}
	os << total;
}

int main(int argc, const char *argv[]) {
	std::ofstream fs("B-large.out");
	fs.precision(8);
	fs << std::fixed;
	int i = 1;
	for (auto tc : load("B-large.in")) {
		fs << "Case #" << i << ": ";
		solve(tc, fs); fs << std::endl;
		i++;
	}
	fs.close();
	return 0;
}

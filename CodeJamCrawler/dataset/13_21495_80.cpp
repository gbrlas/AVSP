#include "lawnmower.hpp"
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

bool analyze(const Lawn& lawn) {
	auto columns = std::unique_ptr<int[]>(new int[lawn.width]);
	auto rows = std::unique_ptr<int[]>(new int[lawn.height]);

	std::fill_n(columns.get(), lawn.width, 1);
	std::fill_n(rows.get(), lawn.height, 1);

	for (int x = 0; x < lawn.width; x++) {
		for (int y = 0; y < lawn.height; y++) {
			columns[x] = std::max(columns[x], lawn(x, y));
			rows[y] = std::max(rows[y], lawn(x, y));
		}
	}

	for (int x = 0; x < lawn.width; x++) {
		for (int y = 0; y < lawn.height; y++) {
			if (lawn(x, y) != std::min(columns[x], rows[y])) return false;
		}
	}

	return true;
}

std::map<bool, std::string> outcomes = { { false, "NO" }, { true, "YES" } };

int main(int argc, char* argv[]) {
	size_t n; std::cin >> n;

	for (size_t i = 1; i <= n; ++i) {
		Lawn l(std::cin);
//		std::cout << l;
		std::cout << "Case #" << i << ": " << outcomes[analyze(l)] << std::endl;
	}
}

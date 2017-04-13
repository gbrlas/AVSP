#include "fair-and-square.hpp"
#include <iostream>
#include <cmath>

size_t fairSquares(size_t min, size_t max) {
	min = ceil(sqrt(min));
	max = floor(sqrt(max));

	size_t total = 0;
	for (size_t i = min; i <= max; i++) {
		if (isPalindromic(i) && isPalindromic(i * i)) total++;
	}
	return total;
}

int main(int argc, char* argv[]) {
	size_t n; std::cin >> n;

	for (size_t i = 1; i <= n; ++i) {
		size_t min; size_t max;
		std::cin >> min >> max;
		std::cout << "Case #" << i << ": " << fairSquares(min, max) << std::endl;
	}
}

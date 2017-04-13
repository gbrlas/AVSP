#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <BigInteger/BigInteger.hh>
#include <BigInteger/BigIntegerUtils.hh>

struct TestCase {
	unsigned long long from, to;
};

std::vector<TestCase> load(const std::string& file) {
	std::ifstream ip(file);
	std::vector<TestCase> res;
	int cases;
	ip >> cases;
	for (int t = 0; t < cases; t++) {
		TestCase cs;
		std::string from, to;
		ip >> cs.from >> cs.to;
		res.push_back(cs);
	}
	ip.close();
	return res;
}

bool palindrome(unsigned long long num) {
	auto n = num;
	unsigned long long rev = 0;
	while (num > 0) {
		const auto dig = num % 10;
		num /= 10;
		rev = rev * 10 + dig;
	}
	return n == rev;
}

void palindromesFrom(unsigned long long nr, unsigned long long (&palindromes)[11]) {
	std::string x = boost::lexical_cast<std::string>(nr);
	std::string y = x;
	std::reverse(y.begin(), y.end());
	palindromes[0] = boost::lexical_cast<unsigned long long>(x + y);
	for (int i = 0; i < 10; i++) {
		std::string tmp = x;
		tmp += ('0' + (char)i);
		tmp += y;
		palindromes[i + 1] = boost::lexical_cast<unsigned long long>(tmp);
	}
}

std::vector<unsigned long long> palindromesForDigits(int digits) {
	std::vector<unsigned long long> result;
	if (digits == 1) {
		for (unsigned long long i = 0; i < 10; i++) {
			result.push_back(i);
		}
		return result;
	}

	unsigned long long start = 1;
	for (int i = 1; i < digits / 2; i++)
		start *= 10;
	unsigned long long end = start * 10 - 1;
	if (digits % 2 == 0) {
		for (unsigned long long x = start; x <= end; x++) {
			std::string str = boost::lexical_cast<std::string>(x);
			std::string rev = str;
			std::reverse(rev.begin(), rev.end());
			result.push_back(boost::lexical_cast<unsigned long long>(str + rev));
		}
	} else {
		for (unsigned long long x = start; x <= end; x++) {
			std::string str = boost::lexical_cast<std::string>(x);
			std::string rev = str;
			std::reverse(str.begin(), str.end());
			for (char c = '0'; c <= '9'; c++)
				result.push_back(boost::lexical_cast<unsigned long long>(str + c + rev));
		}
	}
	return result;
}

template <class T>
int numDigits(T number)
{
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return std::max(1, digits);
}

unsigned long long sqrt(unsigned long long nr) {
	return (unsigned long long)sqrt((long double)nr);
}

unsigned long solve(TestCase& cs) {
	int startDig = numDigits(sqrt(cs.from));
	int endDig = numDigits(sqrt(cs.to));
	unsigned long count = 0;
	for (auto digits = startDig; digits <= endDig; digits++) {
		auto palindromes = palindromesForDigits(digits);
		for (auto pal = palindromes.begin(); pal != palindromes.end(); ++pal) {
			auto n = (*pal) * (*pal);
			if (n >= cs.from && n <= cs.to) {
				if (palindrome(n)) {
					++count;
					//std::cout << n << std::endl;
				}
			}
		}
	}
	//std::cout << "==" << std::endl;
	return count;
}

int main() {
	auto data = load("C-small-attempt0.in");
	std::ofstream op("C-small-attempt0.out");
	int i = 1;
	for (auto it = data.begin(); it != data.end(); ++it, ++i) {
		op << "Case #" << i << ": " << solve(*it) << std::endl;
	}
	op.close();
	//getchar();
}

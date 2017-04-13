#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>
#include <unordered_set>

const long long cut = 1000000007;

bool Check(const std::string &str)
{
	std::unordered_set<char> was;
	char last = str[0];
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] != last && was.find(str[i]) != was.end()) {
			return false;
		}
		was.insert(str[i]);
		last = str[i];
	}
	return true;
}


std::string makeString(const std::vector<std::string> &words)
{
	std::string result = "";
	for (int i = 0; i < words.size(); ++i) {
		result += words[i];
	}
	return result;
}

long long factorial(long long n)
{
	long long result = 1;
	while (n > 1) {
		result *= n;
		--n;
	}
	return result;
}


long long Calculate(std::vector<std::string> words)
{
	std::sort(words.begin(), words.end());
	std::vector<long long> same(1, 1); int idx = 0;
	for (int i = 1; i < words.size(); ++i) {
		if (words[i] == words[i-1]) {
			++same[idx];
		} else {
			same.push_back(1);
			++idx;
		}
	}
	long long result = 0;
	std::string to_check;
	do {
		to_check = makeString(words);
		if (Check(to_check)) {
			result = (++result) % cut;
		}
	} while (std::next_permutation(words.begin(), words.end()));
	for (int i = 0; i < same.size(); ++i) {
		result = (result * factorial(same[i])) % cut;
	}
	return result;
}


int main()
{
	int T;
	std::cin >> T;
	std::vector<std::future<long long>> fut(T);
	for (int c = 0; c < T; ++c) {
		int n; std::cin >> n;
		std::vector<std::string> words(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> words[i];
		}
		fut[c] = std::async(std::launch::async, Calculate, std::move(words));
	}
	for (int c = 0; c < T; ++c) {
		std::cout << "Case #" << (c + 1) << ": " << fut[c].get() << '\n';
	}
	std::cin.ignore(2);
	return 0;
}
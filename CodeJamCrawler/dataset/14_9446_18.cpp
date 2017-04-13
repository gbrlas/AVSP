#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>


std::stack<std::pair<char, int> > convert(const std::string &_word)
{
	std::stack<std::pair<char, int> > result;
	for (int i = 0; i < _word.size(); ++i) {
		if (result.empty()) {
			result.push(std::make_pair(_word[i], 0));
		} else {
			if (result.top().first == _word[i]) {
				++result.top().second;
			} else {
				result.push(std::make_pair(_word[i], 0));
			}
		}
	}
	return result;
}


bool possible(const std::string &_w1, const std::string &_w2)
{
	std::stack<char> s1, s2;
	s1.push(_w1[0]); s2.push(_w2[0]);
	for (int i = 1; i < _w1.size(); ++i) {
		if (_w1[i] != s1.top()) {
			s1.push(_w1[i]);
		}
	}
	for (int i = 1; i < _w2.size(); ++i) {
		if (_w2[i] != s2.top()) {
			s2.push(_w2[i]);
		}
	}
	if (s1.size() != s2.size()) {
		return false;
	} else {
		while (!s1.empty() && s1.top() == s2.top()) {
			s1.pop(); s2.pop();
		}
		return s1.empty();
	}
}


int main()
{
	int T, N;
	std::cin >> T;
	for (int cases = 1; cases <= T; ++cases) {
		std::cin >> N;
		std::vector<std::string> words(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> words[i];
		}
		if (possible(words[0], words[1])) {
			int result = 0;
			auto s1 = convert(words[0]);
			auto s2 = convert(words[1]);
			while (!s1.empty()) {
				result += std::abs(s1.top().second - s2.top().second);
				s1.pop(); s2.pop();
			}
			std::cout << "Case #" << cases << ": " << result << '\n';
		} else {
			std::cout << "Case #" << cases << ": Fegla Won\n";
		}
	}

	return 0;
}
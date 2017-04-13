#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

int FaS[12] = {
	0, 1, 4, 9, 121,
	484, 10201, 12321,
	14641, 40804, 44944, 1000000
};

bool EqualReverse (const std::string &_r)
{
	for (int i = 0, j = _r.size() - 1; i < j; ++i, --j) {
		if (_r[i] != _r[j]) {
			return false;
		}
	}
	return true;
}

bool FairAndSquare (long long _n)
{
	std::string n;	
	std::stringstream ss;
	ss << _n; ss >> n;
	if (!EqualReverse(n)) {
		return false;
	}
	long long ns = _n * _n;
	n = "";
	std::stringstream sss;
	sss << ns; sss >> n;
	return EqualReverse(n);
}

int lower_bound (int _s)
{
	int m, b = 1, e = 10;
	while (true) {
		m = (b + e) / 2;
		if (FaS[m] <= _s && _s < FaS[m+1]) {
			return m;
		} else if (FaS[m] < _s) {
			b = m;
		} else {
			e = m;
		}
	}
}

int upper_bound (int _s)
{
	int m, b = 1, e = 10;
	while (true) {
		m = (b + e) / 2;
		if (FaS[m-1] < _s && _s <= FaS[m]) {
			return m;
		} else if (FaS[m] < _s) {
			b = m;
		} else {
			e = m;
		}
	}
}

int main()
{
	/*long long p = 100;
	for (long long i = 1; i < 1000; ++i) {
		if (i > 3 * p) {
			p *= 10;
			i = p;
		}
		if (FairAndSquare(i)) {
			std::cout << i << '\t' << i * i << '\n';
		}
	}*/

	int T, A, B;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		std::cin >> A >> B;
		//std::cout << "Case #" << i << ": " << (std::upper_bound (FaS, FaS + 10, A) - std::lower_bound (FaS, FaS + 10, B)) << '\n';
		std::cout << "Case #" << i << ": " << lower_bound(B) - upper_bound(A) + 1 << '\n';
	}

	return 0;
}
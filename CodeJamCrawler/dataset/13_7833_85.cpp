#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

unsigned long long FaS[] = {
	0,
	1,
	4,
	9,
	121,
	484,
	10201,
	12321,
	14641,
	40804,
	44944,
	1002001,
	1234321,
	4008004,
	100020001,
	102030201,
	104060401,
	121242121,
	123454321,
	125686521,
	400080004,
	404090404,
	10000200001,
	10221412201,
	12102420121,
	12345654321,
	40000800004,
	1000002000001,
	1002003002001,
	1004006004001,
	1020304030201,
	1022325232201,
	1024348434201,
	1210024200121,
	1212225222121,
	1214428244121,
	1232346432321,
	1234567654321,
	4000008000004,
	4004009004004,
	100000020000001,
	100220141022001,
	102012040210201,
	102234363432201,
	121000242000121,
	121242363242121,
	123212464212321,
	123456787654321,
	400000080000004,
	1000000000000000
};

int FaS_size = sizeof(FaS) / sizeof(unsigned long long);

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

unsigned long long lower_bound (unsigned long long _s)
{
	unsigned long long m, b = 1, e = FaS_size;
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

unsigned long long upper_bound (unsigned long long _s)
{
	unsigned long long m, b = 1, e = FaS_size;
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
	for (long long i = 1; i < 100000000; ++i) {
		if (i > 3 * p) {
			p *= 10;
			i = p;
		}
		if (FairAndSquare(i)) {
			std::cout << i * i << '\n';
		}
	}*/

	unsigned long long T, A, B;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		std::cin >> A >> B;
		//std::cout << "Case #" << i << ": " << (std::upper_bound (FaS, FaS + 10, A) - std::lower_bound (FaS, FaS + 10, B)) << '\n';
		std::cout << "Case #" << i << ": " << lower_bound(B) - upper_bound(A) + 1 << '\n';
	}

	return 0;
}
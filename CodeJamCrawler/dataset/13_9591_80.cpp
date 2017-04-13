// g++ -std=c++0x fsq.cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

bool pallindrome(const string& s1) {
	return equal(s1.begin(), s1.end(), s1.rbegin());
}

bool pallindrome(const size_t& n) {
	string sn(lexical_cast <string> (n));
	return pallindrome(sn);
}

size_t dw() {
	size_t A, B;
	cin >> A >> B;
	size_t sA, sB;
	sA = floor(sqrt(static_cast <double> (A)));
	sB = ceil(sqrt(static_cast <double> (B)));

	size_t ans = 0;
	for (size_t i = sA; i <= sB; i++) {
		size_t si = i * i;
		if (A <= si && si <= B && pallindrome(i) && pallindrome(si)) {
			ans++;
		}
	}

	return ans;
}

int main() {
	size_t T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		cout << "Case #" << (t + 1) << ": " << dw() << endl;
	}
	return 0;
}


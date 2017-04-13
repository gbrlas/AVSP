#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

bool palin (long long int p) {

	stringstream ss;
	string s1;

	ss << p;
	ss >> s1;

	int i = 0;
	int m = s1.size();
	m--;
	int count = 0;

	for (i = 0; i <= m; i++) {
		if (s1[i] != s1[m - i]) {
			break;
		}
	}

	if (i == m + 1) {
		return (true);
	}
	else {
		return (false);
	}
}

int main()
{
	long long int l, p, q, t, m, n, count;

	ifstream pi;
	ofstream po;

	pi.open ("in.txt");
	po.open ("out.txt");

	pi >> t;

	for (l = 1; l <= t; l++) {
		pi >> n;
		pi >> m;
		count = 0;

		for (p = n; p <= m; p++) {
			q = sqrt (p);
			if (p == q * q) {
				if (palin (p) && palin (q)) {
					count++;
				}
			}
		}

		po << "Case #";
		po << l;
		po << ": ";
		po << count;
		po << "\n";
	}

	return 0;
}

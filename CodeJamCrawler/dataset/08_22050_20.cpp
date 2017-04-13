#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <functional>
#include <ctype.h>
#include <numeric>
#include <sstream>

using namespace std;

vector <long long> value;
vector <long long> func;
vector <long long> per;

long long M;

long long AND (long long a, long long b) {
	if (a == 1 && b == 1) {
		return 1;
	} else {
		return 0;
	}
}

long long OR (long long a, long long b) {
	if (a == 1 || b == 1) {
		return 1;
	} else {
		return 0;
	}
}

void input ()
{
	value.clear();
	value.resize(M + 1, 0);
	func.clear();
	func.resize( (M-1)/2 + 1, 0);
	per.clear();
	per.resize( (M-1)/2 + 1, 0);

	for (long long i = 1; i <= (M-1)/2; i++) {
		cin>>func[i]>>per[i];
	}
	for (long long i = (M-1)/2 + 1; i <= M; i++) {
		cin>>value[i];
	}
	for (long long i = (M-1)/2; i >= 1; i--) {
		if (func[i] == 1) {
			value[i] = AND (value[i * 2], value[i * 2 + 1]);
		} else {
			value[i] = OR (value[i * 2], value[i * 2 + 1]);
		}
	}
}

long long f(long long root, long long v)
{
	if (value[root] == v) return 0;

	if (root > (M-1)/2) return -1;

	if (v == 0) {
		if (func[root] == 0) {
			long long a = f(root * 2, 0);
			long long b = f(root * 2 + 1, 0);
			if (a >= 0 && b >= 0) {
				if (per[root] == 1) {
					return min (a, b) + 1;
				} else {
					return a + b;
				}
			} else {
				if (per[root] == 1) {
					if (max (a, b) >= 0) {
						return max (a, b) + 1;
					} else {
						return -1;
					}
				} else {
					return -1;
				}
			}
		} else {
			long long a = f(root * 2, 0);
			long long b = f(root * 2 + 1, 0);
			if (a >= 0 && b >= 0) {
				return min (a, b);
			} else {
				return max (a, b);
			}
		}
	} else {
		if (func[root] == 1) {
			long long a = f(root * 2, 1);
			long long b = f(root * 2 + 1, 1);
			if (a >= 0 && b >= 0) {
				if (per[root] == 1) {
					return min (a, b) + 1;
				} else {
					return a + b;
				}
			} else {
				if (per[root] == 1) {
					if (max (a, b) >= 0) {
						return max (a, b) + 1;
					} else {
						return -1;
					}
				} else {
					return -1;
				}
			}
		} else {
			long long a = f(root * 2, 1);
			long long b = f(root * 2 + 1, 1);
			if (a >= 0 && b >= 0) {
				return min (a, b);
			} else {
				return max (a, b);
			}
		}
	}
}

int main()
{
	long long N;
	cin>>N;
	for (long long i = 1; i <= N; i++) {
		long long V;
		cin>>M>>V;
		input();
		long long rtn = 0;
		rtn = f(1, V);
		if (rtn == -1) {
			cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
		} else {
			cout<<"Case #"<<i<<": "<<rtn<<endl;
		}
	}
	return 0;
}
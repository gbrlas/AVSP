#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int t, a, b;
int size, tmp;
int counter, CASE;
int i, j, k, n, m;
int _tmp1, _tmp2;

inline void rotate(int &a) {
	_tmp1 = a / 10;
	_tmp2 = a - _tmp1 * 10;
	for(i = 1; i < size; ++i) 
		_tmp2 *= 10;
	a = _tmp2 + _tmp1;
}

int main() {

	freopen("D:\\C-small-attempt0.in", "r", stdin);
	freopen("D:\\C-small-attempt0.out", "w", stdout);

	cin >> t;

	for(CASE = 0; CASE < t; CASE++) {

		counter = 0;
		size = 0;

		cin >> a >> b;

		tmp = a;
		while(tmp) {
			tmp /= 10;
			++size;
		}

		n = a;

		while(n < b) {
			m = n;
			for(j = 0; j < size; ++j) {
				
				_tmp1 = m / 10;
				_tmp2 = m - _tmp1 * 10;
				for(i = 1; i < size; ++i) 
					_tmp2 *= 10;
				m = _tmp2 + _tmp1;
				
			//	rotate(m);
				if(m > n && m <= b) {
					counter++;
				}
			}
			n++;
		}
		cout << "Case #" << CASE+1 << ": " << counter << endl;
	}

	return 0;
}
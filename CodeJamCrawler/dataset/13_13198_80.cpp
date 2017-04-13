#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	int i, j, k, p, q, t, n, m, l;

	ifstream pi;
	ofstream po;

	pi.open ("in.txt");
	po.open ("out.txt");
	
	pi >> t;

	for (k = 1; k <= t; k++) {
		pi >> n;
		pi >> m;

		int a[110][110];

		int a_n[105] = {0};
		int a_m[105] = {0};

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				pi >> a[i][j];
				if (a_n[i] < a[i][j]) {
					a_n[i] = a[i][j];
				}
				if (a_m[j] < a[i][j]) {
					a_m[j] = a[i][j];
				}
			}
		}
		p = 0;

		for (i = 0; i < n; i++) {
			p = 0;
			for (j = 0; j < m; j++) {
				if (a[i][j] == a_n[i] || a[i][j] == a_m[j]) {
					continue;
				}
				else {
					p = 1;
					break;
				}
			}
			if (p == 1) {
				break;
			}
		}

		if (p == 1) {
			po << "Case #";
			po << k;
			po << ": NO\n";
		}
		else {
			po << "Case #";
			po << k;
			po << ": YES\n";
		}
	}

	return 0;
}

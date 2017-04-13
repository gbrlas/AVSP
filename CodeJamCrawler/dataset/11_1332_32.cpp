#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	int t;
	cin>>t;
	for (int tt = 1; tt <= t; ++tt) {
		long long l, t, n, c;
		cin>>l>>t>>n>>c;
		vector< long long > p(c);
		vector< long long > v(n);
		for (int i = 0; i < c; ++i) {
			cin>>p[i];
		}
		for (int i = 0; i < n; ++i) {
			v[i] = p[i % c];
		}
		vector< vector < double > > w(n + 1);
		w[0].resize(l + 1);
		fill(w[0].begin(), w[0].end(), -1.0);
		w[0][0] = 0.0;
		for (int i = 1; i <= n; ++i) {
			w[i].resize(l + 1);
			fill(w[i].begin(), w[i].end(), -1.0);
			for (int j = 0; j <= l; ++j) {
				if (j == 0) {
					w[i][j] = w[i - 1][j] + v[i - 1] * 2;
				} else {
					if (w[i - 1][j - 1] >= 0) {
						double ttb = t - w[i - 1][j - 1];
						ttb = (ttb < 0) ? 0 : ttb;
						double ttm = v[i - 1] * 2, c1 = 0, c2 = 0;
						if (ttb >= ttm) {
							c1 = ttm;
						} else {
							c1 = ttb;
							c2 = v[i - 1] - ttb / 2;
						}
						if (w[i - 1][j] >= 0) {
							w[i][j] = min(w[i - 1][j] + v[i - 1] * 2, w[i - 1][j - 1] + c1 + c2);
						} else {
							w[i][j] = w[i - 1][j - 1] + c1 + c2;
						}
					}
				}
			}
		}
		/*if (tt == 61) {
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= l; ++j) {
					cout<<w[i][j]<<" ";
				}
				cout<<endl;
			}
		}*/
		sort(w.back().begin(), w.back().end());
		cout<<"Case #"<<tt<<": "<<(long long)(w.back().front())<<endl;
	}
	return 0;
}

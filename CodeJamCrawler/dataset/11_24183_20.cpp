#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
	freopen("A-small.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	rep(tc, t) {
		int n;
		scanf("%d", &n);
		int g[100], w[100];
		double wp[100], owp[100], oowp[100];
		vector<int> wo[100], lo[100];
		rep(i, n) {
			char temp[200];
			scanf("%s", temp);
			g[i] = w[i] = 0;
			rep(j, n) {
				if (temp[j] == '1') {
					++w[i];
					++g[i];
					wo[i].push_back(j);
				} else if (temp[j] == '0') {
					++g[i];
					lo[i].push_back(j);
				}
			}
			wp[i] = w[i] / (double)g[i];
		}
		rep(i, n) {
			owp[i] = 0;
			rep(j, wo[i].size()) {
				owp[i] += w[wo[i][j]] / (double)(g[wo[i][j]] - 1);
			}
			rep(j, lo[i].size()) {
				owp[i] += (w[lo[i][j]] - 1) / (double)(g[lo[i][j]] - 1);
			}
			owp[i] /= wo[i].size() + lo[i].size();
		}
		rep(i, n) {
			oowp[i] = 0;
			rep(j, wo[i].size()) {
				oowp[i] += owp[wo[i][j]];
			}
			rep(j, lo[i].size()) {
				oowp[i] += owp[lo[i][j]];
			}
			oowp[i] /= wo[i].size() + lo[i].size();
		}
		printf("Case #%d:\n", tc + 1);
		rep(i, n)
			printf("%0.12lf\n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
	}
}
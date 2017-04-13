/*
 * BotTrust.cpp
 *
 */

#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

void solve(vector<vector<int> > & v, vector<double> & rpi) {
	int i, j, n = v.size();
	vector<int> s(n, 0);
	vector<double> wp(n, 0);
	vector<double> owp(n, 0);
	vector<double> oowp(n, 0);

	// WP
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (v[i][j] != -1) {
				wp[i] += v[i][j];
				s[i] += 1;
			}

	// OWP
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (v[i][j] != -1)
				owp[i] += (wp[j] - v[j][i]) / (s[j] - 1);

	for (i = 0; i < n; ++i) {
		wp[i] /= s[i];
		owp[i] /= s[i];
	}

	// OOWP
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (v[i][j] != -1)
				oowp[i] += owp[j];

	for (i = 0; i < n; ++i)
		oowp[i] /= s[i];

	// RPI
	for (i = 0; i < n; ++i)
		rpi[i] = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
}

int main(void) {
	string line;
	int i, j, k, t, n;
	vector<vector<int> > v;
	vector<double> rpi;
	for (i = 1, cin >> t; i <= t; ++i) {
		cin >> n;
		v.resize(n, vector<int> (n));
		rpi.resize(n, 0);
		// Read input
		for (j = 0; j < n; ++j) {
			cin >> line;
			for (k = 0; k < line.size(); ++k) {
				if (line[k] == '.')
					v[j][k] = -1;
				else if (line[k] == '1')
					v[j][k] = 1;
				else if (line[k] == '0')
					v[j][k] = 0;
			}
		}

		solve(v, rpi);

		// Print the result
		printf("Case #%d:\n", i);
		for (j = 0; j < n; ++j) {
			printf("%.10lf\n", rpi[j]);
		}

		v.clear();
		rpi.clear();
	}
}

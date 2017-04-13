// I love natalia

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back

#define DEBUG(x) cout << #x << ": " << (x) << endl;

double RPI(double WP, double OWP, double OOWP) {
	return ( 0.25 * WP + 0.50 * OWP + 0.25 * OOWP );
}

int main() {
#ifndef ONLINE_JUDGE
	freopen( "input.txt", "rt", stdin );
	freopen("output.txt", "wt", stdout);
#endif

	int    T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		char A[200][200];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
			}
		}

		double WP[200];
		for (int i = 0; i < N; i++) {
			WP[i] = 0.0;

			int cnt = 0;
			int div = 0;
			for (int j = 0; j < N; j++) {
				if (A[i][j] == '1')
					cnt++;
				if (A[i][j] != '.')
					div++;
			}

			WP[i] = (double)cnt/(double)(div);
		}

		double OWP[200];
		for (int i = 0; i < N; i++) {
			OWP[i] = 0.0;

			int div = 0;
			for (int j = 0; j < N; j++) {
				if (j != i) {
					if (A[i][j] != '.') {
						div++;

						{
							int cnt = 0;
							int div = 0;
							for (int k = 0; k < N; k++) {
								if (k != i) {
									if (A[j][k] == '1')
										cnt++;
									if (A[j][k] != '.')
										div++;
								}
							}

							OWP[i] += (double)cnt/(double)div;
						}
					}
				}
			}

			OWP[i] /= (double)(div);
		}

		double OOWP[200];
		for (int i = 0; i < N; i++) {
			OOWP[i] = 0.0;

			int div = 0;
			for (int j = 0; j < N; j++) {
				if (j != i) {
					if (A[i][j] != '.') {
						div++;
						OOWP[i] += OWP[j];
					}
				}
			}

			OOWP[i] /= (double)(div);
		}

		cout << "Case #" << t+1 << ":" << endl;

		for (int i = 0; i < N; i++) {
			cout << RPI(WP[i], OWP[i], OOWP[i]) << endl;
		}
	}

exit:
	return ( 0 );
}

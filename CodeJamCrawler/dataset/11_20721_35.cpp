#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#define MAX_N 1001

int a[MAX_N][MAX_N];
long double wp[MAX_N], iowp[MAX_N], owp[MAX_N][MAX_N];

//a[i][j]=0 if team i loses to team j
//a[i][j]=1 if team i beats team j
//a[i][j]=2 if teams i and j don't play

//wp[i] = winning percentage of team i
//owp[i][j] = winning percentage of team j ignoring the games of team i

int main() {
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string il;
			cin >> il;
			for (int j = 0; j < n; j++) {
				if (il[j]=='0')
					a[i][j] = 0;
				else if (il[j]=='1')
					a[i][j] = 1;
				else if (il[j]=='.')
					a[i][j] = -1;
				else assert(false);
			}
		}

		for (int i = 0; i < n; i++) {
			int games = 0, wins = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] >= 0) games++;
				if (a[i][j] > 0) wins++;
			}
			assert(games > 0);
			wp[i] = ((long double) wins) / ((long double) games);

			for (int j = 0; j < n; j++) {
				games = 0; wins = 0;
				for (int k = 0; k < n; k++) {
					if (k == i) continue;
					if (a[j][k] >= 0) games++;
					if (a[j][k] > 0) wins++;
				}
				assert(games > 0);
				owp[i][j] = ((long double) wins) / ((long double) games);
			}
		}

		for (int i = 0; i < n; i++) {
			iowp[i] = 0; int count = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] >= 0) {
					count++;
					iowp[i] += owp[i][j];
				}
			}
			assert(count > 0);
			iowp[i] /= count;
		}

		cout << "Case #" << c << ":" << endl;
		for (int i = 0; i < n; i++) {
			long double score = 0.25 * wp[i] + 0.5 * iowp[i];
			int count = 0; long double sum = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] >= 0) {
					count++;
					sum += iowp[j];
				}
			}
			assert(count > 0);
			score += 0.25 * sum / count;
			cout << score << endl;
		}
	}
	return 0;
}


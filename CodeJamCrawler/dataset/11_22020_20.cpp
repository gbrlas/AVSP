#include <assert.h>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
	int T;
	cin >> T;
	assert(T > 0);

	for (int testCaseCount = 0; testCaseCount < T; testCaseCount++) {
		cout << "Case #" << testCaseCount+1 << ": " << endl;
		int 	N;
		cin	>> N;
		assert (N >= 3);
		vector< vector<int> > scores(N);
		vector <int>		win_number(N, 0);
		vector< double > 	wp(N);
		vector<int>	opponent_number(N, 0);

		string	oneline;
		for (int i=0; i< N; i++) {
			scores[i].resize(N);
			cin >> oneline;
			assert(oneline.length() == N);
			for(int j=0; j<N; j++) {
				switch(oneline[j]) {
				case '0':
					scores[i][j] = 0;
					opponent_number[i]++;
					break;
				case  '1':
					scores[i][j] = 1;
					opponent_number[i]++;
					win_number[i] ++;
					break;
				case  '.':
					scores[i][j] = -1;
					break;
				default:
					cerr << "wrong";
					exit(1);
				}
			}
			wp[i] = win_number[i] * 1.0  / opponent_number[i];
		}

		vector< double >	owp(N, 0);
		for (int i=0; i< N; i++) {
			for(int j=0; j<N; j++) {
				switch(scores[i][j]) {
				case 0:
					owp[i] += (win_number[j]-1) * 1.0 / (opponent_number[j] - 1);
					break;
				case  1:
					owp[i] += (win_number[j]) * 1.0 / (opponent_number[j] - 1);
					break;
				}
			}
			owp[i] /= opponent_number[i];
		}

		for (int i=0; i< N; i++) {
			double rpi = 0.25 * wp[i] + 0.50 * owp[i];
			double oowp = 0;
			for(int j=0; j<N; j++) {
				switch(scores[i][j]) {
				case 0:
				case  1:
					oowp += owp[j];
					break;
				}
			}
			oowp /= opponent_number[i];
			rpi += 0.25 * oowp;
			printf("%.10f\n", rpi);
		}
	}
}

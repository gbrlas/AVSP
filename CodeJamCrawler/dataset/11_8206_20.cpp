#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int T; cin >> T;
	for (int count = 1; count <= T; count ++) {
		int N; cin >> N;
		char matx[101][101];
		for (int i=0; i < N; i++) {
			for (int j=0; j < N; j++) {
				char x;
				cin >> x;
				matx[i][j] = x;
			}
		}
		
		double wp[101];
		double owp[101];
		double oowp[101];
		double rpi[101];
		vector<int> opp[101];
		int oppcount[101]; 
		for (int i=0; i < N; i++) {
			double count = 0, wins = 0;
			oppcount[i] = 0;
			for (int j=0; j < N; j++) {
				if (matx[i][j] == '1') wins++;
				if (matx[i][j] != '.') {
					count++;
					opp[i].push_back(j);
					oppcount[i]++;
				}
			}
			wp[i] = wins / count;
		}
		
		for (int i=0; i < N; i++) {
			owp[i] = 0;
			for (int j=0; j < opp[i].size(); j++) {
				double count = 0, wins = 0;
				for (int k=0; k < N; k++) {
					if (k == i) continue;
					if (matx[opp[i][j]][k] == '1') wins++;
					if (matx[opp[i][j]][k] != '.') count++;
				}
				owp[i] += wins / count / oppcount[i];
			}
		}
		
		for (int i=0; i < N; i++) {
			oowp[i] = 0;
			for (int j=0; j < opp[i].size(); j++) {
				oowp[i] += owp[opp[i][j]]/oppcount[i];
			}
			rpi[i] = 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i];
		}
		
		cout << "Case #" << count << ":" << endl;
		for (int i=0; i < N; i++) {
			cout << rpi[i] << endl;
		}
	}
}
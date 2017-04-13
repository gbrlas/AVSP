#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

#define fi first
#define se second

int main() {
	int T;

	cin >> T;
	for(int t = 0; t < T; t++) {
		int cards[8][8];
		pair<int,int> ans;
		vector<pair<int,int> > v;

		cin >> ans.fi;
		v.resize(16);
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				cin >> cards[i][j];
				v[cards[i][j] - 1].fi = i + 1;
			}
		}
		cin >> ans.se;
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				cin >> cards[i][j];
				v[cards[i][j] - 1].se = i + 1;
			}
		}

		int count = 0, indx;
		for(int i = 0; i < v.size(); i++) {
			if(ans == v[i]) {
				count++;
				indx = i;
			}
		}

		cout << "Case #" << t + 1 << ": ";
		if(count == 1) {
			cout << indx + 1 << endl;
		}
		else if(count < 1) {
			cout << "Volunteer cheated!" << endl;
		}
		else {
			cout << "Bad magician!" << endl;
		}
	}

	return 0;
}

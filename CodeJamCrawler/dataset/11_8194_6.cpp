#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int T; cin >> T;
	for (int t=1; t <= T; t++) {
		int N, D, G;
		cin >> N >> D >> G;
		string res;
		bool possible = false;
		for (int i=1; i <= N; i++) {
			for (int j=0; j <= N; j++) {
				if (D*i == j*100) {
					possible = true;
					break;
				}
			}
			if (possible) break;
		}
		if (G == 100 && D != 100 || G == 0 && D != 0) res = "Broken";
		else if (possible) res = "Possible";
		else res = "Broken";
		cout << "Case #" << t << ": " << res << endl;
	}

}
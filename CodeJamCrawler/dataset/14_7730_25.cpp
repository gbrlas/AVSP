#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		int v; cin >> v;
		int note[4] = {0,0,0,0};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int x; cin >> x;
				if (i == v-1) {
					note[j] = x;
				}
			}
		}
		cin >> v; int cc = 0; int chs = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int x; cin >> x;
				if (i == v-1) {
					for (int k = 0; k < 4; k++) {
						if (x == note[k]) {
							cc++;
							chs = x;
						}
					}
				}
			}
		}
		if (cc == 1) {
			cout << "Case #" << cs << ": " << chs << "\n";
		} else if (cc > 1) {
			cout << "Case #" << cs << ": Bad magician!\n";
		} else {
			cout << "Case #" << cs << ": Volunteer cheated!\n";
		}
	}
	return 0;
}
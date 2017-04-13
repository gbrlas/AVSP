#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		int n;
		cin >> n;
		int first[100];
		int btn[100];
		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c >> btn[i];
			first[i] = (c == 'O');
		}
		int next1 = 0, next2 = 0;
		while (next1 < n && !first[next1]) {
			++next1;
		}
		while (next2 < n && first[next2]) {
			++next2;
		}
		int time = 0;
		int pos1 = 1, pos2 = 1;
		while (next1 < n || next2 < n) {
			bool pressed1 = false, pressed2 = false;
			if (next1 < next2 && pos1 == btn[next1]) {
				do {
					++next1;
				} while (next1 < n && !first[next1]);
				pressed1 = true;
			} else if (next2 < next1 && pos2 == btn[next2]) {
				do {
					++next2;
				} while (next2 < n && first[next2]);
				pressed2 = true;
			}
			if (!pressed1 && next1 < n && pos1 != btn[next1]) {
				pos1 += (pos1 < btn[next1] ? 1 : -1);
			}
			if (!pressed2 && next2 < n && pos2 != btn[next2]) {
				pos2 += (pos2 < btn[next2] ? 1 : -1);
			}
			++time;
		}
		cout << "Case #" << test << ": " << time << endl;
	}
}

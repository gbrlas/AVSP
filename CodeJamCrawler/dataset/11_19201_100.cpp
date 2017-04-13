#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		int c;
		cin >> c;
		char sub[256][256];
		bool opp[256][256];
		for (int i = 0; i < 256; ++i) {
			for (int j = 0; j < 256; ++j) {
				sub[i][j] = 0;
				opp[i][j] = false;
			}
		}
		for (int i = 0; i < c; ++i) {
			char c1, c2, c3;
			cin >> c1 >> c2 >> c3;
			sub[c1][c2] = sub[c2][c1] = c3;
		}
		int d;
		cin >> d;
		for (int i = 0; i < d; ++i) {
			char c1, c2;
			cin >> c1 >> c2;
			opp[c1][c2] = opp[c2][c1] = true;
		}
		int n;
		cin >> n;
		vector<char> s;
		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c;
			if (!s.empty() && sub[c][s.back()] != 0) {
				s.back() = sub[c][s.back()];
			} else {
				bool has_opp = false;
				for (int j = 0; j < s.size(); ++j) {
					if (opp[c][s[j]]) {
						has_opp = true;
						break;
					}
				}
				if (has_opp) {
					s.clear();
				} else {
					s.push_back(c);
				}
			}
		}
		cout << "Case #" << test << ": [";
		for (int i = 0; i < s.size(); ++i) {
			cout << (i > 0 ? ", " : "") << s[i];
		}
		cout << "]" << endl;
	}
}

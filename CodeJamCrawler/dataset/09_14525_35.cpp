#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		vector<char> vc;
		for (int j = 0; j < s.length(); ++j)
			vc.push_back(s[j]);
		bool x = next_permutation(vc.begin(), vc.end());
		cout << "Case #" << (i + 1) << ": ";
		if (!x)
			for (int j = 0; j < s.length(); ++j) {
				if (vc[j] != '0') {
					cout << vc[j];
					vc[j] = '0';
					break;
				}
			}

		for (int j = 0; j < s.length(); ++j) {
			cout << (char) vc[j];
		}
		cout << endl;
	}
}

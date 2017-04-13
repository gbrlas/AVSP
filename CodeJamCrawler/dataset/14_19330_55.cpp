#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    int T = 0;
	int first = 0, second = 0;

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w+", stdout);
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		map <int, int> occur;
		cin >> first;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int tmp = 0;
				cin >> tmp;

				if (i + 1 == first) {
					occur[tmp]++;
				}
			}
		}

		cin >> second;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int tmp = 0;
				cin >> tmp;
				
				if (i + 1 == second) {
					occur[tmp]++;
				}
			}
		}

		int res = -1;
		for (auto iter = occur.begin(); iter != occur.end(); iter++) {
			if (iter->second == 2) {
				if (res == -1) {
					res = iter->first;
				} else if (res > 0) {
					res = -2;
				}
			}
		}

		cout << "Case #" << cas << ": ";
		if (res == -2) {
			cout << "Bad magician!" << endl;
		} else if (res == -1) {
			cout << "Volunteer cheated!" << endl;
		} else {
			cout << res << endl;
		}
	}
    return 0;
}

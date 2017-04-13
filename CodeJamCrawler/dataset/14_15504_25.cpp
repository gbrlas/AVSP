#include <iostream>
#include <vector>
using namespace std;


int solve(int test) {
	int a[4][4], b[4][4], m, n;
	cin >> m;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> a[i][j];
	cin >> n;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> b[i][j];
	m--; n--;
	vector <int> res;
	for (int i = 1; i < 17; i++) {
		bool flag = false;
		for (int j = 0; j < 4; j++)
			if (a[m][j] == i) flag = true;
		if (flag) {
			flag = false;
			for (int j = 0; j < 4; j++)
				if (b[n][j] == i) flag = true;
		}
		if (flag) res.push_back(i);
	}
	cout << "Case #" << test << ": ";
	if (res.size() == 0) cout << "Volunteer cheated!" << endl;
	else if (res.size() > 1) cout << "Bad magician!" << endl;
	else cout << res.front() << endl;
	return 0;
}

int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
		solve(i + 1);
	return 0;
}

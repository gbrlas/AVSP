#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		vector <string> s(4);
		string ans = "Game has not completed";
		for (int i = 0; i < 4; ++i)
			cin >> s[i];
		int count = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (s[i][j] == '.')
					++count;
		if (count == 0)
			ans = "Draw";
		bool f = true;
		for (int i = 0; i < 4; ++i) {
			f = true;
			for (int j = 0; j < 4; ++j)
				if (s[i][j] == '.' || s[i][j] == 'O')
					f = false;
			if (f) {
				ans = "X won";
			}
			f = true;
			for (int j = 0; j < 4; ++j)
				if (s[j][i] == '.' || s[j][i] == 'O')
					f = false;
			if (f) {
				ans = "X won";
			}
		}
		f = true;
		for (int i = 0; i < 4; ++i)
			if (s[i][i] == '.' || s[i][i] == 'O')
					f = false;
		if (f)
			ans = "X won";
		f = true;
		for (int i = 0; i < 4; ++i)
			if (s[i][3 - i] == '.' || s[i][3 - i] == 'O')
					f = false;
		if (f)
			ans = "X won";
		f = true;
		for (int i = 0; i < 4; ++i) {
			f = true;
			for (int j = 0; j < 4; ++j)
				if (s[i][j] == '.' || s[i][j] == 'X')
					f = false;
			if (f) {
				ans = "O won";
			}
			f = true;
			for (int j = 0; j < 4; ++j)
				if (s[j][i] == '.' || s[j][i] == 'X')
					f = false;
			if (f) {
				ans = "O won";
			}
		}
		f = true;
		for (int i = 0; i < 4; ++i)
			if (s[i][i] == '.' || s[i][i] == 'X')
					f = false;
		if (f)
			ans = "O won";
		f = true;
		for (int i = 0; i < 4; ++i)
			if (s[i][3 - i] == '.' || s[i][3 - i] == 'X')
					f = false;
		if (f)
			ans = "O won";
		cout << "Case #" << tc << ": " + ans << endl;
	}
	return 0;
}
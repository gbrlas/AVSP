#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int N = 26;


inline int ind(char c) {
	return c-'A';
}

bool check_opposed(const int p[N], const bool op[N][N], char c) {
	int id = ind(c);
	for(int i = 0; i < N; ++i) {
		if (p[i]>0 && op[i][id]) {
			return true;
		}
	}
	return false;
}

void solve(int case_i) {
	char combine[N][N] = {};
	int present[N] = {};
	bool opposed[N][N] = {};

	// parse input
	{
		int c; cin >> c;
		string buf;
		for(int i = 0; i < c; ++i) {
			cin >> buf;
			int a = ind(buf[0]), b = ind(buf[1]); char r = buf[2];
			combine[a][b] = combine[b][a] = r;
		}	
	}
	{
		int d; cin >> d;
		string buf;
		for(int i = 0; i < d; ++i) {
			cin >> buf;
			int a = ind(buf[0]), b = ind(buf[1]);
			opposed[a][b] = opposed[b][a] = true;
		}	
	}
	int n; cin >> n;
	string s; cin >> s;
	vector<char> ch;
	ch.reserve(n);
	for(int i = 0; i < n; ++i) {
		int c = ind(s[i]);
		if (!ch.empty()) {
			int tail = ind(ch.back());
			if (combine[tail][c] != '\0') {
				ch.pop_back();
				--present[tail];
				ch.push_back(combine[tail][c]);
			} else if (check_opposed(present, opposed, s[i])) {				
				ch.clear();
				fill_n(present, N, false);
			} else {
				ch.push_back(s[i]);
				++present[c];
			}
		} else {
			ch.push_back(s[i]);
			++present[c];
		}
	}
	cout << "Case #" << case_i << ": ";
	cerr << ch.size() << endl;
	cout << '[';
	for(int i = 0; i < (int)ch.size()-1; ++i) {
		cout << ch[i] << ", ";
	}
	if (!ch.empty()) {
		cout << ch.back();
	}
	cout << ']';
	endl(cout);
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		solve(i+1);
	}
	
}
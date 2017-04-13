#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool mless(string a, string b) {
	while(a[0] == '0') a = a.substr(1);
	while(b[0] == '0') b = b.substr(1);
	if(a.length() != b.length()) {
		return a.length() < b.length();
	}
	for(int i = 0; i < a.length(); i++) {
		if(a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	return false;
}

bool mmuch(string a, string b) {
	while(a[0] == '0') a = a.substr(1);
	while(b[0] == '0') b = b.substr(1);
	if(a.length() != b.length()) {
		return a.length() > b.length();
	}

	for(int i = 0; i < a.length(); i++) {
		if(a[i] == b[i]) continue;
		return a[i] > b[i];
	}
	return false;
}

int main() {
	freopen("B.in", "rt", stdin);
	freopen("B.out", "wt", stdout);

	string x;
	int t;
	cin >> t;
	for(int T = 1; T <= t; T++) {
		cin >> x;
		string x1 = string(x);
		x = "0" + x;
		//x = string(x + "0");
		string res = "";
		do {
			bool a = mmuch(x, x1);
			bool b = res.length() == 0 || mless(x, res);
			if(a && b) {
				res = x;
			}
		} while(next_permutation(x.begin(), x.end()));
		while(res[0] == '0') res = res.substr(1);
		cout << "Case #" << T << ": " << res << endl;
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
	vector<int> code(128);
	for (int i = 0; i < 10; i++) {
		code['0' + i] = i;
	}
	for (int i = 0; i < 26; i++) {
		code['a' + i] = i + 10;
	}
	int caseNum;
	cin >> caseNum;
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		string str;
		cin >> str;
		cout << "Case #" << caseIndex << ": ";
		const int n = str.size();
		vector<int> seq(n);
		for (int i = 0; i < n; i++) {
			seq[i] = code[str[i]];
		}
		vector<bool> tags(36, false);
		for (int i = 0; i < n; i++) {
			tags[seq[i]] = true;
		}
		int num = 0;
		for (int i = 0; i < 36; i++) {
			if (tags[i]) {
				num++;
			}
		}
		if (num == 1) {
			num = 2;
		}
		vector<int> mapping(36, -1);
		mapping[seq[0]] = 1;
		vector<bool> app(36, false);
		app[1] = true;
		for (int i = 1; i < n; i++) {
			if (mapping[seq[i]] == -1) {
				int j;
				for (j = 0; app[j]; j++);
				mapping[seq[i]] = j;
				app[j] = true;
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans = ans * num + mapping[seq[i]];
		}
		cout << ans << endl;
	}
	
	return 0;
}

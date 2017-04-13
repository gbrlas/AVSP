#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N, k;
	string s;
	cin >> N;
	for (int tc = 1; tc <= N; tc++) {
		scanf("%d\n", &k);
		getline(cin, s);
		vector< int > p;
		for (int i = 0; i < k; i++) {
			p.push_back(i);
		}
		int res = 1 << 20;
		do {
			string ns = "";
			for (int i = 0; i < s.size(); i += k) {
				for (int j = 0; j < k; j++) {
					ns += s[i + p[j]];
				}
			}
			ns += " ";
			int now = 0;
			char last = ' ';
			for (int i = 0; i < ns.size(); i++) {
				char ch = ns[i];
				if (last == ch) {
					// nop
				} else {
					last = ch;
					now++;
				}
			}
			now--;
			if (now < res) {
				res = now;
			}
		} while (next_permutation(p.begin(), p.end()));
		cout << "Case #" << tc << ": " << res << endl;
	}
}

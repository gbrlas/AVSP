#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream in("A-small.in");
	ofstream out("A-small.out");
	int T;
	int i;
	in >> T;
	string ignore;
	getline(in, ignore);
	for (i = 0; i < T; i++) {
		int char_map[26];
		int num_map[10];
		int k, base, replace, sum, mul;
		for (k = 0; k < 26; k++) {
			char_map[k] = -1;
		}
		for (k = 0; k < 10; k++) {
			num_map[k] = -1;
		}
		string line;
		getline(in, line);
		base = 0;
		replace = 1;
		for (k = 0; k < line.size(); k++) {
			char c = line.at(k);
			if (c >= 'a' && c <= 'z' && char_map[c - 'a'] == -1) {
				char_map[c - 'a'] = replace;
				base++;
				if (replace == 1) replace = 0;
				else if (replace == 0) replace = 2;
				else replace++;
			}
			if (c >= '0' && c <= '9' && num_map[c - '0'] == -1) {
				num_map[c - '0'] = replace;
				base++;
				if (replace == 1) replace = 0;
				else if (replace == 0) replace = 2;
				else replace++;
			}
		}
		if (base == 1) base = 2;
		sum = 0;
		mul = 1;
		for (k = line.size() - 1; k >= 0; k--) {
			char c = line.at(k);
			if (c >= 'a' && c <= 'z') {
				sum += char_map[c - 'a'] * mul;
			}
			if (c >= '0' && c <= '9') {
				sum += num_map[c - '0'] * mul;
			}
			mul = mul * base;
		}
		out << "Case #" << i + 1 << ": " << sum << endl;
	}
	return 0;
}

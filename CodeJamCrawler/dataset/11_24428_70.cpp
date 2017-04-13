/*
 * Magicka.cpp
 *
 */

#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
	map<pair<char, char> , char>::iterator it;
	map<pair<char, char> , char> combine;
	set<pair<char, char> > opposed;
	vector<char> file;
	int i, t, c, d, n;
	for (i = 1, cin >> t; i <= t; ++i) {
		// Combine
		for (cin >> c; c; --c) {
			char x, y, z;
			cin >> x >> y >> z;
			combine.insert(make_pair(make_pair(x, y), z));
			combine.insert(make_pair(make_pair(y, x), z));
		}
		// Opposed
		for (cin >> d; d; --d) {
			char x, y;
			cin >> x >> y;
			opposed.insert(make_pair(x, y));
			opposed.insert(make_pair(y, x));
		}
		// Elements
		for (cin >> n; n; --n) {
			char x;
			cin >> x;
			// Combine the two last elements
			if (not file.empty()) {
				it = combine.find(make_pair(x, file.back()));
				if (it != combine.end()) {
					file.back() = it->second;
					continue;
				}
			}
			// Push back the new element
			file.push_back(x);
			// Check for opposed elements
			for (int j = 0; j < (int) file.size(); ++j) {
				if (opposed.count(make_pair(x, file[j])))
					file.clear();
			}
		}
		// Print the result
		printf("Case #%d: [", i);
		if (not file.empty())
			printf("%c", file.front());
		for (int j = 1; j < (int) file.size(); ++j) {
			printf(", %c", file[j]);
		}
		printf("]\n");
		// Clear data
		combine.clear();
		opposed.clear();
		file.clear();
	}
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

void main() {
	ifstream cin("B-large.in");
	ofstream cout("output.txt");
	int t;
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		int c;
		cin >> c;
		vector<string> combines;
		for (int i = 0; i < c; ++i) {
			string combine;
			cin >> combine;
			combines.push_back(combine);
		}
		int d;
		cin >> d;
		vector<string> opposeds;
		for (int i = 0; i < d; ++i) {
			string opposed;
			cin >> opposed;
			opposeds.push_back(opposed);
		}
		int n;
		string invoke;
		cin >> n >> invoke;
		vector<char> list;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) {
			list.push_back(invoke[i]);
			++cnt[invoke[i] - 'A'];
			if (list.size() >= 2) {
				bool combined = false;
				for (int j = 0; j < c; ++j) {
					if (list[list.size() - 2] == combines[j][0] && list[list.size() - 1] == combines[j][1] ||
							list[list.size() - 2] == combines[j][1] && list[list.size() - 1] == combines[j][0]) {
						list.pop_back();
						list.pop_back();
						list.push_back(combines[j][2]);
						--cnt[combines[j][0] - 'A'];
						--cnt[combines[j][1] - 'A'];
						++cnt[combines[j][2] - 'A'];
						combined = true;
						break;
					}
				}
				if (!combined) {
					for (int j = 0; j < d; ++j) {
						if (cnt[opposeds[j][0] - 'A'] > 0 && cnt[opposeds[j][1] - 'A'] > 0) {
							list.clear();
							memset(cnt, 0, sizeof(cnt));
							break;
						}
					}
				}
			}
		}
		cout << "Case #" << tc + 1 << ": [";
		for (int i = 0; i < list.size(); ++i) {
			cout << list[i];
			if (i < list.size() - 1) cout << ", ";
		}
		cout << "]" << endl;
	}
}
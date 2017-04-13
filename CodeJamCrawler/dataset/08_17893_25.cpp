#include <algorithm>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <iostream>

#define foreach(i,s,w) for(int i=s;i<w.size();++i)
#define forX(i,m) for(typeof(m.begin())i=m.begin();i!=m.end();++i)

using namespace std;

string s;
vector <short> perm;
int k;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> k >> s;
		perm.clear();
		for(int i = 0; i < k; ++i)
			perm.push_back(i);
		int result = s.size();
		do {
			char last = '?';
			int res = 0;
			for(int block = 0; block * k < s.size(); ++block) {
				int start = block * k;
				for(int i = 0; i < k; ++i) {
					char c = s[start + perm[i]];
					if(last != c) {
						++res;
						last = c;
					}
				}
			}
			result <?= res;
		} while(next_permutation(perm.begin(), perm.end()));
		cout << "Case #" << (t + 1) << ": " << result << endl;
	}
	return 0;
}

#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <fstream>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)
#define cin sis
#define cout val

using namespace std;

int main() {
	ifstream sis("in.txt");
	ofstream val("out.txt");
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int N;
		cin >> N;
		vector <string> vs(N);
		foreach(i, 0, vs)
			cin >> vs[i];
		int result = 0;
		foreach(i, 0, vs) {
			foreach(j, i, vs) {
				int tt = count(vs[j].begin() + i + 1, vs[j].end(), '1');
				if(tt)
					continue;
				result += j - i;
				vs.insert(vs.begin() + i, vs[j]);
				vs.erase(vs.begin() + j + 1);
				break;
			}
		}
		cout << "Case #" << (t + 1) << ": " << result << endl;
	}
	sis.close();
	val.close();
	return 0;
}

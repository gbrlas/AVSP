#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main() {
	int T; cin >> T;
	for (int i=1; i<=T; i++) {
		int C; cin >> C;
		map<string, string> combines;
		for (int j=0; j < C; j++) {
			string s; cin >> s;
			combines.insert(make_pair(s.substr(0, 2), s.substr(2, 1)));
			combines.insert(make_pair(s.substr(1, 1) + s.substr(0, 1), s.substr(2, 1)));
		}
		int D; cin >> D;
		map<string, int> mp;
		mp["Q"] = 0;
		mp["W"] = 1;
		mp["E"] = 2;
		mp["R"] = 3;
		mp["A"] = 4;
		mp["S"] = 5;
		mp["D"] = 6;
		mp["F"] = 7;
		
		int exists[8];
		for (int j=0; j < 8; j++) exists[j] = 0;
		vector<int> oppose[8];
		for (int j=0; j < D; j++) {
			string O; cin >> O;
			oppose[mp[O.substr(0,1)]].push_back(mp[O.substr(1,1)]);
			oppose[mp[O.substr(1,1)]].push_back(mp[O.substr(0,1)]);
		}
		int l; cin >> l;
		string str; cin >> str;
		string res, tmp, next;
		for (int j=0; j < l; j++) {
			res += (next = str.substr(j, 1));
			exists[mp[next]]++;
			if (res.size() >= 2 && combines.find(tmp = res.substr(res.size()-2)) != combines.end()) {
				exists[mp[res.substr(res.size()-2, 1)]]--;
				exists[mp[res.substr(res.size()-1, 1)]]--;
				res = res.substr(0, res.size()-2) + combines[tmp];
			} else {
				for (int k=0; k < oppose[mp[next]].size(); k++) {
					if (exists[oppose[mp[next]][k]] > 0) {
						res = "";
						for (int m=0; m < 8; m++) exists[m] = 0;
						break;
					}
				}
			}
		}
		
		cout << "Case #" << i << ": [";
		for (int j=0; j < res.size(); j++) {
			cout << res[j];
			if (j != res.size()-1) cout << ", ";
		}
		cout << "]" << endl;
	}
	return 0;
}
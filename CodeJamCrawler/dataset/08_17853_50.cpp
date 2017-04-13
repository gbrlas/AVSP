#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int S, Q;
map <string, int> names;
vector <int> q;
map <pair <int, int>, int> mem;

int Solve(int pos, int engine) {
	if(pos == q.size())
		return 0;
	pair <int, int> key(pos, engine);
	if(mem.count(key))
		return mem[key];
	int result = 1000000;
	for(int i = 0; i < S; ++i) {
		if(q[pos] == i)
			continue;
		result <?= Solve(pos + 1, i) + (i != engine);
	}
	mem[key] = result;
	return result;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> S;
		names.clear();
		for(int i = 0; i < S; ++i) {
			scanf(" ");
			string s;
			getline(cin, s);
			names[s] = i;
		}
		cin >> Q;
		q.clear();
		for(int i = 0; i < Q; ++i) {
			scanf(" ");
			string s;
			getline(cin, s);
			q.push_back(names[s]);
		}
		int result = 1000000;
		mem.clear();
		for(int i = 0; i < S; ++i)
			result <?= Solve(0, i);
		cout << "Case #" << (t + 1) << ": " << result << endl;
	}
	return 0;
}

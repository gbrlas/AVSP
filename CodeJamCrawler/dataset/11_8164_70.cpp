#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int T; cin >> T;
	for (int i=1; i<=T; i++) {
		vector<string> seq;
		queue<int> B, O;
		cout << "Case #" << i << ": ";
		int n; cin >> n;
		for (int j=0; j<n; j++) {
			string who; cin >> who;
			int val; cin >> val;
			seq.push_back(who);
			if (who == "O") O.push(val);
			else if (who == "B") B.push(val);
		}
		int pos = 0, count = 0, bp = 1, op = 1;
		while(pos < seq.size()) {
			int bnext = (B.size() == 0 ? bp : B.front());
			int onext = (O.size() == 0 ? op : O.front());
			if (abs(bnext-bp) < abs(onext-op)) {
				count += abs(bnext-bp);
				op = onext + abs(onext-op) - abs(bnext-bp);
				bp = bnext;
			} else {
				count += abs(onext-op);
				bp = bnext + abs(bnext-bp) - abs(onext-op);
				op = onext;
			}

			if (seq[pos] == "B") {
				if (bp != bnext) {
					count += abs(bp-bnext);
					bp = bnext;
				}
				count++;
				pos++;
				B.pop();
				if (op != onext) {
					op = onext + abs(op-onext)-1;	
				}
			} else {
				if (op != onext) {
					count += abs(op-onext);
					op = onext;
				}
				count++;
				pos++;
				O.pop();
				if (bp != bnext) {
					bp = bnext + abs(bp-bnext)-1;	
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
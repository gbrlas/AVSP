#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


void Case()
{
	int S;
	cin >> S;
	while (cin.get() != '\n') {}
	map<string,int> namese;
	for (int i = 0; i < S; ++i) {
		string se;
		getline(cin, se);
		namese[se] = i;
	}
	vector<int> b(S,0); // best so far by cur. engine
	int Q;
	cin >> Q;
	while (cin.get() != '\n') {}
	for (int i = 0; i < Q; ++i) {
		string se;
		getline(cin, se);
		int n = namese[se];
		vector<int> c(S,999999999);
		for (int old = 0; old < S; ++old) {
			for (int new_ = 0; new_ < S; ++new_) {
				int cost = (new_ == n) ? 999999999 : b[old] + (old != new_);
				if (cost < c[new_])
					c[new_] = cost;
			}
		}
		b.swap(c);
	}
	int best = 999999999;
	for (int i = 0; i < S; ++i) {
		if (b[i] < best)
			best = b[i];
	}
	cout << best << "\n";
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cout << "Case #" << i << ": ";
		Case();
	}
}

#include <iostream>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
	int t; cin >> t;
	for (int c = 1; c <= t; c++) {
		int n,x; cin >> n >> x;
		multiset<int> files;
		for (int i = 0; i < n; i++) {
			int si; cin >> si;
			files.insert(-si);
		}
		int disks = 0;
		int size = n;
		assert(files.size() == size);
		while (!files.empty()) {
			assert(files.size() == size);
			int a = *files.begin();
			files.erase(files.begin());
			size--;
			assert(files.size() == size);
			int b = x+a; //capacity left on disk
			multiset<int>::iterator it = lower_bound(files.begin(),files.end(),-b);
			if (it != files.end()) {
				files.erase(it);
				size--;
			}
			disks++;
			assert(files.size() == size);
		}
		assert(size==0);
		cout << "Case #" << c << ": " << disks << endl;
	}
	return 0;
}

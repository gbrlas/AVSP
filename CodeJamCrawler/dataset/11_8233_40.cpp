#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int TTT; cin >> TTT;
	for (int ZZZ=1;ZZZ<=TTT;ZZZ++) {
		long long N, L, H; cin >> N >> L >> H;
		
		bool possible[10000];
		
		for (int i=L-1; i < H; i++) possible[i] = true;
		
		for (int i=0; i < N; i++) {
			int next; cin >> next;
			for (int j=L-1; j < H; j++) {
				if ((j+1)%next != 0 && next%(j+1) != 0) {
					possible[j] = false;
				}
			}
		}
		
		bool has = false;
		int min = 0;
		for (int i=L-1;i<H;i++) if (possible[i]) {
			has=true;
			min = i+1;
			break;
		}
		
		cout << "Case #" << ZZZ << ": ";
		
		if (!has) cout << "NO" << endl;
		else cout << min << endl;
	}
}
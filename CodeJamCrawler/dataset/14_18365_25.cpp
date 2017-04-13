//============================================================================
// Name        : Qual_A.cpp
// Author      : Peiqian Li
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int nc;
	int a[4][4], b[4][4];
	int ra, rb;
	cin >> nc;
	for(int cid=1; cid<=nc; ++cid) {
		cin >> ra;
		--ra;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				cin >> a[i][j];
		cin >> rb;
		--rb;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				cin >> b[i][j];
		bool exists[17] = {0};
		for(int i=0;i<4;++i) exists[a[ra][i]] = true;
		int count = 0, ans = 0;
		for(int i=0;i<4;++i)
			if(exists[b[rb][i]]) {
				++count;
				ans = b[rb][i];
			}
		cout << "Case #" << cid << ": ";
		if (count>1) cout << "Bad magician!" << endl;
		else if(count == 1) cout << ans << endl;
		else cout << "Volunteer cheated!" << endl;
	}
	return 0;
}

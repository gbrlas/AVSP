#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
//#define LARGE 1

int a1[4][4], a2[4][4];

int main() {
#ifdef LARGE
	freopen("a_large.i", "rt", stdin);
	freopen("a_large.o", "wt", stdout);
#elif SMALL
	freopen("a_small.i", "rt", stdin);
	freopen("a_small.o", "wt", stdout);
#else
	freopen("a_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int r1, r2;
		cin>>r1;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin>>a1[i][j];
		cin>>r2;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin>>a2[i][j];
		r1--;
		r2--;
		sort(a1[r1], a1[r1]+4);
		sort(a2[r2], a2[r2]+4);
		vector<int> v(4);
		int cnt = set_intersection(a1[r1], a1[r1]+4, a2[r2], a2[r2]+4, v.begin())-v.begin();
		cout << "Case #" << tt << ": ";
		if(cnt > 1) {
			cout << "Bad magician!" << endl;
		} else if (cnt == 0) {
			cout << "Volunteer cheated!" << endl;
		} else {
			cout << v[0] << endl;
		}
	}

	return 0;
}

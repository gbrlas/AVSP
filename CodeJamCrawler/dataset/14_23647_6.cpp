# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <deque>
# include <cassert>
# define inf 1000000007
using namespace std;
typedef unsigned long long int ulli;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("../A-small-attempt1.in","r",stdin);
        freopen("../output.txt", "w", stdout);
    #endif
	int r1,r2,t;
	scanf("%d", &t);
	int a[4][4], b[4][4];
	for(int k=1;k<=t;k++) {
		scanf("%d", &r1);
		r1--;

		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) 
				scanf("%d", &a[i][j]);
		}

		scanf("%d", &r2);
		r2--;

		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				scanf("%d", &b[i][j]);
			}
		}

		int count = 0, res;
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				if(a[r1][i] == b[r2][j]) {
					count++;
					res = a[r1][i];
				}
			}
		}
		printf("Case #%d: ", k);
		if(count == 1) {
			printf("%d\n", res);
		} else if(count == 0) {
			printf("Volunteer cheated!\n");
		} else {
			printf("Bad magician!\n");
		}
	}

    return 0;
}

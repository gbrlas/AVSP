#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		vector<int> v;
		for (int z=0;z<2;z++){
			int x;
			scanf("%d",&x);
			for(int i=1;i<=4;++i){
				for(int j=0;j<4;j++){
					int y;
					scanf("%d",&y);
					if(i==x)v.push_back(y);
				}
			}
		}
		sort(v.begin(),v.end());
		//for(int i=0;i<8;++i)printf("%d ",v[i]);
		//puts("");
		int res = 0;
		for(int i=1;i<8;i++){
			if(v[i]==v[i-1]){
				res = (res?-1:v[i]);
			}
		}
		if(res<0) printf("Case #%d: Bad magician!\n", tt);
		else if(res>0) printf("Case #%d: %d\n", tt,res);
		else printf("Case #%d: Volunteer cheated!\n",tt);
	}
}

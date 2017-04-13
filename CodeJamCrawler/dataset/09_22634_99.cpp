#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int R,C,map[105][105],dirx[] = {0,-1,0,0,1}, diry[] = {0,0,-1,1,0},sink[100][100],ans[100][100];

inline bool isvalid(int x,int y) {
	if(x>=0 && x<R && y>=0 && y<C)
		return true;
	return false;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++) {
		scanf("%d %d",&R,&C);
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				scanf("%d",&map[i][j]);
		printf("Case #%d:\n",t);
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++) {
				vector< pair<int, int> > v;
				v.push_back(make_pair(map[i][j],0));
				for(int k=1;k<5;k++)
					if(isvalid(i+dirx[k],j+diry[k]))
						v.push_back(make_pair(map[i+dirx[k]][j+diry[k]],k));
				sort(v.begin(),v.end());
				sink[i][j] = v[0].second;
			}
		memset(ans,0,sizeof(ans));
		bool fl = true;
		int x=0,y=0;
		int cnt=0;
		while(fl) {
			queue<int> qx,qy;
			while(sink[x][y] != 0) {
				int d = sink[x][y];
				x = x+dirx[d];
				y = y+diry[d];
			}
			ans[x][y] = cnt+'a';
			qx.push(x);
			qy.push(y);
			while(!qx.empty()) {
				int topx = qx.front(), topy = qy.front();
				qx.pop();
				qy.pop();
				for(int k=1;k<5;k++) {
					if(isvalid(topx+dirx[k],topy+diry[k])){
						int s = sink[topx+dirx[k]][topy+diry[k]];
						if(dirx[k]+dirx[s] == 0 && diry[k]+diry[s] == 0 && ans[topx+dirx[k]][topy+diry[k]]==0) {
							ans[topx+dirx[k]][topy+diry[k]] = cnt+'a';
							qx.push(topx+dirx[k]);
							qy.push(topy+diry[k]);
						}
					}
				}
			}
			cnt++;
			fl = false;
			for(int i=0;i<R;i++) {
				for(int j=0;j<C;j++){
					if(ans[i][j]==0){
						x=i;
						y=j;
						fl = true;
						break;
					}
				}
				if(fl) break;
			}
		}
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				printf("%c ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}

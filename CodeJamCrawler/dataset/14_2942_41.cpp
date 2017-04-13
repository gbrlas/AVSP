#include<iostream>
using namespace std;

const int maxw = 110;
const int maxh = 510;

int flow[maxh][maxw][10];
bool badcell[maxh][maxw];
int innerflow[maxh][maxw];

int w,h,b;
bool mark[maxh][maxw][2];

int isvalid(int x, int y) {
	return y>0 && x>=0 && x<w && !badcell[y][x];
}

int dfs(int x, int y, int node) {
	if(mark[y][x][node])
		return 0;
	mark[y][x][node] = 1;
	if (y==h-1)
		return 1;
	int xn,yn;
	if (node == 0) {
		xn=x; yn=y-1;
		if (innerflow[y][x]==0 && isvalid(xn,yn) && flow[y][x][4]==0) {
			if (dfs(xn, yn, 0)) {
				flow[y][x][4] = 1;
				flow[yn][xn][3] = 1;
				innerflow[y][x] = 1;
				return 1;
			}
		}
		if (isvalid(xn,yn) && flow[y][x][0]>0) {
			if (dfs(xn, yn, 1)) {
				flow[y][x][0] = 0;
				flow[yn][xn][7] = 0;
				return 1;
			}
		}

		xn=x; yn=y+1;
		if (innerflow[y][x]==0 && isvalid(xn,yn) && flow[y][x][7]==0) {
			if (dfs(xn, yn, 0)) {
				flow[y][x][7] = 1;
				flow[yn][xn][0] = 1;
				innerflow[y][x] = 1;
				return 1;
			}
		}
		xn=x; yn=y+1;
		if (isvalid(xn,yn) && flow[y][x][3]>0) {
			if (dfs(xn, yn, 1)) {
				flow[y][x][3] = 0;
				flow[yn][xn][4] = 0;
				return 1;
			}
		}

		xn=x-1; yn=y;
		if (innerflow[y][x]==0 && isvalid(xn,yn) && flow[y][x][6]==0) {
			if (dfs(xn, yn, 0)) {
				flow[y][x][6] = 1;
				flow[yn][xn][1] = 1;
				innerflow[y][x] = 1;
				return 1;
			}
		}
		xn=x-1; yn=y;
		if (isvalid(xn,yn) && flow[y][x][2]>0) {
			if (dfs(xn, yn, 1)) {
				flow[y][x][2] = 0;
				flow[yn][xn][5] = 0;
				return 1;
			}
		}

		xn=x+1; yn=y;
		if (innerflow[y][x]==0 && isvalid(xn,yn) && flow[y][x][5]==0) {
			if (dfs(xn, yn, 0)) {
				flow[y][x][5] = 1;
				flow[yn][xn][2] = 1;
				innerflow[y][x] = 1;
				return 1;
			}
		}
		xn=x+1; yn=y;
		if (isvalid(xn,yn) && flow[y][x][1]>0) {
			if (dfs(xn, yn, 1)) {
				flow[y][x][1] = 0;
				flow[yn][xn][6] = 0;
				return 1;
			}
		}
	} else { // node == 1
		xn=x; yn=y-1;
		if (isvalid(xn,yn) && flow[y][x][4]==0) {
			if (dfs(xn, yn, 0)) {
				flow[y][x][4] = 1;
				flow[yn][xn][3] = 1;
				return 1;
			}
		}
		if (innerflow[y][x]==1 && isvalid(xn,yn) && flow[y][x][0]>0) {
			if (dfs(xn, yn, 1)) {
				flow[y][x][0] = 0;
				flow[yn][xn][7] = 0;
				innerflow[y][x] = 0;
				return 1;
			}
		}

		xn=x; yn=y+1;
		if (isvalid(xn,yn) && flow[y][x][7]==0) {
			if (dfs(xn, yn, 0)) {
				flow[y][x][7] = 1;
				flow[yn][xn][0] = 1;
				return 1;
			}
		}
		xn=x; yn=y+1;
		if (innerflow[y][x]==1 && isvalid(xn,yn) && flow[y][x][3]>0) {
			if (dfs(xn, yn, 1)) {
				flow[y][x][3] = 0;
				flow[yn][xn][4] = 0;
				innerflow[y][x] = 0;
				return 1;
			}
		}

		xn=x-1; yn=y;
		if (isvalid(xn,yn) && flow[y][x][6]==0) {
			if (dfs(xn, yn, 0)) {
				flow[y][x][6] = 1;
				flow[yn][xn][1] = 1;
				return 1;
			}
		}
		xn=x-1; yn=y;
		if (innerflow[y][x]==1 && isvalid(xn,yn) && flow[y][x][2]>0) {
			if (dfs(xn, yn, 1)) {
				flow[y][x][2] = 0;
				flow[yn][xn][5] = 0;
				innerflow[y][x] = 0;
				return 1;
			}
		}

		xn=x+1; yn=y;
		if (isvalid(xn,yn) && flow[y][x][5]==0) {
			if (dfs(xn, yn, 0)) {
				flow[y][x][5] = 1;
				flow[yn][xn][2] = 1;
				return 1;
			}
		}
		xn=x+1; yn=y;
		if (innerflow[y][x]==1 && isvalid(xn,yn) && flow[y][x][1]>0) {
			if (dfs(xn, yn, 1)) {
				flow[y][x][1] = 0;
				flow[yn][xn][6] = 0;
				innerflow[y][x] = 0;
				return 1;
			}
		}

	}
	return 0;
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		cin>>w>>h>>b;
		memset(flow, 0, sizeof flow);
		memset(innerflow, 0, sizeof innerflow);
		memset(badcell, 0 , sizeof badcell);
		for(int i=0;i<b;i++) {
			int x0,y0,x1,y1;
			cin>>x0>>y0>>x1>>y1;
			for(int i=x0;i<=x1;i++)
				for(int j=y0;j<=y1;j++) {
					badcell[j][i] = 1;
				}
		}
		int ans = 0;
		for(int i=0;i<w;i++) {
			memset(mark, 0 , sizeof mark);
			if (!badcell[0][i]) {
				ans += dfs(i, 0, 0);
			}
		}
		cout<<"Case #"<<tn+1<<": "<<ans<<endl;

	}
}

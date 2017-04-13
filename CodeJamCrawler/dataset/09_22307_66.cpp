//#include <stdio.h>
#include <io.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>

using namespace std;
#define NORTH 0
#define WEST  1
#define EAST  2
#define SOUTH 3
#define NONE  4
#define ALPHA 128
#define H 100
#define W 100
#define INF (unsigned int)((unsigned int)(-1)>>2)

template <typename T>
struct node {
	T ht;
	T x;
	T y;
	node (){x=y=ht=0;}
	node (T h,T a,T b) {ht = h;x=a;y=b;}
};
node<int> alt[H][W];
queue< node<int> >que;
bool vis[H][W];
char tab[H][W];

int n;
int row,col;

int direct[8] = {//north->west->east->south
	-1,0, 0,-1, 0,1, 1,0
};
#define bound(x, y) (x < 0 || x >= row || y < 0 || y >= col)

bool inflow (int x, int y, int a, int b) {
	int min = INF;
	int dir = NONE;
	int ht = alt[x][y].ht;
	for (int k = 0; k < 4; k++) {
		int u = x+direct[k*2];
		int v = y+direct[k*2+1];
		if (!bound(u, v) && alt[u][v].ht < ht && min > alt[u][v].ht)
			dir = k,
			min = alt[u][v].ht;
	}
	if (dir == NONE) return false;
	return (x+direct[dir*2]==a && y+direct[dir*2+1]==b);
}
void BFS() {
	for (int j = 0; j < row; j++)
		for (int i = 0; i < col; i++)
			vis[j][i] = false;

	char alpha = 'a';
	for (int i = 0; i < row; i++)
	for (int j = 0; j < col; j++)
	{
		if (vis[i][j] == false) {
			vis[i][j] = true;
			tab[i][j] = alpha;
			que.push(alt[i][j]);
			while (que.empty() == false) {

				node<int>v = que.front(); que.pop();
				// find in four derection
				// seqence: north->west->east->south
				int min = alt[v.x][v.y].ht, po = NONE;

				for (int k = 0; k < 4; k++) {//流入
					int x = v.x+direct[k*2];
					int y = v.y+direct[k*2+1];
					if (!bound(x, y)) {
						//计算流出最小值
						if (min > alt[x][y].ht)
							min = alt[x][y].ht,
							 po = k;
						//追加可流入点
						if (vis[x][y] == false && inflow(x, y, v.x, v.y) == true)
							vis[x][y] = true,
							tab[x][y] = alpha,
							que.push(alt[x][y]);
					}
				}
				if (po != NONE)//流出 outflow
				{	
					int x = v.x+direct[po*2];
					int y = v.y+direct[po*2+1]; 
					if (vis[x][y] == false)
						vis[x][y] = true,
						tab[x][y] = alpha,
						que.push(alt[x][y]);
				}
			}	//end while
			alpha++;
		}
	}
}
void solve(int id) {
	cout<<"Case #"<<id+1<<":"<<endl;
	for (int i = 0; i < row; i++,cout<<endl)
		for (int j = 0; j < col; j++)
			cout<<tab[i][j]<<" ";
}
void main() {
	ifstream infile("B-small-attempt1.in.txt");
	streambuf *inbuf = cin.rdbuf(infile.rdbuf());

	ofstream outfile("B-small-attempt1.out.txt");
	streambuf *outbuf = cout.rdbuf(outfile.rdbuf());
	
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>row>>col;
		int pn = 0;
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++) 
				cin>>alt[j][k].ht,
				alt[j][k].x = j,
				alt[j][k].y = k;
		BFS();
		solve(i);
	}
	 
	cin.rdbuf(inbuf);
	infile.close();

	cout.rdbuf(outbuf);
	outfile.close();
}
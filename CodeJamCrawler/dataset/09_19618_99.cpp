#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<iterator>
#include<streambuf>
#include<sstream>
#include<list>
#include<stack>
#include<ostream>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dx[]={-1, 0,0,1};
int dy[]={ 0,-1,1,0};
int H,W;
const int MAX=105;
int arr[MAX][MAX];
bool ishigher(int x,int y,int x1,int y1){
	if(x<0 or y<0 or x1 <0 or y1<0 ) return false;
	if(x>=H or x1>=H or y>=W or y1>=W) return false;
	if(arr[x][y]<=arr[x1][y1]) return false;
	return true;
}
bool islower(int x,int y,int x1,int y1){
	if(x<0 or y<0 or x1 <0 or y1<0 ) return false;
	if(x>=H or x1>=H or y>=W or y1>=W) return false;
	if(arr[x][y]>=arr[x1][y1]) return false;
	return true;
}

bool findlowest(int x,int y,int &sx,int &sy){
	int i=0,val=30000;
	for(i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(islower(nx,ny,x,y)){
			if(arr[nx][ny]<val){
				val=arr[nx][ny];
				sx=nx;
				sy=ny;
			}
		}
	}
	if(val==30000) { sx=sy=-1; return false;}
	return true;
}

struct node{
	int x,y;
	node(int p,int q):x(p),y(q){}
	node(){x=y=-1; }
};

char visit[MAX][MAX];

bool isgood(int x,int y){
	if(x<0 or y<0 or x>=H or y>=W) return false;
	if(visit[x][y]) return false;
	return true;
}

/* check if there is a path from x,y -> x1,y1 */
void dfs(int x,int y,int val){
	
	int i;
	visit[x][y]=val;
	for(i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		//printf("DBG:%d,%d->%d,%d\n",x,y,nx,ny);
		if(isgood(nx,ny) ){
		//	printf("YES\n");
			int tx,ty;
			tx=ty=-1;
			findlowest(nx,ny,tx,ty);
			{
		//		printf("find lowest returned (%d,%d)->%d,%d\n",nx,ny,tx,ty);
				if((tx==x) and (ty==y)){
					dfs(nx,ny,val);
				}
			}
		}
	}
	return;
}

void bfs(int x,int y,char val){
	int tx,ty,cx,cy,i;
	tx=x,ty=y;
	cx=cy=-1;
	visit[tx][ty]=val;
	vector<node> v;
	v.push_back(node(tx,ty));
	while(findlowest(tx,ty,cx,cy)){
			v.push_back(node(cx,cy));
			visit[cx][cy]=val;
			tx=cx;
			ty=cy;
	}
	for(i=0;i<v.size();i++){ 	
		//printf("debug:%d,%d\n",v[i].x,v[i].y);
		dfs(v[i].x,v[i].y,val);
	}
}

int main(){
	int i,j,tc=1,no;
	scanf(" %d",&no);
	while(no--){
		memset(visit,0,sizeof(visit));
		memset(arr,0,sizeof(arr));
		scanf(" %d %d",&H,&W);
		for(i=0;i<H;i++)
		for(j=0;j<W;j++) scanf(" %d",&arr[i][j]);
		char ch='a';
		for(i=0;i<H;i++)
		for(j=0;j<W;j++){
			if(visit[i][j]) continue;
			bfs(i,j,ch++);
			if(ch>'z') ch='z';
		//	goto fail;
		}
fail:
		printf("Case #%d:\n",tc++);
		for(i=0;i<H;i++){
		for(j=0;j<W-1;j++) printf("%c ",visit[i][j]);
		printf("%c\n",visit[i][j]);
		}
	}
	return 0;
}


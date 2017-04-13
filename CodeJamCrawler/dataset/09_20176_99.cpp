//
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int W,H,n;
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};
int data[100][100];
int debug[100][100];
char board[100][100];
char real[100][100];
int cnt;
void init() {
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++) {
			int x,y;
			int rec;
	                int tmp=data[i][j];
			for(int k=0;k<4;k++){
				x=j+dx[k],y=i+dy[k];
				if(x<W&&x>=0&&y<H&&y>=0&&data[y][x]<tmp) {
						tmp=data[y][x],rec=k;
				}
				if(tmp<data[i][j]) {
					debug[i][j]=rec;
				}
			}
		}
}
void dfs(int i,int j) {
	  int x,y;
	  for(int k=0;k<4;k++){
		  x=j+dx[k],y=i+dy[k];
		  if( x>=0&&x<W&&y>=0&&y<H ) {
			  if(debug[y][x]+k==3)
				  board[y][x]=board[i][j],dfs(y,x);
		  }
	  }
	   
}
void dfs2(int i,int j) {
          int x,y;
	  real[i][j]='a'+cnt;
	  for(int k=0;k<4;k++){
		  x=j+dx[k],y=i+dy[k];
		  if( x>=0&&x<W&&y>=0&&y<H ) {
			  if(board[i][j]==board[y][x]&&real[y][x]==0) dfs2(y,x);
		  }
	  }
}

int main() {
	scanf("%d",&n);
	for(int q=1;q<=n;q++) {
		scanf("%d%d",&H,&W);
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++) scanf("%d",&data[i][j]);
		memset(board,0,sizeof(board));
		memset(debug,-1,sizeof(debug));
		init();
		cnt=0;
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++) {
			if(debug[i][j]<0){
                                        board[i][j]='a'+(cnt++);
					dfs(i,j);
			}
		}
		memset(real,0,sizeof(real));
		cnt=0;
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++) {
			if(!real[i][j]){
                                       
					dfs2(i,j);
					cnt++;
			}
		} 
		printf("Case #%d:\n",q);
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(j) printf(" ");
				printf("%c",real[i][j]);
				
			}
			printf("\n");
		}
	}
}


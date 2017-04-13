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
void flood() {
	  
	  for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
	        if(board[i][j]&&debug[i][j]>=0)       
		    {
                        int x,y;
						y=i+dy[debug[i][j]],x=j+dx[debug[i][j]];
						if(y>=0&&x>=0) {
						board[y][x]=board[i][j];
			}
		
		}
		else if(debug[i][j]>=0){
			int x,y;
			y=i+dy[debug[i][j]],x=j+dx[debug[i][j]];
			if(board[y][x]) {
				board[i][j]=board[y][x];
			}
		}
	    else if(!board[i][j]) board[i][j]='a'+(cnt++);
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
				{
					
					flood();
			}
		}
		printf("Case #%d:\n",q);
		if(board[0][0]=='b') 
           for(int i=0;i<H;i++)
			   for(int j=0;j<W;j++)
				   if(board[i][j]=='a') board[i][j]='b';
				   else board[i][j]='a';

		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(j) printf(" ");
				printf("%c",board[i][j]);
			}
			printf("\n");
		}
	}
}


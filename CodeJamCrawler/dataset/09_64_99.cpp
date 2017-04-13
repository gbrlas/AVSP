#include <stdio.h>

#define EAST 1
#define SOUTH 2
#define WEST 3
#define NORTH 4

int value[5] = {0, 1, 2, 4, 8};
int antid[5] = {0, WEST, NORTH, EAST, SOUTH};
int js[5] = {0, 0, 1, 0, -1};
int ks[5] = {0, 1, 0, -1, 0};

int H, W;
int board[101][101];
char graph[101][101];
char result[101][101];

int stackj[10001];
int stackk[10001];
int top;
void push(int j, int k){
	++top;
	stackj[top] = j;
	stackk[top] = k;	
}

void pop(int& j, int& k){	
	j = stackj[top];
	k = stackk[top];	
	--top;
}

void dfs(int j, int k, char ch){
	int i, nextj, nextk;
	top = 0;
	push(j, k);
	result[j][k] = ch;
	while(0 < top){
		pop(j, k);
		for(i = 1; i <= 4; ++i){
			if ((graph[j][k] & value[i]) > 0){
				nextj = j + js[i];
				nextk = k + ks[i];
				if (result[j + js[i]][k + ks[i]]==0){
					push(j+js[i], k + ks[i]);
					result[j + js[i]][k + ks[i]] = ch;
				}
			}
		}
	}
}

int main(){
	int T, i, j, k, d, min, minj, mink;
	char ch = 'a';
	scanf("%d", &T);
	for(i = 1; i <= T; ++i){
		scanf("%d%d", &H, &W);
		for(j = 0; j < H; ++j){
			for(k = 0; k < W; ++k){
				scanf("%d", &(board[j][k]));
				result[j][k] = 0;
				graph[j][k] = 0;
			}			
		}
		for(j = 0; j < H; ++j)
			for(k = 0; k < W; ++k){
				d = 0;
				min = board[j][k];
				// NORTH
				if (j > 0 && min > board[j-1][k]){
					min = board[j-1][k];
					d = NORTH;
				}
				//WEST
				if (k > 0 && min > board[j][k-1]){
					min = board[j][k-1];
					d = WEST;
				}
				//EAST
				if (k < W-1 && min > board[j][k+1]){
					min = board[j][k+1];
					d = EAST;
				}
				//SOUTH
				if (j < H-1 && min > board[j+1][k]){
					min = board[j+1][k];
					d = SOUTH;
				}
				if(d >0){
					graph[j][k] |= value[d];
					graph[j + js[d]][k + ks[d]] |= value[antid[d]];
				}
			}
		//dfs		
		ch = 'a';
		for(j = 0; j < H; ++j)
			for(k = 0; k < W; ++k){
				if (result[j][k] == 0){
					dfs(j,k , ch);
					++ch;
				}
			}
		printf("Case #%d:\n", i);
		for(j = 0; j < H; ++j)
			for(k = 0; k < W; ++k){
				printf("%c", result[j][k]);
				if (k < W-1)
					printf(" ");
				else
					printf("\n");
			}
	}
}
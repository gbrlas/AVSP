#include<iostream>
using namespace std;
#define MAXALTITUDE 10000
int arr[102][102],prev[102][102];
char basin[102][102];
int T, H, W;
void mark(int pre, char col){
  if(pre == -1)
	return;
  basin[pre/(1+W)][pre%(1+W)] = col;
  mark(prev[pre/(1+W)][pre%(1+W)], col);
}

int sink(int val, int r, int c){
  if(arr[r-1][c] >= val && arr[r][c-1] >= val && arr[r][c+1] >= val && arr[r+1][c] >= val)
	return 1;
  
  else
	return 0;
}
int main(){
  int i,k,m,n;
  int kase,minAlt, minR, minC,flag;
  
  char basinChar;
  scanf("%d",&T);
  for(kase=1;kase<=T;kase++){
	scanf("%d %d",&H,&W);
	for(i=0;i<=W+1;i++){
	  arr[0][i] = MAXALTITUDE;
	  arr[H+1][i] = MAXALTITUDE;
	}
	for(i=0;i<=H+1;i++){
	  arr[i][0] = MAXALTITUDE;
	  arr[i][W+1] = MAXALTITUDE;
	}
	for(i=1;i<=H;i++)
	  for(k=1;k<=W;k++){
		scanf("%d",&arr[i][k]);
		basin[i][k] = 0;
		prev[i][k] = -1;
	  }
	basinChar = 'a';  
	for(m=1;m<=H;m++){
	  for(n=1;n<=W;n++){
		if(basin[m][n])
		  continue;
		flag = 0;
		i = m;
		k = n;
		while(!sink(arr[i][k], i, k)){
		  minAlt = arr[i-1][k];
		  minR = i-1;
		  minC = k;
		  if(arr[i][k-1] < minAlt){
			minAlt = arr[i][k-1];
			minR = i;
			minC = k-1;
		  }
		  if(arr[i][k+1] < minAlt){
			minAlt = arr[i][k+1];
			minR = i;
			minC = k+1;
		  }
		  if(arr[i+1][k] < minAlt){
			minAlt = arr[i+1][k];
			minR = i+1;
			minC = k;
		  }
		  prev[minR][minC] = i*(1+W) + k;
		  i = minR;
		  k = minC;
		  if(basin[i][k]){
			mark(prev[i][k], basin[i][k]);
			flag = 1;
			break;
		  }
		}
		if(!flag){
		  mark(i*(1+W) + k,basinChar);
		  basinChar++;
		}
	  }
	}
	printf("Case #%d:\n",kase);
	for(i=1;i<=H;i++){
	  for(k=1;k<=W;k++)
		printf("%c ",basin[i][k]);
	  printf("\n");
	}
  }
  return 0;
}

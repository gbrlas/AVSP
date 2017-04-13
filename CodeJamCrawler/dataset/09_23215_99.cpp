#include <stdio.h>
#include <iostream>

using namespace std;

#define MAXN 123

char curr_char;
int b[MAXN][MAXN];
char vis[MAXN][MAXN];
int h, w;

int ok(int i, int j){
  return i>=0 && i<h && j>=0 && j<w;
}

char dfs(int i, int j){

  if (vis[i][j] != -1)
    return vis[i][j];

  int di[] = {-1, 0, 0, 1};
  int dj[] = {0, -1, 1, 0};

  int minh = b[i][j];
  int minr = -1;
  for(int r=0; r<4; r++){
    
    int i2 = di[r] + i;
    int j2 = dj[r] + j;

    if (ok(i2, j2) && minh > b[i2][j2]){
      minh = b[i2][j2];
      minr = r;
    }
  }

  //sink
  if (minr == -1){
    vis[i][j] = curr_char++;
  }
  else {
    vis[i][j] = dfs(i + di[minr], j + dj[minr]);
  }
  return vis[i][j];
}

int main (){
  
  int t, cases = 1;
  scanf("%d", &t);
  
  while (t--){
    scanf("%d %d", &h, &w);

    for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
	scanf("%d", &b[i][j]);

    for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
	vis[i][j] = -1;

    curr_char = 'a';

     for (int i=0; i<h; i++)
       for (int j=0; j<w; j++)
	 dfs(i, j);

    printf("Case #%d:\n", cases++);
    for (int i=0; i<h; i++){
      for (int j=0; j<w; j++){
	if (j) printf(" ");
	printf("%c", vis[i][j]);
      }
      printf("\n");
    }
    
  }
  
  return 0;
}

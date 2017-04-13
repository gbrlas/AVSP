#include <stdio.h>
#include <iostream>

using namespace std;

#define MAXN 500

int x, y, dir;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int mapa[MAXN+2][MAXN+2];
int fim[MAXN+2][MAXN+2];

void processa(char *str){

  for (int i=0; str[i]; i++){
    if (str[i] == 'F'){
      x+=dx[dir];
      y+=dy[dir];
      mapa[y*2][x*2] = 1;
      mapa[y*2 - dy[dir]][x*2 - dx[dir]] = 1;
    }
    else if (str[i] == 'R' ) dir = (dir + 1) % 4;
    else dir = (dir + 3) % 4;

  }
}
void flood (int i, int j){

  if (i < 0 || i == MAXN || j < 0 || j == MAXN) return;
  if (mapa[i][j] != 0) return;
  mapa[i][j] = 2;
  for (int r=0; r<4; r++)
    flood(i+dy[r], j+dx[r]);
}

int main (){

  char str[1000];
  int t, len, cases = 1;
  scanf("%d",&t);

  while(t--){
    
    int n;
    scanf("%d",&n);

    x = y = MAXN/4;
    dir = 0;
    memset(mapa,0,sizeof(mapa));
    memset(fim,0,sizeof(fim));
    for (int i=0; i<n; i++){
      scanf("%s %d",str, &len);

      //printf("%s",str);
      for (int j=0; j<len; j++){
	processa(str);
      }
    }
    flood(0,0);

    for (int i=0; i<MAXN; i++)   
      for (int j=0; j<MAXN; j++)
	if (mapa[i][j] == 0) mapa[i][j] = 1;

    for (int i=0; i<MAXN; i++){
      
      int alt = 0;
      int prev = 2;
      for (int j=0; j<MAXN; j++){
	if (prev != mapa[i][j]){
	  prev = mapa[i][j];
	  alt++;
	}
	//printf("%d",mapa[i][j]);
      }
      //printf("\n");
      prev = 2;
      int alt2 = 0;
      for (int j=0; j<MAXN; j++){
	if (prev != mapa[i][j]){
	  prev = mapa[i][j];
	  alt2++;
	}
	if (alt2 > 0 && alt2 < alt && alt2 % 2 == 0)
	  fim[i][j] = 3;
      }
    }

    for (int i=0; i<MAXN; i++){
      
      int alt = 0;
      int prev = 2;
      for (int j=0; j<MAXN; j++){
	if (prev != mapa[j][i]){
	  prev = mapa[j][i];
	  alt++;
	}
      }
      prev = 2;
      int alt2 = 0;
      for (int j=0; j<MAXN; j++){
	if (prev != mapa[j][i]){
	  prev = mapa[j][i];
	  alt2++;
	}
	if (alt2 > 0 && alt2 < alt && alt2 % 2 == 0)
	  fim[j][i] = 3;
      }
    }
    int sum = 0;
    for(int i=1; i<MAXN; i+=2){
      for(int j=1; j<MAXN; j+=2){
	//printf("%d",fim[i][j]);
	if (fim[i][j] == 3) sum++;
      }
      //printf("\n");
    }

    printf("Case #%d: %d\n",cases++,sum);
  }
  
  return 0;
}

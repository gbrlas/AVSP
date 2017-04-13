#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define INF 1000000000
#define pii pair<int,int>

using namespace std;

int tc,r,c,i,j,cnt;
int A[300][300];
int visited[300][300];
int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};

int DFS(int y, int x){
   if (visited[y][x] != 0) return visited[y][x];
   int minx = 0, miny = 0, lowest = INF;
   for (int i = 0; i < 4; i++){
      int newx = dx[i]+x, newy = dy[i]+y; 
      if (A[newy][newx] < lowest){
         lowest = A[newy][newx];
         minx = newx; miny = newy;
      }
   }
   //printf("%d\n",lowest);
   if (lowest >= A[y][x]){
      visited[y][x] = cnt;
      cnt++;
      return cnt-1;
   }else{
      int color = DFS(miny, minx);
      visited[y][x] = color;
      return color;
   }
}

int main(){
   scanf("%d ",&tc);
   for (int TC = 1; TC <= tc; TC++){
      scanf("%d %d ",&r,&c);
      for (i = 1; i <= r; i++) for (j = 1; j <= c; j++) scanf("%d ",&A[i][j]);
      for (i = 0; i <= c+1; i++){
         A[0][i] = INF; A[r+1][i] = INF;
      }
      for (i = 0; i <= r+1; i++){
         A[i][0] = INF; A[i][c+1] = INF;
      }
      memset(visited,0,sizeof(visited));
      cnt = 1;
      for (i = 1; i <= r; i++) for (j = 1; j <= c; j++){
         if (visited[i][j] == 0) visited[i][j] = DFS(i,j);
      }
      printf("Case #%d:\n",TC);
      for (i = 1; i <= r; i++){
         for (j = 1; j <= c; j++){
            if (j != 1) printf(" ");
            printf("%c",visited[i][j]+'a'-1);
         }
         printf("\n");
      }
   }
   return 0;
}


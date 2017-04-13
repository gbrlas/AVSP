#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory>
#include <cmath>
#include <numeric>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define MST(G, x) memset(G,x,sizeof(G))
#define FOR(i, a, b) for(i=a; i<b; i++)

using namespace std;

int N, M;
int val[110][110];
int vst[110][110];
int G[110][110];
int move[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};

bool _in(int x, int y)
{
   if(x < 0 || x >= N)  return 0;
   
   if(y < 0 || y >= M)  return 0;
   
   return 1;
          
}

bool sink(int x, int y)
{
   for(int k=0; k<4; k++)
   if(_in(x+move[k][0], y+move[k][1]) && 
      G[x+move[k][0]][y+move[k][1]] < G[x][y])
        return 0;
   
   return 1;  
}

void dfs(int x, int y)
{
   //cout << x << "  " << y << endl; 
   if(val[x][y] != -1)  return ;
     
   
   int h = G[x][y], i, j, k;
   
   for(k=0; k<4; k++)
   if(_in(x+move[k][0], y+move[k][1]) && 
      G[x+move[k][0]][y+move[k][1]] < h)
        i = x + move[k][0], j = y + move[k][1], h = G[i][j];
        
   dfs(i, j);
   val[x][y] = val[i][j];
}

void DFS(int i, int j, int w)
{
  // cout << i << "  " << j << endl;
   vst[i][j] = 1; 
   G[i][j] = w;
   
   for(int k=0; k<4; k++) 
   if(_in(i+move[k][0], j+move[k][1]) && !vst[i+move[k][0]][j+move[k][1]]
      && val[i+move[k][0]][j+move[k][1]] == val[i][j])
        DFS(i+move[k][0], j+move[k][1], w);
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("google2.txt", "w", stdout);
    
    int T;
    cin >> T;
    int cas = 0;
    
    while(T --)
    {
       int i, j, k;
       cin >> N >> M;
       
       MST(val, -1);
       MST(vst, 0);
       
       FOR(i, 0, N)
         FOR(j, 0, M)
           scanf("%d", &G[i][j]); 
       
       k = 1;    
       FOR(i, 0, N)
         FOR(j, 0, M)
         if(sink(i, j))
           val[i][j] = k ++; // cout << i << "  " << j << endl;
           
       FOR(i, 0, N)
         FOR(j, 0, M)
           dfs(i, j);//cout << endl;
       
       k = 'a' - 1;    
       FOR(i, 0, N)
         FOR(j, 0, M)
         if(!vst[i][j])
           DFS(i, j, ++ k);
       
       printf("Case #%d:\n",++cas);    
       FOR(i, 0, N)
       {
          FOR(j, 0, M-1)
            printf("%c ", G[i][j]);
          printf("%c\n",G[i][j]);    
       }
           
    }
                 
    return 0;
}

#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include<cctype>
#include<cmath>
#include <sstream>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>

using namespace std;

#define PB(x) push_back(x)
#define MP(x,y) make_pair((x),(y))
#define SZ(a) (int((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define REP(x,a,b) for(int x = (a);x < (b);x++)
#define FOR(x,n) REP(x,0,n)
#define FOREVER while(1)
#define WATCH(x) cout << #x << " = " << (x)

#ifdef DEBUG
#define D(X) X
#else
#define D(X)
#endif

typedef long long ll;
const int inf = (1<<29);
string grid[50];
int dx[] = {1,0,1,1};
int dy[] = {0,1,1,-1};
int main(){
   int T,N,K;
   cin >> T;
   FOR(t,T){
      cin >> N >> K;
      FOR(i,N)
         cin >> grid[i];
      FOR(i,N)reverse(ALL(grid[i]));
      FOR(i,N){
         FOR(j,N){
            int ind = j;
            while(ind < N && grid[i][ind] == '.')ind++;
            if(ind != j){
               grid[i][j] = grid[i][ind];
               grid[i][ind] = '.';
            }
         }
      }
      int red = 0;
      int blue = 0;
      FOR(i,N){
         FOR(j,N){
            if(grid[i][j] == 'R' || grid[i][j] == 'B'){
               int achou = 0;
               FOR(d,4){
                  int achei = 1;
                  FOR(k,K){
                     if(i+dx[d]*k < 0 || i+dx[d]*k >= N){
                        achei = 0;
                        break;
                     }
                     if(j+dy[d]*k < 0 || j+dy[d]*k >= N){
                        achei = 0;
                        break;
                     }
                     if(grid[i+dx[d]*k][j+dy[d]*k] != grid[i][j]){
                        achei = 0;
                        break;
                     }
                  }
                  if(achei){
                     achou = 1;
                     break;
                  }
               }
               if(achou){
                  if(grid[i][j] == 'R')red = 1;
                  if(grid[i][j] == 'B')blue = 1;
               }
            }
         }
      }
      if(!red && !blue)printf("Case #%d: Neither\n",t+1);
      if(red && blue)printf("Case #%d: Both\n",t+1);
      if(red && !blue)printf("Case #%d: Red\n",t+1);
      if(!red && blue)printf("Case #%d: Blue\n",t+1);
   }
   return 0;
}

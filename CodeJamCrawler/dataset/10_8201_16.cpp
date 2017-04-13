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
int grid[200][200];
int grid2[200][200];
int main(){
   int T,existe = 0,R,x1,x2,y1,y2;
   cin >> T;
   FOR(t,T){
      memset(grid,0,sizeof(grid));
      cin >> R;
      FOR(r,R){
         cin >> x1 >> y1 >> x2 >> y2;
         REP(i,x1,x2+1){
            REP(j,y1,y2+1){
               grid[i][j] = 1;
               existe = 1;
            }
         }
      }
   int count = 0;
   while(existe){
      count++;
      existe = 0;
      FOR(i,101)FOR(j,101){
         grid2[i][j] = grid[i][j];
      }
      FOR(i,101)FOR(j,101){
         if(grid2[i-1][j] && grid2[i][j-1]){grid[i][j] = 1;existe = 1;}
         else if(grid2[i-1][j] || grid2[i][j-1]){grid[i][j] = grid2[i][j];existe = (grid[i][j] || existe);}
         else grid[i][j] = 0;
         

      }
   }
   printf("Case #%d: %d\n",t+1,count);
   }
   return 0;
}

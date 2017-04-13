using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define MPI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define PI(x) printf("%d ",x)
#define PIS(x) printf("%d\n",x)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define F first
#define S second

char mat[6][6];

int checkf(){
  FR(i,4){
    int X=0,O=0;
    FR(j,4){
      if(mat[i][j]=='X' || mat[i][j]=='T') X++;
      if(mat[i][j]=='O' || mat[i][j]=='T') O++;
    }
//    D(X); D(O);
    if(X==4) return 1;
    if(O==4) return 2;
  }
  return 0;
}

int checkc(){
  FR(i,4){
    int X=0,O=0;
    FR(j,4){
      if(mat[j][i]=='X' || mat[j][i]=='T') X++;
      if(mat[j][i]=='O' || mat[j][i]=='T') O++;
    }
    if(X==4) return 1;
    if(O==4) return 2;
  }
  return 0;
}

int checkd(){
  int X=0,O=0;
  for(int i=0,j=0;i<4;i++,j++){
    if(mat[i][j]=='X' || mat[i][j]=='T') X++;
    if(mat[i][j]=='O' || mat[i][j]=='T') O++;
  }
  if(X==4) return 1;
  if(O==4) return 2;

  X=0;O=0;
  for(int i=3,j=0;i>=0;i--,j++){
    if(mat[i][j]=='X' || mat[i][j]=='T') X++;
    if(mat[i][j]=='O' || mat[i][j]=='T') O++;
  }

  if(X==4) return 1;
  if(O==4) return 2;
  return 0;
}

int main(){
  int T=1,n;
  cin >> n;
  FR(x,n){
    int cositas=0;
    FR(i,4){
      FR(j,4){
        cin >> mat[i][j];
        if(mat[i][j]=='.') cositas++;
      }
    }

/*    FR(i,4){
      FR(j,4) cout << mat[i][j];
      cout << endl;
    }
*/  
    int a = checkf();
    int b = checkc();
    int c = checkd();

    if(a){
      if(a==1) printf("Case #%d: X won\n",T++);
      else printf("Case #%d: O won\n",T++);
      continue;
    }
    
    if(b){
      if(b==1) printf("Case #%d: X won\n",T++);
      else printf("Case #%d: O won\n",T++);
      continue;
    }

    if(c){
      if(c==1) printf("Case #%d: X won\n",T++);
      else printf("Case #%d: O won\n",T++);
      continue;
    }
    
    if(!a && !b && !c){
      if(cositas) printf("Case #%d: Game has not completed\n",T++);
      else printf("Case #%d: Draw\n",T++);
    }
  }
  
}






#include<iostream>
#include<cmath>
#define EQ(x,y) (fabs((x)-(y))<1e-6)
using namespace std;
const int BUF = 505;

int row, col, val[BUF][BUF], mass;

void read(){
  cin >> row >> col >> mass;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      char ch;
      cin >> ch;
      val[i][j] = ch-'0'+mass;
    }
}


bool success(int K){
  for(int r=0;r+K<=row;r++)
    for(int c=0;c+K<=col;c++){
      double xVec = 0, yVec = 0;
      int sum = 0;
      for(int rr=0;rr<K;rr++)
        for(int cc=0;cc<K;cc++){
          if((rr==0   && cc==0) || (rr==0   && cc==K-1) || 
             (rr==K-1 && cc==0) || (rr==K-1 && cc==K-1) )  continue;
            
          sum += val[rr+r][cc+c];
          xVec += val[rr+r][cc+c]*(cc-K/2.0+0.5);
          yVec += val[rr+r][cc+c]*(rr-K/2.0+0.5);

          //if(EQ(xVec,0) && EQ(yVec,0) && EQ(1.0*sum/(K*K-2),mass))
          if(EQ(xVec,0) && EQ(yVec,0))
            return true;
        }
    }
  return false;
}


void work(int cases){
  for(int K=min(row,col);K>=3;K--)
    if(success(K)){
      cout << "Case #" << cases << ": " << K << endl;
      return;
    }
  cout << "Case #" << cases << ": IMPOSSIBLE" << endl;
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}

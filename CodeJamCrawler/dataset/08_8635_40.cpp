#include<iostream>
#include<complex>
#include<vector>
#define EPS (1.0e-8)
using namespace std;
typedef complex<int> Point;

int n, A, B, C, D, _x0, _y0, mod;

void read(){
  cin >> n >> A >> B >> C >> D >> _x0 >> _y0 >> mod;
}

void work(int cases){
  vector<Point> pts;

  int x = _x0, y = _y0;
  pts.push_back(Point(x,y));
  for(int i=1;i<n;i++){
    x = (1LL*A*x+B)%mod;
    y = (1LL*C*y+D)%mod;
    pts.push_back(Point(x,y));
  }

  int cnt = 0;
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      for(int k=j+1;k<n;k++){
        int xMod = (pts[i].real()+pts[j].real()+pts[k].real())%3;
        int yMod = (pts[i].imag()+pts[j].imag()+pts[k].imag())%3;

        if(xMod==0 && yMod==0) cnt++;
      }

  cout << "Case #" << cases << ": " << cnt << endl;
}

int main(){
    int cases;
    cin >> cases;

    for(int i=0;i<cases;i++){
      read();
      work(i+1);
    }
    
}

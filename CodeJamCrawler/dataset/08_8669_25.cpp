#include<iostream>
using namespace std;

int X, Y, A;

void read(){
  cin >> X >> Y >> A;
}

int calc(int x1, int x2, int y1, int y2, int xx, int yy){
  return 2*xx*yy-x1*y1-x2*y2-(x1-x2)*(y2-y1);
}

int calc(int x1, int x2, int y1, int y2){
  return 2*X*Y-x1*y1-x2*y2-(x1-x2)*(y2-y1);
}

void work(int cases){
  cout << "Case #" << cases << ": ";
  
  for(int xx=1;xx<=X;xx++)
    for(int yy=1;yy<=Y;yy++)
      for(int x=0;x<=xx;x++)
	for(int y=0;y<=yy;y++){
	  int x1 = 0, x2 = xx, x3 = x;
	  int y1 = 0, y2 = y, y3 = yy;

	if(calc(x2,x3,y2,y3,xx,yy)==A){
	  cout << x1 << ' ' << y1 << ' ' << x2<< ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
	  return;
	}
	}

  for(int x=0;x<=X;x++)
    for(int y=0;y<=Y;y++){
      int x1 = 0, x2 = X, x3 = x;
      int y1 = 0, y2 = y, y3 = Y;

      if(calc(x2,x3,y2,y3)==A){
	cout << x1 << ' ' << y1 << ' ' << x2<< ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
	return;
      }
    }

  for(int x=0;x<=X;x++)
    for(int y=0;y<=Y;y++){
      int x1 = 0, x2 = 0, x3 = x;
      int y1 = 0, y2 = y, y3 = 0;

      if(x*y==A){
	cout << x1 << ' ' << y1 << ' ' << x2<< ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
	return;
      }
    }


  cout << "IMPOSSIBLE" << endl;
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

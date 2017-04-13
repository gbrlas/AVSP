#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>
#include <numeric>

using namespace std;
int C, N,M,A;

void calc() {
  int B = max(N,M);
  for (int x1 = -B ; x1 <= B ; x1++) {
    for (int y1 = -B ; y1 <= B ; y1++) {  
      double a = sqrt(x1*x1 + y1*y1);   
      double h = double(A) / a;
      double x_perp = -y1;
      double y_perp = x1;
      double norm = sqrt(x_perp*x_perp + y_perp * y_perp);
      x_perp /= norm;
      y_perp /= norm;
      x_perp *= h;
      y_perp *= h;
      double coeff = double(y1) / double(x1);
      double beta = y_perp - coeff * x_perp;

      for (int x2 = -B ; x2 <= B ; x2++) {
	double y2_float = beta + coeff * x2 + 1e-9;
	if (fabs(y2_float - int(y2_float)) <= 1e-7) {
	  int y2 = int(y2_float);

	  double b = sqrt(x2*x2 + y2*y2);
	  double dx = x1-x2; double dy = y1-y2;
	  double c = sqrt(dx*dx + dy*dy);
	  double p = (a+b+c) / 2.;
	  double aire = sqrt(p * (p-a) * (p-b) * (p-c));
	  if (fabs(aire - double(A) / 2.) <= 1e-9) {
	    int min_x, min_y;
	    min_x = max(-x1, -x2);
	    min_x = max(min_x, 0);
	    min_y = max(-y1,-y2);
	    min_y = max(min_y, 0);
	    int xx1 = min_x + x1;
	    int xx2 = min_x + x2;
	    int yy1 = min_y + y1;
	    int yy2 = min_y + y2;
	    int xx0 = min_x;
	    int yy0 = min_y;
	    if (xx1 <= N && xx2 <= N && xx0 <= N &&
		yy1 <= M && yy2 <= M && yy0 <= M) {
	      //si ok
	      cout<<" "<<xx0<<" " << yy0
		  <<" "<<xx1<<" " << yy1
		  <<" "<<xx2<<" " << yy2 << endl;
	      return;
	    }
	  }
	}
      }
    }
  }
  cout << " IMPOSSIBLE" <<endl;
}

int main() {
  cin>>C;
  for (int tt = 1 ; tt <= C ; tt++) {
    cin>>N>>M>>A;
    cout << "Case #"<<tt<<":";
    calc();
  }

  return 0;
}

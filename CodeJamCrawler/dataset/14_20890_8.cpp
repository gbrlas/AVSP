#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i=0; i<cases; i++){
    int P, Q;
    char c;
    cin >> P >> c >> Q;
    bool possible = false;
    int pow = 1;
    for(int j=1; j<=40; j++){
      pow *= 2;
      if(Q==pow){
        possible = true;
      }
    }
    if(possible == false){
      cout << "Case #" << i+1 << ": " << "impossible" << endl;
      continue;
    }

    pow = 1;
    for(int j=1; j<=40; j++){
      pow *= 2;
      if(pow*P/Q >= 1){
        cout << "Case #" << i+1 << ": " << j << endl;
        break;
      }
    }
  }
  return 0;
}

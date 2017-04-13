// To run, please supply the input on stdin
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <cassert>
#include <limits>
#include <sstream>
#include <deque>

using namespace std;

#define DEBUG(x)  //x
#define DEBUG2(x) //x


int main() {

  int N;
  if (!(cin >> N)) {
    DEBUG(cout << "N expected\n");
    return -1;
  }
  
  int caseN = 1;
  DEBUG(cout << "N: " << N << "\n");
  
  int P, K, L;
  while (cin >> P) {
    cin >> K >> L;
    DEBUG(cout << "P: " << P << ", K: " << K << ", L: "  << L << "\n");

    deque<int> F;
    DEBUG(cout << "F: ");
    for (int i = 0; i < L; i++) {
      int tmp;
      cin >> tmp;
      F.push_back(tmp);
      DEBUG(cout << tmp << ", ");
    }
    DEBUG(cout << "\n");
    
    int R = 0;

    // time to solve
    sort(F.begin(), F.end(), greater<int>());
    
    int turn = 0;
    bool impossible = false;
    while (F.size() > 0) {
      int freq = F.front();
      DEBUG2(cout << freq << "\n");
      int r = turn / K + 1;
      if (r > P) {
        impossible = true;
        break;
      }
      R += r * freq;
      turn++;
      F.pop_front();
    }
    


    if (impossible) cout << "Case #" << caseN << ": Impossible\n";
    else            cout << "Case #" << caseN << ": " << R << "\n";
    caseN++;
  }
  
}
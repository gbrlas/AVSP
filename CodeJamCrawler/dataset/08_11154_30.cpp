// To run, please supply the input on stdin
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <cassert>
#include <limits>

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
  
  int S;
  while (cin >> S) {
    DEBUG(cout << "S: " << S << "\n");
    string dummy;
    getline(cin, dummy);
    
    map<string, int> s;
    for (int i = 0; i < S; i++) {
      string search_engine;
      getline(cin, search_engine);
      DEBUG(cout << "search_engine: " << search_engine << "\n");
      s[search_engine] = i;  // i'm more comfortable with the numbers
    }
    
    int Q;
    cin >> Q;
    getline(cin, dummy);
    DEBUG(cout << "Q: " << Q << "\n");
 
    vector<int> q;
    q.reserve(Q);
    for (int i = 0; i < Q; i++) {
      string query;
      getline(cin, query);
      DEBUG(cout << "query: " << query << "\n");
      q.push_back(s[query]);
    }
    DEBUG(cout << "q: ";  copy(q.begin(), q.end(), ostream_iterator<int>(cout, ""));  cout << "\n");
    
    // time to solve
    int R = -1;
    for (int j = 0; j < S; j++) {
      DEBUG2(cout << "============" << j << "\n");
      int i = 0;
      int p = j;
      int r = 0;
      while (i < Q) {
        if (q[i] == p) {
          r++;
          int farthest = 0;
          int pp = p;
          for (int k = 0; k < S; k++) {
            if (k == pp) continue;
            int d = distance(q.begin() + i, find(q.begin() + i, q.end(), k));
            if (d > farthest) {
              farthest = d;
              p = k;
            }
          }
          i += farthest;
          DEBUG2(cout << "farthest" << farthest << "\n");
          continue;
        }
        i++;
      };
      
      if (R == -1 || r < R)  R = r;
    }    
 
    cout << "Case #" << caseN << ": " << R << "\n";
    caseN++;
  }
  
}
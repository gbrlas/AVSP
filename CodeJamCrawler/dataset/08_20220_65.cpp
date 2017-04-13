/*
 * Google Code Jam 2008
 * Round 1A
 * Problem B: 
 *
 * James Rauen
 * jrauen@gmail.com
 * Handle: JRR
 */

using namespace std;
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>


struct Solver {
  int N; //number of flavors
  int M; //number of customers
  int likes[2048][2048];
  Solver() {
    memset(likes, -1, sizeof(likes));
    int T, X, Y;
    cin >> N >> M;
    for (int cust = 1; cust <= M; cust++) {
      cin >> T;
      for (int p = 1; p <= T; p++) {
	cin >> X >> Y;
	likes[cust][X] = Y;
      }
    }
  }
  bool okAssignmentForCustomer(int mask, int cust) {
    for (int flavor = 1; flavor <= N; flavor++)
      if (likes[cust][flavor] == ((mask >> (flavor-1)) & 1))
	return true;
    return false;
  }
  bool okAssignment(int mask) {
    for (int cust = 1; cust <= M; cust++)
      if (! okAssignmentForCustomer(mask, cust))
	return false;
    return true;
  }
  int popul(int mask) {
    int ret = 0;
    while (mask > 0) {
      ret += (mask & 1);
      mask >>= 1;
    }
    return ret;
  }

  void solve() {
    int bestmask = 0;
    int bestmalts = 999999;
    for (int mask = 0; mask < (1 << N); mask++) {
      if (okAssignment(mask)) 
	if (popul(mask) < bestmalts) {
	  bestmask = mask;
	  bestmalts = popul(mask);
	}
      //      if (okAssignment(mask)) cerr << "OK: " << mask << endl;
      //      else cerr << "NOT OK: " << mask << endl;
    }
    if (bestmalts == 999999)
      printf("IMPOSSIBLE\n");
    else {
      for (int i = 0; i < N; i++)
	printf("%d ", ((bestmask >> i) & 1));
      printf("\n");
    }
  }
};



int main(int argc, char *argv[])
{
  int C;
  cin >> C;
  for (int tc = 1; tc <= C; tc++) {
    auto_ptr<Solver> s(new Solver);
    printf("Case #%d: ", tc);
    s->solve();
  }
  return 0;
}
    
  

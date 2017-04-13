/*
 * Google Code Jam 2008
 * Americas Onsite Round - September 29, 2008
 * Problem C
 *
 * James Rauen
 * jrauen@gmail.com
 * Handle: JRR
 */

using namespace std;
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
typedef long long i64;
typedef pair<int, int> ipair;
#define FOR0(VAR,UB) for (int VAR = 0; VAR <  (UB); VAR++)
#define FOR1(VAR,UB) for (int VAR = 1; VAR <= (UB); VAR++)

template<typename T>
T scan(istream& is = cin) {T v; is >> v; return v;}


struct Solver {
  double A[6][4]; // [q][r]
  vector<double> B;
  void run() {
    int M, Q;
    cin >> M >> Q;
    FOR0(q, Q) FOR0(r, 4) cin >> A[q][r];
    for(int rmask = 0; rmask < (1 << (2*Q)); rmask++) {
      double thisProb = 1.0;
      FOR0(q, Q) {
	int r = (rmask >> (2*q)) & 3;
	thisProb *= A[q][r];
      }
      B.push_back(thisProb);
    }
    sort(B.rbegin(), B.rend());
    double check = 0.0;
    FOR0(i, B.size()) check += B[i];
    cerr << "B.size()= " << B.size() << endl;
    cerr << "check=" << check << endl;
    if (M >= B.size()) { cout << "1.0"; return; }
    double ret = 0.0;
    FOR0(i, M) ret += B[i];
    printf("%9.7f", ret);
  }
};

int main()
{
  const int nCases = scan<int>();
  for (int tc = 1; tc <= nCases; tc++) {
    cerr << "Case #" << tc << endl;
    cout << "Case #" << tc << ": ";
    auto_ptr<Solver> s(new Solver);
    s->run();
    cout << endl;
  }
  return 0;
}


/*
 * Google Code Jam 2008
 * Round 2
 * Problem D
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

template<typename T>
T scan(istream& is = cin) {T v; is >> v; return v;}


struct Solver {
  void run() {
    int k;
    string s;
    cin >> k >> s;
    int nChars = s.size();
    vector<int> permutation;
    for (int i = 0; i < k; i++)
      permutation.push_back(i);
    int lowestNumRuns = 99999999;
    do {
      vector<char> encoded(nChars, '#');
      for (int i = 0; i < nChars; i++)
	encoded[i] = s[((i / k) * k) + permutation[i % k]];
      int numRuns = 1;
      for (int i = 1; i < nChars; i++)
	if (encoded[i] != encoded[i-1])
	  numRuns++;
      if (numRuns < lowestNumRuns)
	lowestNumRuns = numRuns;
    } while (next_permutation(permutation.begin(), permutation.end()));
    cout << lowestNumRuns;
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


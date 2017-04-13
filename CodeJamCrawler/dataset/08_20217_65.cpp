/*
 * Google Code Jam 2008
 * Round 1A
 * Problem A: 
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
#include <algorithm>

long long dot(vector<int> &X, vector<int> & Y) {
  long long ret = 0;
  for (int i = 0; i < X.size(); i++)
    ret += X[i] * Y[i];
  return ret;
}

long long solve1(vector<int> X, vector<int> Y) {
  sort(X.begin(), X.end());
  sort(Y.rbegin(), Y.rend());
  return dot(X, Y);
}

long long solve2(vector<int> X, vector<int> Y) {
  sort (X.begin(), X.end());
  long long ret = (1 << 30);
  do {
    long long u = dot(X, Y);
    //    cerr << u << endl;
    if (u < ret) ret = u;
  } while (next_permutation(X.begin(), X.end()));
  //  cerr << "Returning " << ret << endl;
  return ret;
}


int main(int argc, char *argv[])
{
  bool verify = true;
  int N;
  cin >> N;
  for (int tc = 1; tc <= N; tc++) {
    int k;
    cin >> k;
    vector<int> X, Y;
    for (int i = 0; i < k; i++) {
      int v;
      cin >> v;
      X.push_back(v);
    }
    for (int i = 0; i < k; i++) {
      int v;
      cin >> v;
      Y.push_back(v);
    }
    long long result1 = solve1(X, Y);
    if (verify) {
      long long result2 = solve2(X, Y);
      assert (result1 == result2);
    }
    cout << "Case #" << tc << ": " << result1 << endl;
  }
  return 0;
}
    
  

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
#define MOD 1000000007
#define NN 1010

long long dyna[NN];
long long seq[NN];
int seq_size;

long long how_many(const int i) {
  long long& res = dyna[i];
  if (res != -1) return res;
  res = 1;   //celle qui s'arête en i.
  for (int j = i+1 ; j < seq_size ; j++) {
    if (seq[j] > seq[i]) {
      res += how_many(j);
      res %= MOD;
    }
  }
  //  cout << "i "<<i<<" res " << res<<endl;
  return res;
}
  
int main() {
  int test_case;
  cin>>test_case;
  long long m,X,Y,Z;
  for (int tt = 1 ; tt <= test_case ; tt++) {
    cin>>seq_size;
    cin>>m>>X>>Y>>Z;
    vector<long long> A(m);
    for (int i = 0; i < m ; i++)
      cin>>A[i];
    for (int i = 0 ; i < seq_size ; i++) {
      seq[i] = A[i % m];
      //      cout << "seq["<<i<<"] = " << seq[i]<<endl;
      A[i % m] = (X * A[i%m] + Y * (i+1)) % Z;
    }
    fill(dyna, dyna + NN, -1);
    long long res = 0;
    for (int i = 0 ; i < seq_size ; i++) {
      res += how_many(i);
      //      cout << res <<endl;
    }
    res %= MOD;
    cout <<"Case #"<<tt<<": "<<res<<endl;
  }

  return 0;
}

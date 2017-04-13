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
  
long long P, K, L;  
vector<long long>freqs;

long long calc() {
  long long res = 0;
  vector<long long> keys(K, 0);
  sort(freqs.rbegin(), freqs.rend());
  for (long long i = 0 ; i < freqs.size() ; i++) {
    vector<long long>::iterator it = min_element(keys.begin(), keys.end());
    res += freqs[i] * (*it + 1);
    (*it)++;
  }
  return res;
}

int main() {
  long long test_case;
  cin>>test_case;
  for (long long tt = 1 ;  tt <= test_case ; tt++) {
    cin>>P>>K>>L;
    freqs.resize(L);
    for (long long i = 0 ; i < L ; i++) {
      cin>>freqs[i];
    }
    long long res = calc();
    cout << "Case #"<<tt<<": " << res <<endl;
  }

  return 0;
}

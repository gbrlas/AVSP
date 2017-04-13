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
  
int P, K, L;  
vector<int>freqs;

int calc() {
  int res = 0;
  vector<int> keys(K, 0);
  sort(freqs.rbegin(), freqs.rend());
  for (int i = 0 ; i < freqs.size() ; i++) {
    vector<int>::iterator it = min_element(keys.begin(), keys.end());
    res += freqs[i] * (*it + 1);
    (*it)++;
  }
  return res;
}

int main() {
  int test_case;
  cin>>test_case;
  for (int tt = 1 ;  tt <= test_case ; tt++) {
    cin>>P>>K>>L;
    freqs.resize(L);
    for (int i = 0 ; i < L ; i++) {
      cin>>freqs[i];
    }
    int res = calc();
    cout << "Case #"<<tt<<": " << res <<endl;
  }

  return 0;
}

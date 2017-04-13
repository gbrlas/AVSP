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
  
string N_str;
  
const int pluss = 0;
const int moins = 1;

long long calc(int i, long long cur_value, long long cur, bool sign) {
  if (i == N_str.size()) {
    long long val;
    if (sign == pluss) val = cur_value + cur;
    else val = cur_value - cur;
    return val % 2 == 0 || val % 3 == 0 || val % 5 == 0 || val % 7 == 0;
  }
  long long res = 0;
  res += calc(i+1, cur_value, cur * 10 + (N_str[i]-'0'), sign);
  if (i > 0) {
    long long val = 0;
    if (sign == pluss) val = cur_value + cur; else val = cur_value - cur;
    res += calc(i+1, val, N_str[i] - '0', pluss);
    res += calc(i+1, val, N_str[i] - '0', moins);
  }
  return res;
}

int main() {
  int test_case;
  cin>>test_case;
  for (int tt = 1 ; tt <= test_case ; tt++) {
    cin.ignore();
    cin>>N_str;
    long long res = calc(0, 0, 0, pluss);
    cout <<"Case #"<<tt<<": "<<res<<endl;
  }
  return 0;
}

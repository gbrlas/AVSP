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

long long dyna[50][220][220][2];

long long calc(int i, int cur_value_mod210, int cur_mod210, bool sign) {
  long long& res = dyna[i][cur_value_mod210][cur_mod210][sign];
  if (res != -1) return res;
  long long val;
  if (sign == pluss) val = cur_value_mod210 + cur_mod210;
  else val = cur_value_mod210 - cur_mod210 + 210;
  val %= 210;

  if (i == N_str.size()) {
    return val % 2 == 0 || val % 3 == 0 || val % 5 == 0 || val % 7 == 0;
  }

  res = 0;
  res += calc(i+1, cur_value_mod210, (cur_mod210 * 10 + int(N_str[i]-'0')) % 210, sign);
  if (i > 0) {
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
    fill(***dyna, ***dyna + 50*220*220*2, -1);
    long long res = calc(0, 0, 0, pluss);
    cout <<"Case #"<<tt<<": "<<res<<endl;
  }
  return 0;
}

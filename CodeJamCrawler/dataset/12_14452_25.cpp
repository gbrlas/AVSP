#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back


vector<int> getms (int n) {
  vector<int> ret;
  stringstream ss;
  ss << n;
  string digits;
  ss >> digits;

  set<int> realret;

  for(int i = 0; i < digits.size(); i++) {
    digits = digits[digits.size()-1] + digits.substr(0, digits.size()-1);
    if(digits[0] != '0') realret.insert(atoi(digits.c_str()));
  }

  return vector<int>(realret.begin(), realret.end());
}


int getans(int A, int B) {
  int ret = 0;
  for(int n = A; n <= B; n++) {
    vector<int> ms = getms(n);
    for(int i = 0; i < ms.size(); i++) {
      if(ms[i] > n && ms[i] <= B)
        ret++;
    }
  }

  return ret;
}

int main() {
  int T;
  cin >> T;
  for(int c = 0; c < T; c++) {
    int A, B;
    cin >> A >> B;
    int ans = getans(A,B);
    cout << "Case #" << (c+1) << ": " << ans << endl;
  }
  return 0;
}


#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ASSERT_ for (;;) {}
#define PII pair<long long, long long>
using namespace std;

int main() {
  long long T, A, B;
  cin >> T;
  for (long long testcase = 1; testcase <= T; testcase++) {
    long long res = 0;
    cin >> A >> B;
    for (long long n = A; n <= B; n++) {
      long long num = n;
      vector<long long> digits;
      long long len = 0;
      while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
        len++;
      }
      reverse(digits.begin(), digits.end());
      vector<long long> tmp(digits);
      copy(digits.begin(), digits.end(), back_inserter(tmp));;
      swap(tmp, digits);
      assert(digits.size() == 2 * len);
      set<long long> secik;
      for (long long st = 1; st < len; st++) {
        long long x = 0;
        for (long long st2 = st; st2 < st + len; st2++) {
          assert((unsigned)st2 < digits.size());
          x = 10*x + digits[st2];
        }
        if (n < x && x <= B) { 
          secik.insert(x);
        }
      }
      res += secik.size();
    }
    cout << "Case #" << testcase << ": " << res << endl;
  }
  return 0;
}

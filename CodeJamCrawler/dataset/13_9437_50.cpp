#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long

int isPalindrome(ll num) {
  ll num_rev = 1;
  ll num_temp = num;
  num_rev = num_temp % 10;
  num_temp /= 10;
  while (num_temp) {
    num_rev = (num_rev * 10) + (num_temp % 10);
    num_temp /= 10;
  }
  if (!(num_rev - num)) return 1;

  return 0;
}

int main()
{
  int T, i = 0;
  ll A, B;

  cin >> T;
  while (i++ < T) {
    cin >> A >> B;
    int num, sum = 0;

    ll A_root = sqrt(A);
    ll B_root = sqrt(B);
    if (A != B) {
      if ((A_root * A_root) == A)
	if (isPalindrome(A) && isPalindrome(A_root)) sum++;
      if ((B_root * B_root) == B)
	if (isPalindrome(B) && isPalindrome(B_root)) sum++;
    }
    else {
      if ((A_root * A_root) == A)
	if (isPalindrome(A) && isPalindrome(A_root)) sum++;
    }

    if ((A_root * A_root) == A)
      A_root++;
    if ((A_root * A_root) < A)
      A_root++;
    if ((B_root * B_root) == B)
      B_root--;
    if ((B_root * B_root) < B)
      B_root = B_root;

    for (int j = A_root; j <= B_root; j++) {
      if (isPalindrome(j))
	if (isPalindrome(j * j))
	  sum++;
    }
    cout << "Case #" << i << ": " << sum << endl;

  }    

  return 0;
}

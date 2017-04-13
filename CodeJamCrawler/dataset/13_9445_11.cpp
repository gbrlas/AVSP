#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double

int main()
{
  int T, i = 0;
  ld r, t;
  cin >> T;
  while (i < T) {
    cin >> r >> t;
    int count = 0, j = 0;
    ld area = 0.0;
    ld reqArea = (22.0 / 7.0) * t;
    while (1) {
      area += (22.0 / 7.0) * ((double)(4.0 * j) + 1.0 + (2 * r));
      j++;
      if (area > reqArea)
	break;
      else
	count++;
    }
    i++;
    cout << "Case #" << i << ": " << count << endl;
  }

  return 0;
}

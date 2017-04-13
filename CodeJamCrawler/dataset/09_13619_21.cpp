#include <iostream>
#include <vector>
using namespace std;

int main () {

  int t, n;
  char buf[50];
  scanf("%d\n", &t);
  for (int c = 1; c <= t; ++c) {
    scanf("%d\n", &n);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      scanf("%s", buf);
      int p = n-1;
      for (; p >= 0; --p)
	if (buf[p] == '1')
	  break;
      v.push_back(p);
      //printf("%d %d\n", i, p);
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] > i) {
	int p = i+1;
	for (; p < n; ++p)
	  if (v[p] <= i)
	    break;
	for (int j = p; j > i; --j) {
	  ++k;
	  int tt = v[j-1];
	  v[j-1] = v[j];
	  v[j] = tt;
	}
      }
    }
    printf("Case #%d: %d\n", c, k);
  }
}

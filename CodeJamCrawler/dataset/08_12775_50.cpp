#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool seen[101];

int solve (vector<int> & q, size_t t, int len) {

  int s = 0;
  for (int i = 0; i < len; ++i)
    seen[i] = false;
  for (; t < q.size(); ++t) {
    if (!seen[q[t]]) {
      seen[q[t]] = true;
      if (++s == len)
	break;
    }
  }
  return (t < q.size() ? 1+solve(q, t, len) : 0);
}

int main () {

  int N, S, Q, c = 0;
  char in[110];
  scanf("%d\n", &N);
  while (N--) {
    int t = 0;
    scanf("%d\n", &S);
    map<string,int> mmap;
    for (; t < S; ) {
      cin.getline(in, 110);
      mmap[string(in)] = t++;
    }
    scanf("%d\n", &Q);
    vector<int> q;
    for (t = 0; t < Q; ++t) {
      cin.getline(in, 110);
      q.push_back(mmap[string(in)]);
    }
    printf("Case #%d: %d\n", ++c, solve(q, 0, S));
  }
}

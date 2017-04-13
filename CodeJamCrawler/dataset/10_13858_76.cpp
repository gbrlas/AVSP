#include <cstdio>
#include <deque>

using namespace std;

int main() {
  int cases;

  scanf("%d\n", &cases);

  for (int c = 0; c < cases; c++) {
    int rides, size, n;
    int sum = 0;
    int curr = 0;
    deque<pair<int, int> > q;

    scanf("%d %d %d\n", &rides, &size, &n);

    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d ", &a);
      q.push_back(make_pair(a, -1));
    }

    for (int i = 0; i < rides; i++) {
      while (curr + q.front().first <= size && q.front().second != i) {
        curr += q.front().first;
        q.push_back(make_pair(q.front().first, i));
        q.pop_front();
      }

      sum += curr;
      curr = 0;
    }

    printf("Case #%d: %d\n", c + 1, sum);
  }

  return 0;
}

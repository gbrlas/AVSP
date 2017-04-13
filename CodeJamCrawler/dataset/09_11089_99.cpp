#include <cstdio>
#include <deque>
using namespace std;

int basin[100][100];
int height[100][100];

int main() {
  int T;
  scanf("%d", &T);

  for (int tt = 1; tt <= T; ++tt) {
    int H, W;
    scanf("%d%d", &H, &W);

    for (int i = 0; i < H; ++i)
      for (int j = 0; j < W; ++j) {
        basin[i][j] = -1;
        scanf("%d", &height[i][j]);
      }

    printf("Case #%d:\n", tt);

    int basins = 0;

    for (int i = 0; i < H; ++i)
      for (int j = 0; j < W; ++j) {
        if (basin[i][j] == -1) {
          deque<pair<int, int> > Q;

          Q.push_back(make_pair(i, j));

          while (!Q.empty()) {
            int r = Q.back().first;
            int c = Q.back().second;

            int cand_r[] = { r, r - 1, r, r, r + 1 };
            int cand_c[] = { c, c, c - 1, c + 1, c };

            int best = 0;

            for (int k = 1; k < 5; ++k) {
              if (cand_r[k] < 0 || cand_r[k] >= H || cand_c[k] < 0 || cand_c[k] >= W)
                continue;

              if (height[cand_r[k]][cand_c[k]] < height[cand_r[best]][cand_c[best]])
                best = k;
            }

            if (best == 0) {
              /* New basin */
              basin[r][c] = basins++;
              Q.pop_back();
            } else if (basin[cand_r[best]][cand_c[best]] != -1) {
              /* We know our basin */
              basin[r][c] = basin[cand_r[best]][cand_c[best]];
              Q.pop_back();
            } else {
              /* We need to dig deeper */
              Q.push_back(make_pair(cand_r[best], cand_c[best]));
            }
          }
        }

        printf("%c%c", basin[i][j] + 'a', (j == W - 1) ? '\n' : ' ');
      }
  }

  return 0;
}

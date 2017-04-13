#include <algorithm>
#include <cstdio>

using namespace std;

const int O = 0;
const int B = 1;

long solve() {
  int n;
  scanf("%d", &n);

  long pos[2];
  pos[O] = 1;
  pos[B] = 1;

  long turns[2];
  turns[O] = 0;
  turns[B] = 0;

  char buff[4];
  int button;
  int robot, otherRobot;
  long ans = 0;
  //printf("\n");
  for (int i = 0; i < n; ++ i) {
    scanf("%s %d", buff, &button);
    //printf("%s %d\n", buff, button);
    if (buff[0] == 'O') {
      robot = O;
    } else {
      robot = B;
    }
    otherRobot = !robot;
    
    //printf("%ld : %ld\n", turns[otherRobot] + 1, turns[robot] + labs(pos[robot] - button) + 1);
    turns[robot] = max(turns[otherRobot] + 1, turns[robot] + labs(pos[robot] - button) + 1);
    pos[robot] = button;
    ans = turns[robot];
    //printf("Turn %d: %ld\n", i, ans);
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; ++i) {
    long ans = solve();
    printf("Case #%d: %ld\n", i, ans);
  }
  return 0;
}

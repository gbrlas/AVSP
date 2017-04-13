#include <algorithm>
#include <cstdio>

using namespace std;

const int C = 64;
const int D = 32;
const int N = 128;

int combCount;
char combTable[C][4];
int oppCount;
char oppTable[D][4];

int n;
char input[N];
int ansLen;
char answer[N];
char present[32];

int top;

void readInput() {
  scanf("%d", &combCount);
  for (int i = 0; i < combCount; ++i) {
    scanf("%s", combTable[i]);
  }
  scanf("%d", &oppCount);
  for (int i = 0; i < oppCount; ++i) {
    scanf("%s", oppTable[i]);
  }
  scanf("%d %s", &n, input);
  top = 0;
  for (int i = 0; i < 32; ++ i) {
    present[i] = 0;
  }
}

char tryCombine(char x, char y) {
  for (int i = 0; i < combCount; ++ i) {
    if ((x == combTable[i][0] && y == combTable[i][1]) ||
        (x == combTable[i][1] && y == combTable[i][0])) {
      return combTable[i][2];
    }
  }
  return 0;
}

bool tryOppose(char x) {
  for (int i = 0; i < oppCount; ++ i) {
    if (x == oppTable[i][0] && present[oppTable[i][1] - 'A']) {
      return true;
    }
    if (x == oppTable[i][1] && present[oppTable[i][0] - 'A']) {
      return true;
    }
  }
  return false;
}

void addChar(char ch) {
  answer[top++] = ch;
  ++present[ch - 'A'];
}

void popChar() {
  --top;
  --present[answer[top] - 'A'];
}

void solve() {
  readInput();
  char ch, newCh;
  for (int i = 0; i < n; ++ i) {
    ch = input[i];
    while (top > 0 && (newCh = tryCombine(answer[top - 1], ch))) {
      ch = newCh;
      popChar();
    }
    if (top > 0 && tryOppose(ch)) {
      while (top > 0) {
        popChar();
      }
    } else {
      addChar(ch);
    }
  }
  ansLen = top;
}

int main(int argc, char *argv[]) {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; ++i) {
    solve();
    printf("Case #%d: [", i);
    if (ansLen > 0) {
      printf("%c", answer[0]);
    }
    for (int j = 1; j < ansLen; ++ j) {
      printf(", %c", answer[j]);
    }
    printf("]\n");
  }
  return 0;
}

#include <stdio.h>
#define NORTH 0
#define WEST  1
#define EAST  2
#define SOUTH 3
#define SINK  4
#define UNDEF '0'

int T, H, W;
char next;
int map[100 * 100];
char div[100 * 100];

char mark(int *map, char *div, int j, int k) {
  if (div[W * j + k] != UNDEF) {
    #ifdef DEBUG
    printf("Found cached: %c\n", div[W * j + k]);
    #endif
    return div[W * j + k];
  }
  int min = map[W * j + k];
  int where = SINK;
  if(j > 0 && map[W * (j - 1) + k] < min) {
    min = map[W * (j - 1) + k];
    where = NORTH;
  }
  if(k > 0 && map[W * j + k - 1] < min) {
    min = map[W * j + k - 1];
    where = WEST;
  }
  if(k < W - 1 && map[W * j + k + 1] < min) {
    min = map[W * j + k + 1];
    where = EAST;
  }  	
  if(j < H - 1 && map[W * (j + 1) + k] < min) {
    min = map[W * (j + 1) + k];
    where = SOUTH;
  }
  switch (where) {
  case NORTH:
    return div[W * j + k] = mark(map, div, j - 1, k);
  case WEST:
    return div[W * j + k] = mark(map, div, j, k - 1);
  case EAST:
    return div[W * j + k] = mark(map, div, j, k + 1);
  case SOUTH:
    return div[W * j + k] = mark(map, div, j + 1, k);
  case SINK:
    return div[W * j + k] = next++;
  }
}

void print_basin(char c) {
  printf('a' <= c && c <= 'z' ? "%c " : "0x%x ", c);
}

int main() {
  int i, j, k;
  scanf("%d", &T);
  for (i = 0; i < T; i++) {
    scanf("%d%d", &H, &W);
    next = 'a';
    for (j = 0; j < H; j++) {
      for (k = 0; k < W; k++) {
	scanf("%d", &map[W * j + k]);
	div[W * j + k] = UNDEF;
      }
    }
    printf("Case #%d:\n", i + 1);
    for (j = 0; j < H; j++) {
      for (k = 0; k < W; k++) {
	mark(map, div, j, k);
	print_basin(div[W * j + k]);
      }
      putchar('\n');
    }	
  }
  return 0;
}

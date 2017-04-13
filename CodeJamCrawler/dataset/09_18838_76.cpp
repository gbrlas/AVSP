#include <stdlib.h>
#include <stdio.h>

int H;
int W;
int map[101][101];
int label[101][101];
char tochar[26];
int next = 0;

int run(int i, int j) {
  if (label[i][j] != -1) {
    return label[i][j];
  }
  int min = map[i][j];
  int nexti = -1;
  int nextj = -1;
  if (i != 0 && map[i-1][j] < min) {
    min = map[i-1][j];
    nexti = i-1;
    nextj = j;
  }
  if (j != 0 && map[i][j-1] < min) {
    min = map[i][j-1];
    nexti = i;
    nextj = j-1;
  }
  if (j != W-1 && map[i][j+1] < min) {
    min = map[i][j+1];
    nexti = i;
    nextj = j+1;
  }
  if (i != H-1 && map[i+1][j] < min) {
    min = map[i+1][j];
    nexti = i+1;
    nextj = j;
  }
  if (nexti != -1) {
    label[i][j] = run(nexti, nextj);
  } else {
    label[i][j] = next;
  }
  return label[i][j];
}

int main()
{
  int T;
  scanf("%d", &T);
  int casenum;
  for (casenum = 1; casenum <= T; casenum++) {
    scanf("%d %d", &H, &W);
    int i;
    int j;
    for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
        scanf("%d",&(map[i][j]));
        label[i][j] = -1;
      }
    }
    for (i = 0; i < 26; i++) {
      tochar[i] = '\0';
    }
    next = 0;
    for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
        if (label[i][j] == -1) {
          run(i,j);
          next++;
        }
      }
    }
    char nextused = 'a';
    for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
        if (tochar[label[i][j]] == '\0') {
          tochar[label[i][j]] = nextused++;
        }
      }
    }
    printf("Case #%d:\n",casenum);
    for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
        printf("%c",tochar[label[i][j]]);
        if (j != W-1) {
          printf(" ");
        }
      }
      printf("\n");
    }
  }
}

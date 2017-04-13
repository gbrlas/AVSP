#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool rwin = false;
bool bwin = false;
bool over = false;

void check(int r, int b, int K) {
  if (r >= K) rwin = true;
  if (b >= K) bwin = true;
  if (rwin && bwin) over = true;
}

void count(char ch, int& r, int& b) {
  if (ch == 'R') {
    r++;
    b = 0;
  }else if (ch == 'B') {
    b++;
    r = 0;
  } else {
    r = b = 0;
  }
}

int main() {
  char tmp[52];

  gets(tmp);
  int caseN;
  sscanf(tmp, "%d", &caseN);

  for (int cc = 1; cc <= caseN; ++cc) {
    cout << "Case #" << cc << ": " ;

    gets(tmp);
    int N, K;
    sscanf(tmp, "%d%d", &N, &K);

    char board[N][N];
    char tmp2[N];

    memset(board, '.', N * N);
    for (int i = 0; i < N; ++i) {
      gets(tmp);

      int w = N - 1;
      for (int j = N - 1; j >= 0; --j)
        if (tmp[j] != '.') {
          tmp2[w] = tmp[j];
          w--;
        }

      //strncpy(board[i], tmp, N);
      w++;
      strncpy(board[i] + w, tmp2 + w, N - w);
    }

/*
    cout << endl;

    // dump
    for (int i = 0; i < N; ++i){
      for (int j = 0; j < N; ++j)
        cout << board[i][j];
      cout << endl;
    }
    cout << endl;
*/
    // start search
    rwin = false;
    bwin = false;
    over = false;

    // dir -
    for (int i = 0; !over && i < N; ++i) {
      int r = 0;
      int b = 0;
      for (int j = N -1; !over && j >= 0; --j) {
        if (board[i][j] == '.') break;
        else count(board[i][j], r, b);
        check(r, b, K);
      }
    }

    // dir |
    for (int i = 0; !over && i < N; ++i) {
      int r = 0;
      int b = 0;
      for (int j = N -1; !over && j >= 0; --j) {
        if (board[j][i] == '.') break;
        else count(board[j][i], r, b);
        check(r, b, K);
      }
    }

    // dir /
    for (int i = 0; !over && i < N; ++i) {
      int r = 0;
      int b = 0;
      int ti = 0;
      int tj = i;
      int di = 1;
      int dj = -1;
      for (; ti < N && tj >= 0; ti += di, tj += dj) {
        count(board[ti][tj], r, b);
        check(r, b, K);
      }
    }
    for (int i = 1; !over && i < N; ++i) {
      int r = 0;
      int b = 0;
      int ti = N - 1;
      int tj = i;
      int di = -1;
      int dj = 1;
      for (; ti >= 0 && tj < N; ti += di, tj += dj) {
        count(board[ti][tj], r, b);
        check(r, b, K);
      }
    }

    // dir
    for (int i = 0; !over && i < N; ++i) {
      int r = 0;
      int b = 0;
      int ti = N - 1;
      int tj = i;
      int di = -1;
      int dj = -1;
      for (; ti >= 0 && tj >= 0; ti += di, tj += dj) {
        count(board[ti][tj], r, b);
        check(r, b, K);
      }
    }
    for (int i = 1; !over && i < N; ++i) {
      int r = 0;
      int b = 0;
      int ti = 0;
      int tj = i;
      int di = 1;
      int dj = 1;
      for (; ti < N && tj < N; ti += di, tj += dj) {
        count(board[ti][tj], r, b);
        check(r, b, K);
      }
    }

    if (bwin && rwin) cout << "Both";
    else if (bwin) cout << "Blue";
    else if (rwin) cout << "Red";
    else cout << "Neither";

    cout << endl;
  }

  return 0;
}


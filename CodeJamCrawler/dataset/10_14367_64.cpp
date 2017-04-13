// 空白哥光芒万丈！信空白，拿AC！
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <queue>

//#define _DEBUG_MODE_

#ifdef _DEBUG_MODE_
#define db(X) cerr << "* DEBUG [L" << __LINE__ << "]: " << #X << " = " << X << endl;
#define db_arr(X) cerr << "* DEBUG [L" << __LINE__ << "]: {" << #X << "} = "; for (int __i__=0; __i__<sizeof(X)/sizeof(X[0]); __i__++) cerr << X[__i__] << " "; cerr << endl;
#define db_arrM(X, M) cerr << "* DEBUG [L" << __LINE__ << "]: {" << #X << "} = "; for (int __i__=0; __i__<M; __i__++) cerr << X[__i__] << " "; cerr << endl;
#define db_arrMN(X, M, N) cerr << "* DEBUG [L" << __LINE__ << "]: {" << #X << "} = "; for (int __i__=M; __i__<N; __i__++) cerr << X[__i__] << " "; cerr << endl;
#else
#define db(X)
#define db_arr(X)
#define db_arrM(X, M)
#define db_arrMN(X, M, N)
#endif

#define For(i, n) for(i=0;i<(n);i++)
#define ForL(i, m, n) for(i=(m);i<(n);i++)

#define Clear(X) memset( (X), 0, sizeof( (X) ) )
#define Fill(X) memset( (X), -1, sizeof( (X) ) )

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned long ulong;

void _main();

int main() {
  // COUNTER CODE STARTS HERE

  int cases, i;

  cin >> cases;

  For (i, cases) {
    printf("Case #%d: ", i+1);
    _main();
    cout << endl;
  }

  // COUNTER CODE ENDS HERE

  return 0;
}

// ACTUAL CODE STARTS BELOW
int M, N;
int board[600][600];

bool check(int row, int col, int edge) {
  int i, j;
  //db(row); db(col) db(edge);

  // First pixel
  if (board[row][col] == 0) return false;
  if (edge == 1) return true;

  // First row
  for (i=col+1; i<col+edge; i++) { 
    if (board[row][i] == 0 || board[row][i] == board[row][i-1]) return false;
  }

  // Following rows
  for (j=row+1; j<row+edge; j++) {
    for (i=col; i<col+edge; i++) {
      if (board[j][i] == 0 || board[j][i] == board[j-1][i]) return false;
    }
  }

  return true;
}

void cut(int row, int col, int edge) {
  int i, j;
  For (i, edge) For (j, edge) board[j+row][i+col] = 0;
  //  cerr << endl;  For (i, M) { db_arrM(board[i+1], N+2); }
}

void read() {
  cin >> M >> N;
  Clear(board);

  int i, j, k, d, t;
  string s;
  char c;

  For (i, M) {
    cin >> s;
    For (j, N/4) {
      c = s[j];
      if (c >= '0' && c <= '9') {
	d = c-'0';
      } else {
	d = 10+c-'A';
      }

      For (k, 4) {
	t = d & 1;
	d >>= 1; t++;
	board[i+1][(j+1)*4-k] = t;
      }
    }
    db_arrM(board[i+1], N+2);
  }
}

void _main() {
  read();
  int sum = 0, size=min(M, N);
  int r, c, remain = M*N;
  int out[1000];
  Clear(out);

  while (size > 0 && remain > 0) {
    for (r=1; r<=M-size+1; r++) {
      for (c=1; c<=N-size+1; c++) {
	if (check(r, c, size)) {
	  if (!out[size]) sum++;
	  out[size]++;
	  cut(r, c, size);
	  remain -= size*size;
	}
      }
    }
    size--;
  }
  cout << sum;
  
  for (int i=999; i>0; i--) {
    if (out[i]) cout << endl << i << " " << out[i];
  }
}
  

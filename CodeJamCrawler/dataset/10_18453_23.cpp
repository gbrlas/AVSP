#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cal(vector<char>& board, int n, int m) {
  for (int i = 0; i < n; ++i) {
    int k = n - 1;
    for (int j = n-1; j >= 0; --j) {
      if (board[i*n+j] != '.') {
        if (j != k) {
          board[i*n+k] = board[i*n+j];
        }
        --k;
      }
    }
    for (; k >= 0; --k) board[i*n+k] = '.';
  }
  bool blue = false;
  bool red = false;
  // Check every row.
  for (int i = 0; i < n; ++i) {
    int count = 0;
    char last = '.';
    for (int j = 0; j < n; ++j) {
      if (board[i*n+j] == last) count++;
      else {
        last = board[i*n+j];
        count = 1;
      }
      if (count == m && last != '.') {
        if (last == 'B') blue = true;
        else red = true;
      }
    }
  }
  if (red && blue) return 1;
  // Check every column.
  for (int i = 0; i < n; ++i) {
    int count = 0;
    char last = '.';
    for (int j = 0; j < n; ++j) {
      if (board[j*n+i] == last) count++;
      else {
        last = board[j*n+i];
        count = 1;
      }
      if (count == m && last != '.') {
        if (last == 'B') blue = true;
        else red = true;
      }
    }
  }
  if (red && blue) return 1;

  for (int i = 0; i < n; ++i) {
    int count = 0;
    char last = '.';
    for (int j = 0; j < n; ++j) {
      int x = n - 1 - j;
      int y = i - j;
      if (x < 0 || x >= n || y < 0 || y >= n) break;
      if (board[x*n+y] == last) count++;
      else {
        last = board[x*n+y];
        count = 1;
      }
      if (count == m && last != '.') {
        if (last == 'B') blue = true;
        else red = true;
      }
    }
  }
  if (red && blue) return 1;
  for (int i = 0; i < n; ++i) {
    int count = 0;
    char last = '.';
    for (int j = 0; j < n; ++j) {
      int x = i - j;
      int y = n - 1 - j;
      if (x < 0 || x >= n || y < 0 || y >= n) break;
      if (board[x*n+y] == last) count++;
      else {
        last = board[x*n+y];
        count = 1;
      }
      if (count == m && last != '.') {
        if (last == 'B') blue = true;
        else red = true;
      }
    }
  }
  if (red && blue) return 1;
  for (int i = 0; i < n; ++i) {
    int count = 0;
    char last = '.';
    for (int j = 0; j < n; ++j) {
      int x = j;
      int y = i - j;
      if (x < 0 || x >= n || y < 0 || y >= n) break;
      if (board[x*n+y] == last) count++;
      else {
        last = board[x*n+y];
        count = 1;
      }
      if (count == m && last != '.') {
        if (last == 'B') blue = true;
        else red = true;
      }
    }
  }
  if (red && blue) return 1;
  for (int i = 0; i < n; ++i) {
    int count = 0;
    char last = '.';
    for (int j = 0; j < n; ++j) {
      int x = i + j;
      int y = n - 1 - j;
      if (x < 0 || x >= n || y < 0 || y >= n) break;
      if (board[x*n+y] == last) count++;
      else {
        last = board[x*n+y];
        count = 1;
      }
      if (count == m && last != '.') {
        if (last == 'B') blue = true;
        else red = true;
      }
    }
  }
  if (red && blue) return 1;
  if (!red && !blue) return 0;
  if (red && !blue) return 2;
  if (!red && blue) return 3;
  return - 1;
}

int main(int argc, char* argv[]) {
  ifstream in(argv[1]);
  int t;
  in >> t;
  vector<char> board;
  for (int i = 0; i < t; ++i) {
    int n, k;
    in >> n >> k;
    board.clear();
    board.resize(n*n);
    for (int j = 0; j < n; ++j) {
      string s;
      in >> s;
      for (int j2 = 0; j2 < n; ++j2) {
        board[j*n+j2] = s[j2];
      }
    }
    int r = cal(board, n, k);
    switch (r) {
      case 0:
        cout << "Case #" << i+1 << ": Neither\n";
        break;
      case 1:
        cout << "Case #" << i+1 << ": Both\n";
        break;
      case 2:
        cout << "Case #" << i+1 << ": Red\n";
        break;
      case 3:
        cout << "Case #" << i+1 << ": Blue\n";
        break;
    }
  }
  return 0;
}

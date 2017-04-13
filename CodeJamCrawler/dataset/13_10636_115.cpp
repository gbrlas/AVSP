#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int x_wins, o_wins, draw;
char b[8][8];

int win(int x, int o, int t) {
  if(x == 4) return 1;
  else if(o == 4) return 2;
  else if(x == 3 && t) return 1;
  else if(o == 3 && t) return 2;
  return 0;
}

int check() {
  int x, o, t;
  for(int i = 0; i < 4; ++i) {
      // Vertical
    x = o = t = 0;
    for(int j = 0; j < 4; ++j) {
      if(b[i][j] == 'X') ++x;
      if(b[i][j] == 'O') ++o;
      if(b[i][j] == 'T') ++t;
    }
    if(win(x, o, t) == 1) x_wins = 1;
    else if(win(x, o, t) == 2) o_wins = 1;
    
      // Horizontal
    x = o = t = 0;
    for(int j = 0; j < 4; ++j) {
      if(b[j][i] == 'X') ++x;
      if(b[j][i] == 'O') ++o;
      if(b[j][i] == 'T') ++t;
    }
    if(win(x, o, t) == 1) x_wins = 1;
    else if(win(x, o, t) == 2) o_wins = 1;
  }
    // Diagonal
  x = o = t = 0;
  for(int i = 0, j = 0; i < 4; ++i, ++j) {
    if(b[i][j] == 'X') ++x;
    if(b[i][j] == 'O') ++o;
    if(b[i][j] == 'T') ++t;
  }
  if(win(x, o, t) == 1) x_wins = 1;
  else if(win(x, o, t) == 2) o_wins = 1;
  
  x = o = t = 0;
  for(int i = 0, j = 3; i < 4; ++i, --j) {
    if(b[i][j] == 'X') ++x;
    if(b[i][j] == 'O') ++o;
    if(b[i][j] == 'T') ++t;
  }
  if(win(x, o, t) == 1) x_wins = 1;
  else if(win(x, o, t) == 2) o_wins = 1;
  
  t = 0;
  int to = 0, tx = 0;
  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < 4; ++j) {
      if(b[i][j] == 'X') ++tx;
      if(b[i][j] == 'O') ++to;
      if(b[i][j] == 'T') ++t;
    }
  }
  draw = (tx + to + t) == 16;
}

int main() {
  int tt;
  string res;
  
  cin>>tt;
  for(int t = 1; t <= tt; ++t) {
    for(int i = 0; i < 4; ++i) {
      cin>>b[i];
    }
    x_wins = o_wins = draw = 0;
    check();
    if(x_wins) res = "X won";
    else if(o_wins) res = "O won";
    else if(draw) res = "Draw";
    else res = "Game has not completed";
    
    cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}

#include <iostream>
#include <string>
using namespace std;

string s[5];

bool checkX() {
  for (int i = 0; i < 4; i++) {
    bool flag = true;
    for (int j = 0; j < 4; j++) 
      if ((s[i][j] == '.') || (s[i][j] == 'O')) flag = false;
    if (flag) return true;

    flag = true;
    for (int j = 0; j < 4; j++)
      if ((s[j][i] == '.') || (s[j][i] == 'O')) flag = false;
    if (flag) return true;
  }

  bool flag = true;
  for (int i = 0; i < 4; i++) 
    if ((s[i][i] == '.') || (s[i][i] == 'O')) flag = false;
  if (flag) return true;

  flag = true;
  for (int i = 0; i < 4; i++)
    if ((s[3 - i][i] == '.') || (s[3 - i][i] == 'O')) flag = false;
  if (flag) return true;

  return false;
}

bool checkO() {
  for (int i = 0; i < 4; i++) {
    bool flag = true;
    for (int j = 0; j < 4; j++) 
      if ((s[i][j] == '.') || (s[i][j] == 'X')) flag = false;
    if (flag) return true;

    flag = true;
    for (int j = 0; j < 4; j++)
      if ((s[j][i] == '.') || (s[j][i] == 'X')) flag = false;
    if (flag) return true;
  }

  bool flag = true;
  for (int i = 0; i < 4; i++) 
    if ((s[i][i] == '.') || (s[i][i] == 'X')) flag = false;
  if (flag) return true;

  flag = true;
  for (int i = 0; i < 4; i++)
    if ((s[3 - i][i] == '.') || (s[3 - i][i] == 'X')) flag = false;
  if (flag) return true;

  return false;
}

bool checkEnd() {
  for (int i = 0; i < 4; i++) 
    for (int j = 0; j < 4; j++)
      if (s[i][j] == '.') return false;
  return true;
}

void solve(int t) {
  cout << "Case #" << t << ": ";
  if (checkX()) {
    cout << "X won" << endl;
    return;
  }
  if (checkO()) {
    cout << "O won" << endl;
    return;
  }
  if (checkEnd()) {
    cout << "Draw" << endl;
    return;
  }
  cout << "Game has not completed" << endl;
}

int main() {
  int test;
  cin >> test;
  getline(cin, s[4]);
  for (int t = 1; t <= test; t++) {
    for (int i = 0; i < 4; i++) getline(cin, s[i]);
    getline(cin, s[4]);
    solve(t);
  }
  return 0;
}

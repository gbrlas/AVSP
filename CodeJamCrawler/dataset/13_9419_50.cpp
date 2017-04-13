#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
//#include <cstdlib>

using namespace std;

string sx[4] = {"XXXX", "XXXX", "XXXX", "XXXX"};
string so[4] = {"OOOO", "OOOO", "OOOO", "OOOO"};

int XWon(string s[4]) {
  int i = -1;
  while (++i < 4) {
    if (s[i].find("T") != -1) {
      s[i].replace(s[i].find("T"),1,"X");
      break;
    }
  }
  i = -1;
  while (++i < 4)
    if (!sx[i].compare(s[i])) return 1;

  i = -1;
  while (++i < 4) {
    if ((s[0][i] == 'X') &&
	(s[1][i] == 'X') &&
	(s[2][i] == 'X') &&
	(s[3][i] == 'X'))
      return 1;
  }

  if ((s[0][0] == 'X') &&
      (s[1][1] == 'X') &&
      (s[2][2] == 'X') &&
      (s[3][3] == 'X')) {
    return 1;
  }

  if ((s[0][3] == 'X') &&
      (s[1][2] == 'X') &&
      (s[2][1] == 'X') &&
      (s[3][0] == 'X')) {
    return 1;
  }

  return 0;
}

int OWon(string s[4]) {
  int i = -1;
  while (++i < 4) {
    if (s[i].find("T") != -1) {
      s[i].replace(s[i].find("T"),1,"O");
      break;
    }
  }
  i = -1;
  while (++i < 4)
    if (!so[i].compare(s[i])) return 1;

  i = -1;
  while (++i < 4) {
    if ((s[0][i] == 'O') &&
	(s[1][i] == 'O') &&
	(s[2][i] == 'O') &&
	(s[3][i] == 'O'))
      return 1;
  }

  if ((s[0][0] == 'O') &&
      (s[1][1] == 'O') &&
      (s[2][2] == 'O') &&
      (s[3][3] == 'O')) {
    return 1;
  }

  if ((s[0][3] == 'O') &&
      (s[1][2] == 'O') &&
      (s[2][1] == 'O') &&
      (s[3][0] == 'O')) {
    return 1;
  }

  return 0;
}

int main()
{
  int T, i = 0;

  string s[4];
  cin >> T;
  while (i++ < T) {
    int j = -1;
    while (++j < 4) {
      cin >> s[j];
    }
    
    j = -1;
    int dots = 0;
    while (++j < 4) {
      if (s[j].find(".") != -1) dots++;
    }

    int decision = -1;
    string s_t[4] = s;
    decision = XWon(s_t);
    if (!decision) {
      decision = 0;
      decision = OWon(s);
      if (decision == 1) {
	cout << "Case #" << i << ": O won" << endl;
      }
      else {
	if (!dots) cout << "Case #" << i << ": Draw" << endl;
	else cout << "Case #" << i << ": Game has not completed" << endl;
      }
    }
    else cout << "Case #" << i << ": X won" << endl;
    string ss;
    getline(cin,ss);
  }
  return 0;
}

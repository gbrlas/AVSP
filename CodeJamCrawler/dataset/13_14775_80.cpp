#include <iostream>
#include <vector>
#include <string>

#define OWNER_X 0
#define OWNER_O 1
#define NO_CONT -1

#define WIN_X 0
#define WIN_O 1
#define DRAW 2
#define NOT_YET 3

using namespace std;

int checkLine(const char* line) {
  int owner = -2;
  for(int i = 0; i < 4; i++) {
    if(line[i] == 'X') {
      if(owner == WIN_O) {
        return NO_CONT;
      }
      else {
        owner = WIN_X;
        continue;
      }
    }
    else if(line[i] == 'O') {
      if(owner == WIN_X) {
        return NO_CONT;
      }
      else {
        owner = WIN_O;
        continue;
      }
    }
    else if(line[i] == 'T')
      continue;
    else { //line[i] == '.'
      return NO_CONT;
    }
  }

  return owner;
}

int solve(const vector<string>& input) {
  bool haveDot = false;
  int check;
  char checkRow[4][4];
  char checkAng[2][4];
  /* 0:Top-Left to Under-Right */
  /* 1:Top-Right to Under-Left*/

  for(int i = 0; i < input.size(); i++) {
    for(int j = 0; j < input[i].size(); j++) {
      if(input[i][j] == '.') haveDot = true;

      checkRow[j][i] = input[i][j];
      if(i == j)
        checkAng[0][i] = input[i][j];
      else if(i + j == 3)
        checkAng[1][i] = input[i][j];
    }
    check = checkLine(((input[i].c_str())));
    if(check != NO_CONT) return check;
  }

  for(int i = 0; i < 4; i++) {
    check = checkLine((const char*)&(checkRow[i]));
    if(check != NO_CONT) return check;
  }
  for(int i = 0; i < 2; i++) {
    check = checkLine((const char*)&(checkAng[i]));
    if(check != NO_CONT) return check;
  }

  if(haveDot == true) return NOT_YET; 

  return DRAW;
}

int main() {
    int T;
    string line;

    string ans_print[4];
    ans_print[0] = "X won";
    ans_print[1] = "O won";
    ans_print[2] = "Draw";
    ans_print[3] = "Game has not completed";

    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; i++) {
        vector<string> input;
        while (1) {
            getline(cin, line);
            if (line.empty()) break;
            input.push_back(line);
        }
        int answer = solve(input);
        cout << "Case #" << i << ": " << ans_print[answer]<< endl;
    }
}

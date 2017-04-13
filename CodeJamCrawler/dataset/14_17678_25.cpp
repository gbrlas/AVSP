#include <iostream>
#include <fstream>

using namespace std;

void analyze(int caseNum, int arrangement1[4], int arrangement2[4]);

int main() {
  ifstream input("/home/conrad/Downloads/input.in");
  int numberOfTestCases;
  input >> numberOfTestCases;

  int arrangement1[4];
  int arrangement2[4];
  int answer1, answer2;

  int line, card, caseNum;
  for (caseNum = 0; caseNum < numberOfTestCases; caseNum++) {
    input >> answer1;
    for (line = -1; line < 4; line++)
      if (line != answer1 - 1)
        input.ignore(11,'\n');
      else {
        for (card = 0; card < 4; card++)
          input >> arrangement1[card];
        input.ignore(1,'n');
      }

    input >> answer2;
    for (line = -1; line < 4; line++)
      if (line != answer2 - 1)
        input.ignore(13,'\n');
      else {
        for (card = 0; card < 4; card++)
          input >> arrangement2[card];
        input.ignore(1,'\n');
      }

    analyze(caseNum + 1,arrangement1,arrangement2);
  }

  return 0;
}

void analyze(int caseNum, int arrangement1[4], int arrangement2[4]) {
  int i, j;
  int matching = 0;
  int answer;
  bool cheated = true;

  cout << "Case #" << caseNum << ": ";

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (arrangement1[i] == arrangement2[j]) {
        cheated = false;
        matching++;
        if (matching >= 2) {
          cout << "Bad magician!" << endl;
          return;
        }
        else
          answer = arrangement1[i];
      }
    }
  }

  if (cheated)
    cout << "Volunteer cheated!" << endl;
  else
    cout << answer << endl;

  return;
}

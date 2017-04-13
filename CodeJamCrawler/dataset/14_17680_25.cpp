#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
  cout << fixed;
  cout << setprecision(7);
  ifstream input("input.in");

  int testCases, testCase;
  input >> testCases;

  double C, F, X;

  int farms;
  double speed, cost, remainder, best;
  for (testCase = 0; testCase < testCases; testCase++) {
    input >> C;
    input >> F;
    input >> X;

    cout << "Case #" << testCase + 1 << ": ";
    cost = 0;
    best = remainder = X / 2;

    farms = 1;
    speed = 2;
    while (true) {
      cost += C / speed;
      speed = 2 + (farms * F);
      remainder = X / speed;

      if (remainder + cost > best) {
        cout << best << endl;
        break;
      }
      else {
        best = remainder + cost;
        farms++;
      }
    }
  }

  input.close();
  return 0;
}

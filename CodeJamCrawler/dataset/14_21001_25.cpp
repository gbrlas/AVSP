#include <iostream>
#include <vector>

using namespace std;

void input_guess(vector<int>& row) {
  int row_index;
  cin >> row_index;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int x;
      cin >> x;
      if (i == row_index - 1) {
        row[x - 1] = 1;
      }
    }
  }
}

void output_answer(
    int tc,
    const vector<int>& row_one,
    const vector<int>& row_two) {

  int count = 0, which = -1;
  for (int i = 0; i < 16; ++i) {
    if (row_one[i] && row_two[i]) {
      which = i;
      ++count;
    }
  }

  cout << "Case #" << tc + 1 << ": ";
  if (count == 0) {
    cout << "Volunteer cheated!" << endl;
  } else if (count == 1) {
    cout << which + 1 << endl;
  } else {
    cout << "Bad magician!" << endl;
  }
}

int main() {
  int T;

  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    vector<int> row_one(16);
    input_guess(row_one);

    vector<int> row_two(16);
    input_guess(row_two);

    output_answer(tc, row_one, row_two);
  }

  return 0;
}

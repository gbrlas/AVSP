#include <iostream>
#include <vector>

using namespace std;

bool checkRow(int col, int row, int N, int M, int lawnLen,
    const vector<vector<int> >& input) {

  for(int i = 0; i < N; i++) {
    if(input[i][row] > lawnLen) {
      return false;
    }
  }
  return true;
}

bool checkCol(int col, int row, int N, int M, int lawnLen,
    const vector<vector<int> >& input) {

  for(int i = 0; i < M; i++) {
    if(input[col][i] > lawnLen) {
      return false;
    }
  }
  return true;
}

bool checkPos(int col, int row, int N, int M, int lawnLen,
    const vector<vector<int> >& input) {
  if(checkRow(col, row, N, M, lawnLen, input) == true ||
      checkCol(col, row, N, M, lawnLen, input) == true)
    return true;
  else
    return false;
}

int solve(int N, int M, const vector<vector<int> >& input) {
  int max = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(max < input[i][j])
        max = input[i][j];
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      //cout << input[i][j];
      if(max == input[i][j])
        continue;

      if (checkPos(i, j, N, M, input[i][j], input) == false)
        return 1;

    }
  }
  return 0;
}

int main() {
    int T, N, M;
    int tmp;

    string ans_print[2];
    ans_print[0] = "YES";
    ans_print[1] = "NO";

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N >> M;
        vector<vector<int> > input(N, vector<int>(M));
        for(int j = 0; j < N; j++) {
          for(int k = 0; k < M; k++) {
            cin >> input[j][k];
          }
        }
        int answer = solve(N, M, input);
        cout << "Case #" << i << ": " << ans_print[answer]<< endl;
    }
}

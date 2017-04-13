#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> read_answer(int row)
{
    int number;
    vector<vector<int>> matrix(4);
    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) {
            cin >> number;
            matrix[j].push_back(number);
        }
    }
    return matrix[row];
}

int main()
{
    int T, row1, row2;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> row1;
        vector<int> answer_row1 = read_answer(row1 - 1);
        cin >> row2;
        vector<int> answer_row2 = read_answer(row2 - 1);
        sort(answer_row1.begin(), answer_row1.end());
        sort(answer_row2.begin(), answer_row2.end());
        vector<int> result;
        set_intersection(answer_row1.begin(), answer_row1.end(), answer_row2.begin(), answer_row2.end(), back_inserter(result));
        cout << "Case #" << i + 1 << ": ";
        if (result.size() == 1) {
            cout << result[0];
        } else if (result.size() == 0) {
            cout << "Volunteer cheated!";
        } else {
            cout << "Bad magician!";
        }
        cout << "\n";
    }
}


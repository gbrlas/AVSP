#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static bool won(const string& line, char s) {
    for (size_t i = 0; i < line.size(); ++i)
        if (line[i] != s && line[i] != 'T')
            return false;
    return true;
}

static bool won(const vector<string>& board, char s) {
    vector<string> lines(board.begin(), board.end());
    for (int i = 0; i < 4; ++i) {
        string ver;
        for (int j = 0; j < 4; ++j)
            ver.push_back(board[j][i]);
        lines.push_back(ver);
    }
    string d1, d2;
    for (int i = 0; i < 4; ++i) {
        d1.push_back(board[i][i]);
        d2.push_back(board[i][3-i]);
    }
    lines.push_back(d1);
    lines.push_back(d2);
    for (size_t i = 0; i < lines.size(); ++i)
        if (won(lines[i], s))
            return true;
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        vector<string> board(4);
        bool hasEmpty = false;
        for (int i = 0; i < 4; ++i) {
            cin >> board[i];
            if (std::find(board[i].begin(), board[i].end(), '.') != board[i].end())
                hasEmpty = true;
        }
        bool xWon = won(board, 'X');
        bool oWon = won(board, 'O');
        string result;
        if (xWon)
            result = "X won";
        else if (oWon)
            result = "O won";
        else if (hasEmpty)
            result = "Game has not completed";
        else
            result = "Draw";

        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}


#include <iostream>

using namespace std;

#define match(a, b) (((a) != '.' && (b) != '.') && ((a) == (b) || (a) == 'T' || (b) == 'T'))

char win(char a, char b, char c, char d) {
    if (match(a, b) && match(a, c) && match(a, d)
        && match(b, c) && match(b, d) && match(c, d)) {
        return a == 'T' ? b : a;
    } else {
        return 0;
    }
}

int main()
{
    int N;
    char board[4][4];
    char won;
    cin >> N;
    bool unfin = false;
    for (int i = 0; i < N; i++) {
        cout << "Case #" << (i + 1) << ": ";
        for (int j = 0; j < 16; j++) {
            char c;
            do {
                cin >> c;
            } while (c == '\n');
            board[j / 4][j % 4] = c;
        }
        for (int j = 0; j < 4; j++) {
            won = win(
                           board[j][0],
                           board[j][1],
                           board[j][2],
                           board[j][3]);
            if (won) {
                cout << won << " won" << endl;
                goto l_next;
            }
            won = win(
                           board[0][j],
                           board[1][j],
                           board[2][j],
                           board[3][j]);
            if (won) {
                cout << won << " won" << endl;
                goto l_next;
            }
        }
        won = win(
                       board[0][0],
                       board[1][1],
                       board[2][2],
                       board[3][3]);
        if (won) {
            cout << won << " won" << endl;
            goto l_next;
        }
        won = win(
                       board[0][3],
                       board[1][2],
                       board[2][1],
                       board[3][0]);
        if (won) {
            cout << won << " won" << endl;
            goto l_next;
        }
        unfin = false;
        for (int j = 0; j < 16; j++) {
            if (board[j / 4][j % 4] == '.') {
                unfin = true;
                break;
            }
        }
        if (unfin) {
            cout << "Game has not completed" << endl;
        } else {
            cout << "Draw" <<endl;
        }
l_next:
    continue;
    }
    return 0;
}

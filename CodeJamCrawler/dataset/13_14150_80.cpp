#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define SIZE 4

/**
 * return: -1 X wins, 0 no one wins and +1 0 wins
 */
char rowWin(string &s) {

    char mander;
    for (int i = 0; i < SIZE; ++i) {
        if (s[i] == '.') return 0;
        if (s[i] != 'T') {
            mander = s[i];
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        if (s[i] != 'T' and s[i] != mander) {
            return 0;
        }
    }

    return mander;
}

char colWin(string board[SIZE], int col) {
    char mander;
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][col] == '.') return 0;
        if (board[i][col] != 'T') {
            mander = board[i][col];
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][col] != 'T' and board[i][col] != mander) {
            return 0;
        }
    }

    return mander;

}

char diagonalWin(string board[SIZE]) {
    char cNormal;
    char cInvers;
    bool normal = true;
    bool invers = true;
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][i] == '.') {
            normal = false;
        }
        if (board[i][3-i] == '.') {
            invers = false;
        }
        if (board[i][i] != 'T') {
            cNormal = board[i][i];
        }
        if (board[i][3-i] != 'T') {
            cInvers = board[i][3-i];
        }
    }

    char wrong = false;
    if (normal) {
        for (int i = 0; i < SIZE && !wrong; ++i) {
            wrong =  board[i][i] != 'T' and board[i][i] != cNormal;
        }
        
        if (!wrong) {
            return cNormal;
        }
    }
    
     if (invers) {
        wrong = false;
        for (int i = 0; i < SIZE && !wrong; ++i) {
            wrong = board[i][3-i] != 'T' and board[i][3-i] != cInvers;
        }
        if (!wrong) {
            return cInvers;
        }
    }
    return 0;
}

string getRes(char check) {
    if (check == 'X') {
        return  "X won";
    } else {
        return "O won";
    }    
}

string gameResult(string board[SIZE])
{
    char check;

    for (int i = 0; i < SIZE; ++i) {
        check = rowWin(board[i]);

        if (check != 0) {
            cerr << "i = " << i << "rowWin" << endl;
            return getRes(check);
        }

        check = colWin(board, i);
        if (check != 0) {
            cerr << "i = " << i << "colWin" << endl;
            return getRes(check);
        }
    }

    cerr << "diagonal win" << endl;
    //diagonal
    check = diagonalWin(board);
    if (check != 0) return getRes(check);

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == '.') {
                return "Game has not completed";
            }
        }
    }    
 
    return "Draw";
}


int main()
{
    int num;

    string board[SIZE];
    cin >> num;
    for (int numCase = 1; numCase <= num; ++numCase) {
        for (int i = 0; i < SIZE; ++i) {
            cin >> board[i];
        }
        
        cout << "Case #" << numCase << ": " << gameResult(board)<< endl;
    }
}

#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0;i<n;i++)

char lookup[256];
unsigned int repr(char c) {
    return ((unsigned char)(c));
}
char classify(char tab[]) {
    lookup[repr('X')]=0;
    lookup[repr('T')]=0;
    lookup[repr('.')]=0;
    lookup[repr('O')]=0;
    REP(i, 4) {
        lookup[repr(tab[i])]++;
    }
    if (lookup[repr('X')] + lookup[repr('T')] == 4) {
        return 'X';
    }
    if (lookup[repr('O')] + lookup[repr('T')] == 4) {
        return 'O';
    }
    if (lookup[repr('.')] > 0) {
        return '.';
    }
    return 'N';
}

void readpath(int row, int col, int dr, int dc, char tab[], string t[]) {
    REP(i, 4) {
        tab[i] = t[row][col];
        row += dr;
        col += dc;
    }
}

bool win(int cas, char c) {
    if (c == 'O' or c == 'X') {
        cout << "Case #" << cas << ": " << c << " won" << endl;
        return true;
    }
    return false;
}

void draw(int cas) {
    cout << "Case #" << cas << ": Draw" << endl;
}

void incomplete(int cas) {
    cout << "Case #" << cas << ": Game has not completed" << endl;
}

void solve(int cas) {
    string t[4];
    REP(i, 4) cin >> t[i];
    char tab[4];
    int empty = 0;
    REP(i, 4) REP(j, 4) if (t[i][j] == '.') empty++;
    REP(i, 4) {
        readpath(i, 0, 0, 1, tab, t);
        if (win(cas, classify(tab))) {
            return;
        }
    }
    REP(i, 4) {
        readpath(0, i, 1, 0, tab, t);
        if (win(cas, classify(tab))) {
            return;
        }
    }
    {
        readpath(0, 0, 1, 1, tab, t);
        if (win(cas, classify(tab))) {
            return;
        }
    }
    {
        readpath(3, 0, -1, 1, tab, t);
        if (win(cas, classify(tab))) {
            return;
        }
    }
    if (empty > 0) incomplete(cas);
    else draw(cas);
}

int main() {
    int T;
    cin >> T;
    REP(i, T) solve(i+1);
    return 0;
}

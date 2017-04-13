#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (fin.bad()) {
        cout << "Could not open input file" << endl;
        return -1;
    }
    int t;
    fin >> t;
    for (int ncase = 0; ncase < t; ncase++) {
        string b[4];
        for (int r = 0; r < 4; r++) {
            fin >> b[r];
            cout << b[r] << endl;
        }
        cout << endl;

        bool ma = false;
        bool ghwo = false;
        bool ghwx = false;
        for (int r = 0; r < 4; r++) {
            bool hwo = true;
            bool hwx = true;
            for (int c = 0; c < 4; c++) {
                if (b[r][c] == 'X') {
                    hwo = false;
                }
                if (b[r][c] == 'O') {
                    hwx = false;
                }
                if (b[r][c] == '.') {
                    hwo = false;
                    hwx = false;
                    ma = true;
                }
            }
            if (hwo) {
                ghwo = true;
                cout << "O won row " << r << endl;
            }
            if (hwx) {
                ghwx = true;
                cout << "X won row " << r << endl;
            }
        }
        for (int c = 0; c < 4; c++) {
            bool hwo = true;
            bool hwx = true;
            for (int r = 0; r < 4; r++) {
                if (b[r][c] == 'X') {
                    hwo = false;
                }
                if (b[r][c] == 'O') {
                    hwx = false;
                }
                if (b[r][c] == '.') {
                    hwo = false;
                    hwx = false;
                    ma = true;
                }
            }
            if (hwo) {
                ghwo = true;
                cout << "O won col " << c << endl;
            }
            if (hwx) {
                ghwx = true;
                cout << "X won col " << c << endl;
            }
        }

        bool hwo = true;
        bool hwx = true;
        for (int e = 0; e < 4; e++) {
            if (b[e][e] == 'X') {
                hwo = false;
            }
            if (b[e][e] == 'O') {
                hwx = false;
            }
            if (b[e][e] == '.') {
                hwo = false;
                hwx = false;
                ma = true;
            }
        }
        if (hwo) {
            ghwo = true;
            cout << "O won diag1 " << endl;
        }
        if (hwx) {
            ghwx = true;
            cout << "X won diag1 " << endl;
        }

        hwo = true;
        hwx = true;
        for (int e = 0; e < 4; e++) {
            if (b[e][3 - e] == 'X') {
                hwo = false;
            }
            if (b[e][3 - e] == 'O') {
                hwx = false;
            }
            if (b[e][3 - e] == '.') {
                hwo = false;
                hwx = false;
                ma = true;
            }
        }
        if (hwo) {
            ghwo = true;
            cout << "O won diag2 " << endl;
        }
        if (hwx) {
            ghwx = true;
            cout << "X won diag2 " << endl;
        }
        string gmsg;
        if (ghwo) gmsg = "O won";
        if (ghwx) gmsg = "X won";
        if ((!ghwo) && (!ghwx) && (ma)) gmsg = "Game has not completed";
        if ((!ghwo) && (!ghwx) && (!ma)) gmsg = "Draw";
        fout << "Case #" << ncase + 1 << ": " << gmsg << endl;
    }
    return 0;
}

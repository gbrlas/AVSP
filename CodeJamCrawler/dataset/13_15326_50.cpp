#include <fstream>
#include <iostream>
#include <vector>

bool hasEmpty = false;
bool hasWinner = false;

void isEmptyChar(char c) {
    if (!hasEmpty && c == '.')
        hasEmpty = true;
}

int main() {
    int numCases;
    char c;
    char in[16];

    std::vector<int> xH(4,0);
    std::vector<int> oH(4,0);
    std::vector<int> tH(4,0);
    std::vector<int> xV(4,0), oV(4,0), tV(4,0);
    std::vector<int> xD(2,0), oD(2,0), tD(2,0);

    std::cin >> numCases;

    for (int i = 0; i < numCases; ++i) {

        for (int j = 0; j < 16; ++j) {
            std::cin >> c;
            if (c == 'X') {
                xH[j/4]++;
                xV[j%4]++;
                if (j == 0 || j == 5 || j == 10 || j == 15)
                    xD[0]++;
                if (j == 3 || j == 6 || j == 9 || j == 12)
                    xD[1]++;
            } else if (c == 'O') {
                oH[j/4]++;
                oV[j%4]++;
                if (j == 0 || j == 5 || j == 10 || j == 15)
                    oD[0]++;
                if (j == 3 || j == 6 || j == 9 || j == 12)
                    oD[1]++;
            } else if (c == 'T') {
                tH[j/4]++;
                tV[j%4]++;
                if (j == 0 || j == 5 || j == 10 || j == 15)
                    tD[0]++;
                if (j == 3 || j == 6 || j == 9 || j == 12)
                    tD[1]++;
            } else {
                isEmptyChar(c);
            }
        }

        if (!hasWinner) {
        for (int j = 0; j < 4; ++j) {
            if (xH[j] == 4 || (xH[j] == 3 && tH[j] == 1)
                    || xV[j] == 4 || (xV[j] == 3 && tV[j] == 1)) {
                std::cout << "Case #" << i+1 << ": X won\n";
                hasWinner = true;
                break;
            } else if (oH[j] == 4 || (oH[j] == 3 && tH[j] == 1)
                    || oV[j] == 4 || (oV[j] == 3 && tV[j] == 1)) {
                std::cout << "Case #" << i+1 << ": O won\n";
                hasWinner = true;
                break;
            }
        }
        }

        if (!hasWinner) {
        for (int j = 0; j < 2; ++j) {
            if (xD[j] == 4 || (xD[j] == 3 && tD[j] == 1)) {
                std::cout << "Case #" << i+1 << ": X won\n";
                hasWinner = true;
                break;
            } else if (oD[j] == 4 || (oD[j] == 3 && tD[j] == 1)) {
                std::cout << "Case #" << i+1 << ": O won\n";
                hasWinner = true;
                break;
            }
        }
        }

        if (!hasWinner && !hasEmpty) {
            std::cout << "Case #" << i+1 << ": Draw\n";
        } else if (!hasWinner && hasEmpty) {
            std::cout << "Case #" << i+1 << ": Game has not completed\n";
        }

        for (int j = 0; j < 4; ++j) {
            xH[j] = 0; oH[j] = 0; tH[j] = 0;
            xV[j] = 0; oV[j] = 0; tV[j] = 0;
            xD[j%2] = 0; oD[j%2] = 0; tD[j%2] = 0;
        }

        hasWinner = false;
        hasEmpty = false;
    }

    return 0;
}